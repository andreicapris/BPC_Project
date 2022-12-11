#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void read_matrix(int* l, int* h, float m[][20])
{
	int i, j;

	printf("\nNumarul de linii = ");
	(void)scanf("%d", h);
	printf("\nNumarul de coloane = ");
	(void)scanf("%d", l);

	for (i = 0; i < *h; i++)
	{
		printf("\n");
		for (j = 0; j < *l; j++)
		{

			printf("m[%d][%d] = ", i, j);
			(void)scanf("%f", &m[i][j]);
		}
	}
}

void display_matrix(int l, int h, float m[][20])
{
	int i = 0, j = 0;
	char c = '*';
	float red_value = -11.11;
	printf("\n       ");
	for (j = 0; j < l; j++)
		printf("  a[][%3d]", j);

	for (i = 0; i < h; i++)
	{
		printf("\na[%3d][]", i);
		for (j = 0; j < l; j++)
		{
			if (m[i][j] != red_value) printf(" %8.2f ", m[i][j]);
			else printf("    %c%c    ", c, c);
		}
	}
}

void gen_matrix(int* l, int *h, float m[][20])
{
	int i, j;
	do {
		printf("\nNumarul de linii = ");
		(void)scanf("%d", h);
		printf("\nNumarul de coloane = ");
		(void)scanf("%d", l);
	} while ((*l < 0 || *l>20) || (*h < 0 || *h>20));
	for (i = 0; i < *h; i++)
		for (j = 0; j < *l; j++)
		{
			m[i][j] = rand();
		}
}

void min_max_matrix(int l, int h, float i_m[][20], float min_m[][20], float max_m[][20])
{
	int i, j, min, max;
	float red_value = -11.11;
	min = max = i_m[0][0];
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
		{
			if (i_m[i][j] >= max) max = i_m[i][j];
			if (i_m[i][j] <= min) min = i_m[i][j];
		}

	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
		{
			if (max == i_m[i][j]) max_m[i][j] = max;
			else max_m[i][j] = red_value;

			if (min == i_m[i][j]) min_m[i][j] = min;
			else min_m[i][j] = red_value;
		}
}



void main()
{
	int l, h;
	float mat[20][20] = { 0 };
	float min[20][20] = { 0 }, max[20][20] = { 0 };
	//read_matrix(&l, &h, mat);
	gen_matrix(&l, &h, mat);
	display_matrix(l, h, mat);
	min_max_matrix(l, h, mat, min, max);
	printf("\n Locatiile minimului: \n");
	display_matrix(l, h, min);
	printf("\n Locatiile maximului: \n");
	display_matrix(l, h, max);
}
