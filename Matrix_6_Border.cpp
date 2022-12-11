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

void border_matrix(int l, int b, float m[][20])
{
	int i, j, k;
	float red_value = -11.11;
	for (i = 0; i < l; i++)
		for (j = 0; j < l; j++)
		{
			if (i < b)
			{
				m[i][j] = red_value;
				m[l - i - 1][j] = red_value;
			}
			else
				for (k = 0; k < b; k++)
				{
					if (j < b)
					{
						m[i][j] = red_value;
						m[i][l - j - 1] = red_value;
					}
				}
		}
}

void main()
{
	int m, bd;
	float mat[20][20];

	//read_matrix(&m, mat);
	gen_matrix(&m, mat);
	do {
		printf("Introduceti grosimea chenarului: ");
		(void)scanf("%d", &bd);
	} while (bd < 0 || bd > m / 2);
	border_matrix(m, bd, mat);
	display_matrix(m, mat);
}