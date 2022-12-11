#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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

void display_matrix(int l, float m[][20])
{
	int i = 0, j = 0;
	printf("\n       ");
	for (j = 0; j < l; j++)
		printf("  a[][%d]", j);

	for (i = 0; i < l; i++)
	{
		printf("\na[%d][] ", i);
		for (j = 0; j < l; j++)
		{    
			printf(" %7.2f", m[i][j]);
		}
	}
}

void fold_matrix(int l, float in_m[][20])
{
	int i, j;

	if (l % 2 == 0) {

		for (i = 0; i < l; i++)
		{

			for (j = 0; j < l; j++)
			{
				in_m[i][j] += in_m[l - i - 1][j];
				if (i > l / 2 - 1) in_m[i][j] = 0;
			}
		}
	}

	else 
	{
		for (i = 0; i < l; i++)
		{

			for (j = 0; j < l; j++)
			{
				in_m[i][j] += in_m[l - i - 1][j];
				if (i > l / 2) in_m[i][j] = 0;
			}
		}
	}
}

void main()
{
	int m;
	float mat[20][20], out_mat[4][4];

	read_matrix(&m, mat);
	display_matrix(m, mat);
	fold_matrix(m, mat);
	display_matrix(m , mat);
}