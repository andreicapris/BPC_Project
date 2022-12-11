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

void display_vector(int n, float v[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%3.3f  ", v[i]);
    }
}

void display_vector_f(int n, float v[])
{
    int i;
    for (i = 0; i < n; i+=2)
    {
        printf("\nr[%d] = %3.3f apare de %2.0f ori.", i/2, v[i], v[i+1]);
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

int mode_frequency_vector(int n, float v[], float r[])
{
    int i, j = 0, rep = 1;
    float temp;

    for (i = 0; i < n; i++)
    {
        temp = v[i];
        if (temp == v[i + 1]) 
        { 
            rep = rep + 1;
          
        }
        if (temp != v[i + 1]) {
            r[j] = v[i];
            r[j + 1] = (float)rep;
            rep = 1;
            j=j+2;
        }

    }
    return j;
}

void main()
{
    int m, l;
    float v[100], r[100];

    read_vector(&m, v);
    insert_sort(m, v);
    l = mode_frequency_vector(m, v, r);
    //display_vector(m, v);
    printf("\n");
    display_vector_f(l, r);
}