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
void find_matrix(float in_mat[][20], float out_mat[][20], float s_mat[][20], int l_m, int l_s)
{
	int i, j, k, l, t_f = 0, t_x, t_y;
	for (i = 0; i <= l_m - l_s; i++)
		for (j = 0; j <= l_m - l_s; j++)
		{
			if (s_mat[0][0] == in_mat[i][j])
			{
				for (k = 0; k < l_s; k++)
					for (l = 0; l < l_s; l++)
					{
						if (s_mat[k][l] == in_mat[k + i][l + j]) t_f = 1;
						else t_f = 0;
					}
				if (t_f == 1)
				{
					t_x = i;
					t_y = j;
				}
			}

		}
	if (t_f == 1)
	{
		for (i = 0; i < l_m; i++)
			for (j = 0; j < l_m; j++)
			{
				if (i == t_x && j == t_y)
				{
					for (k = 0; k < l_s; k++)
						for (l = 0; l < l_s; l++)
							out_mat[i + k][j + l] = in_mat[i + k][j + l];

				}
			}

	}
}
void init_matrix(int l, float in_mat[][20])
{
	int i, j;
	float red_value = -11.11;
	for (i = 0; i < l; i++)
		for (j = 0; j < l; j++)
			in_mat[i][j] = red_value;
}


void main()
{
	int l1, l2;
	
	float input_mat[20][20], output_mat[20][20] = { 0 }, s_mat[20][20];

	gen_matrix(&l1, input_mat);
	display_matrix(l1, input_mat);
	
	//read_matrix(&l1, input_mat);
	//display_matrix(l1, input_mat);
	init_matrix(l1, output_mat);

	do {
		read_matrix(&l2, s_mat);
	} while (l2 > l1);
	find_matrix(input_mat, output_mat, s_mat, l1, l2);
	display_matrix(l1, output_mat);


}