#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
void display_vector(int* n, float v[])
{
    int i;
    for (i = 0; i < *n; i++)
    {
        printf("%3.3f  ", v[i]);
    }
}

void buble_sort(float *v, int* n)
{
    int i, j;
    float temp;
    for (i = 0; i < *n - 1; i++)
        for (j = 0; j < * n - i - 1; j++)
            if (*(v + j) > *(v + j + 1))
            {
                temp = *(v + j);
                *(v + j) = *(v + j + 1);
                *(v + j + 1) = temp;
            }

}

void main()
{
    int m, i;
   
    printf("Introduceti marimea vectorului: ");
    (void)scanf("%d", &m);

    float* v = (float*)malloc(m * sizeof(float));
   
    for (i = 0; i < m; i++)
    {
        printf("\nv[%d] = ", i);
        (void)scanf("%f", v+i);
    }
    
    
    buble_sort(v, &m);
    display_vector(&m, v);
    
    free(v);

}