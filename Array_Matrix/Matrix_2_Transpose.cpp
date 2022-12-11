#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void read_matrix(int* l, float m[][20])
{
	int i, j;

	printf("\nNumarul de linii si coloane = ");
	(void)scanf("%d", l);

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

void transpose_matrix(int l, float in_m[][20], float out_m[][20])
{
	int i, j;
	float temp;
	for (i = 0; i < l; i++)
		for (j = 0; j < l; j++)
			out_m[j][i] = in_m[i][j];
}

void swap_matrix(int l, float in_m[][20], float out_m[][20])
{
	int i, j;
	for (i = 0; i < l; i++)
		for (j = 0; j < l; j++)
			out_m[i][j] = in_m[i][j];
}

void main()
{
	int l;
	float in_mat[20][20] = { 0 }, out_mat[20][20] = { 0 };

	read_matrix(&l, in_mat);
	transpose_matrix(l, in_mat, out_mat);
	swap_matrix(l, out_mat, in_mat);
	display_matrix(l, out_mat);
}