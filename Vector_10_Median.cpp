#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
void display_vector(int* n, float *v)
{
    int i;
    for (i = 0; i < *n; i++)
    {   
        
        printf("%3.3f  ", *(v + i));
    }
}

void buble_sort(float* v, int* n)
{
    int i, j;
    float temp;
    for (i = 0; i < *n - 1; i++)
        for (j = 0; j < *n - i - 1; j++)
            if (*(v + j) > *(v + j + 1))
            {
                temp = *(v + j);
                *(v + j) = *(v + j + 1);
                *(v + j + 1) = temp;
            }

}

float median_find(float* v, int* n)
{
    float imp_median, par_median;
    imp_median = *(v + *n / 2);
    par_median = (*(v + *n / 2) + *(v + *n / 2-1))/2;
    if (*n % 2 == 1)
        return imp_median;
    if (*n % 2 == 0)
        return par_median;
        
}

void main()
{
    int m, i;
    float median;

    printf("Introduceti marimea vectorului: ");
    (void)scanf("%d", &m);

    float* v = (float*)malloc(m * sizeof(float));

    for (i = 0; i < m; i++)
    {
        printf("\nv[%d] = ", i);
        (void)scanf("%f", v + i);
    }
   
    buble_sort(v, &m);
    median = median_find(v, &m);
    
    printf("Medianul este : %3.3f", median);

    

    //display_vector(&m, v);

    free(v);

}