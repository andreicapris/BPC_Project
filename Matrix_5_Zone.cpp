#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct zones {
	float z1, z2, z3, z4;
};
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

zones compute_zones(int l, float m[][20], zones z)
{
	int i, j;

	for (i = 0; i < l; i++)
		for (j = 0; j <= i; j++)
		{
			//if (i == l - j - 1) z += m[i][j];
			//if (i == j) continue;
			z.z2 += m[i][j];
		}

	for (i = 0; i < l; i++)
		for (j = i; j < l; j++)
		{
			//if (i == j) continue;
			z.z1 += m[i][j];
		}

	for (i = 0; i < l; i++)
		for (j = 0; j <= l-i-1; j++)
		{
			//(i == l - j - 1) continue;
			z.z3 += m[i][j];
		}

	for (i = 0; i < l; i++)
		for (j = l - i - 1; j < l; j++)
		{
			//(i == l - j - 1) continue;
			z.z4 += m[i][j];
		}

	return z;
}

void main()
{
	int m;
	float mat[20][20];
	zones rez = { 0 };

	read_matrix(&m, mat);
	display_matrix(m, mat);
	rez = compute_zones(m, mat, rez);
	printf("\nSuma elementelor de deasupra diagonalei principale este: %f.", rez.z1);
	printf("\nSuma elementelor de sub diagonala principala este: %f.", rez.z2);
	printf("\nSuma elementelor de deasupra diagonalei secundare este:: %f.", rez.z3);
	printf("\nSuma elementelor de sub diagonala secundara este:: %f.", rez.z4);

}