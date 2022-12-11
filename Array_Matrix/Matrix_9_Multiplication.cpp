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

void display_matrix(int l, int h, float m[][40])
{
	int i = 0, j = 0;
	printf("\n       ");
	for (j = 0; j < l; j++)
		printf(" a[][%2d]", j);

	for (i = 0; i < h; i++)
	{
		printf("\na[%2d][]", i);
		for (j = 0; j < l; j++)
		{
			printf(" %7.2f", m[i][j]);
		}
	}
}

void prod_matrix(int li1, int hi1, int li2, int hi2, float m1[][20], float m2[][20], float res[][40])
{
	int i, j, k;
	if (li1 == 1 && hi1 == 1) {
		for (i = 0; i < hi2; i++)
			for (j = 0; j < li2; j++)
			{
				res[i][j] += m1[0][0] * m2[i][j];
			}
	}
	else if (li2 == 1 && hi2 == 1)
	{
		for (i = 0; i < hi1; i++)
			for (j = 0; j < li1; j++)
			{
				res[i][j] += m2[0][0] * m1[i][j];
			}
	}
	else
	{
		for (i = 0; i < hi1; i++)
		{
			for (j = 0; j < li2; j++)
			{
				for (k = 0; k < hi2; k++)
					res[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
}

void main()
{
	int la, lb, ha, hb;
	float ma[20][20], mb[20][20];
	float mr[40][40] = { 0 };

	printf("\nIntroduceti matricea A:");
	read_matrix(&la, &ha, ma);
	
	printf("\nIntroduceti matricea B:");
	read_matrix(&lb, &hb, mb);
	prod_matrix(la, ha, lb, hb, ma, mb, mr);
	if ((la != 1 && ha != 1) && (lb != 1 && hb != 1)) display_matrix(lb, ha, mr);
	else 
	{
		if (la == 1 && ha == 1) display_matrix(lb, hb, mr);
		else display_matrix(la, ha, mr);
	}

}