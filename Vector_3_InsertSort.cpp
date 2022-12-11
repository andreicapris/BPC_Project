#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void read_vector(int* n, float v[])
{
    int i;
    printf("\nNumarul de elemente:");
    (void)scanf("%d", n);
    for (i = 0; i < *n; i++)
    {
        printf("\nv[%d] = ", i);
        (void)scanf("%f", &v[i]);
    }
}

void display_vector(int* n, float v[])
{
    int i;
    for (i = 0; i < *n; i++)
    {
        printf("%3.3f  ", v[i]);
    }
}

void insert_sort(int n, float v[]) 
{
    int i, j;
    float temp;
    for (i = 1; i < n; i++)
    {
        temp = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > temp)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = temp;
    }
}

void main()
{
    int m;
    float v[100];
    read_vector(&m, v);
    insert_sort(m, v);
    display_vector(&m, v);
}