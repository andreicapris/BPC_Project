/*Programul "roteste" vectorul la stanga sau la dreapta cu numarul de pasi din s*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void read_vector(int *n, float v[]) 
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

void display_vector(int *n, float v[])
{
    int i;
    for(i = 0; i < *n; i++)
    {
        printf("%3.3f  ", v[i]);
    }
}

void left_shift(int step, int l, float v[])
{
    float temp = 0;
    int i, s;
    s = step;

    do {
        temp = v[0];
        for (i = 0; i < l - 1; i++) {
            v[i] = v[i + 1];
        }
        v[l - 1] = temp;
        s--;
    } while (s != 0);
}

void right_shift(int step, int l, float v[])
{
    float temp = 0;
    int i, s;
    s = step;

    do {
        temp = v[l - 1];
        for (i = l - 1; i >= 1; i--)
        {
            v[i] = v[i-1];
        }
        v[0] = temp;
        s--;
    } while (s != 0);
}
void main()
{
    float v[100];
    int m, s, ans = 1;
    do {
        printf("Marimea pasului: ");
        (void)scanf("%d", &s);
    } while (s == 0);

        read_vector(&m, v);

        do {
            if (s > 0) right_shift(s, m, v);
            else if (s < 0)
            {
                s = -1 * s;
                left_shift(s, m, v);
            }

            printf("\n");
            display_vector(&m, v);
            printf("\nDoriti sa mai aplicati o data?(1/0)");
            (void)scanf("%d", &ans);
        } while (ans == 1);
}