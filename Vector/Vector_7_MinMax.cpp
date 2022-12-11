#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct min_max_tuple {
    float mint, maxt;
};

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

min_max_tuple min_vector(int* n, float v[])
{
    int i;
    min_max_tuple tmp;
    tmp.mint = v[0];
    tmp.maxt = v[0];
    for (i = 1; i < *n; i++)
    {
        if (tmp.mint > v[i]) tmp.mint = v[i];
        if (tmp.maxt < v[i]) tmp.maxt = v[i];
    }
    return tmp;
}

void main()
{
    int m;
    float v[100];
    min_max_tuple mmt;

    read_vector(&m, v);
    mmt = min_vector(&m, v);
    printf("\nMaximul este %3.3f", mmt.maxt);
    printf("\nMinimul este %3.3f", mmt.mint);


}