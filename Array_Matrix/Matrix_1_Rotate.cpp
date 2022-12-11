#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
	printf("\n       ");
	for (j = 0; j < l; j++)
		printf("  a[][%d]", j);

	for (i = 0; i < h; i++)
	{
		printf("\na[%d][] ", i+1);
		for (j = 0; j < l; j++)
		{
			printf(" %7.2f", m[i][j]);
			//0 flag pentru padding la stanga langa 6 il putem pune ca sa ne facem o idee despre cum va arata
			//6 nr total de caractere afisate incluzand punctul
			//o data ce depasim 5 zecimale afisarea se strica sau 4 + semn
		}
	}
}

void rotate_matrix(int l, int h, float in_m[][20], float out_m[][20])
{
	int i, j;
	for (j = 0; j < h; j++)
		{
			for (i = 0; i < l; i++)
				out_m[l - i - 1][j] = in_m[j][i];
		}
		
}

int main(int argc, char **argv)
{
	int lin, col; 
	float in_mat[20][20] = { 0 }, out_mat[20][20] = { 0 };
	

	read_matrix(&col, &lin, in_mat);
	rotate_matrix(col, lin, in_mat, out_mat);
	display_matrix(col, lin, in_mat);
	display_matrix(lin, col, out_mat);
	printf("\n");
	printf("\nDupa inca o rotatie");
	rotate_matrix(lin, col, out_mat, in_mat);
	display_matrix(col, lin, in_mat);
	
	
		
	return 0;	
	
}