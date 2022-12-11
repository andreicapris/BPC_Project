#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void read_matrix(int* l, float m[][20])
{
	int i, j;
	do {
		printf("\nNumarul de linii si coloane = ");
		(void)scanf("%d", l);
	} while (*l < 0 || *l>20);
	for (i = 0; i < *l; i++)
	{
		printf("\n");
		for (j = 0; j < *l; j++)
		{

			printf("m[%d][%d] = ", i, j);
			(void)scanf("%f", &m[i][j]);
		}
	}
}

void gen_matrix(int* l, float m[][20])
{
	int i, j;
	float k = 1;
	do {
		printf("\nNumarul de linii si coloane = ");
		(void)scanf("%d", l);
	} while (*l < 0 || *l>20);
	for (i = 0; i < *l; i++)
		for (j = 0; j < *l; j++)
		{
			m[i][j] = k;
			k++;
		}
}

void display_matrix(int l, float m[][20])
{
	int i = 0, j = 0;
	float red_value = -11.11;
	char c = '*';
	printf("\n       ");
	for (j = 0; j < l; j++)
		printf(" a[][%2d]", j);

	for (i = 0; i < l; i++)
	{
		printf("\na[%2d][]", i);
		for (j = 0; j < l; j++)
		{
			if (m[i][j] == red_value) printf("    %c   ", c);
			else {
				printf(" %7.2f", m[i][j]);
			}
		}
	}
}

void line_tend(int x, float mat[][20], int l)
{
	int i , flag_s = 0, flag_is = 0;
	for (i = 0; i < l - 1; i++)
	{
		if (mat[x][i] < mat[x][i + 1]) flag_s = 1;
		else flag_s = 0;

		if (mat[x][i] > mat[x][i + 1]) flag_is = 1;
		else flag_is = 0;
	}

	if (flag_s == 1 || flag_is == 1)
	{
		if (flag_s == 1) printf("Linia %d este crescatoare.", x);
		if (flag_is == 1) printf("Linia %d este descrescatoare.", x);
	}
	else printf("Nu ne putem da seama.");
}


void main()
{
	int m, x, ex = 1;
	float in_mat[20][20];

	read_matrix(&m, in_mat);
	//gen_matrix(&m, in_mat);
	display_matrix(m, in_mat);
	do {

		printf("\nIntroduceti linia pe care o vreti analizata: ");
		(void)scanf("%d", &x);
		line_tend(x, in_mat, m);
		printf("\nDoriti sa continuati ? (1/0)");
		(void)scanf("%d", &ex);
	} while (ex != 0);

}