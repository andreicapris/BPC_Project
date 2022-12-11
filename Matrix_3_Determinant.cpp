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
void two_by_two(int l, float m[][20])
{
	int i, j;
	float det;
	for (i = 0; i < l - 1; i++)
	{
		
		for (j = 0; j < l - 1; j++)
		{
			printf("\n-------------\n");		
			printf(" %7.2f %7.2f \n", m[i][j], m[i][j + 1]);
			printf(" %7.2f %7.2f ", m[i + 1][j], m[i + 1][j + 1]);
			det = m[i][j] * m[i + 1][j + 1] - m[i][j+1] * m[i+1][j];
			printf("\nDeterminantul este: %7.2f", det);
			printf("\n-------------\n");
			det = 0;
		}
	}
}

void main()
{
	int m;
	float mat[20][20];

	read_matrix(&m, mat);
	display_matrix(m, mat);
	printf("\n");
	two_by_two(m, mat);
}
