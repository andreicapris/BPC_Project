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
    for (i = 0; i < *n; i++)
    {
        printf("%3.3f  ", v[i]);
    }
}

bool check_sym(int n, float v[])
{
    int i;
    bool result = false;

    for (i = 0; i <= n / 2 - 1; i++)
        {
            if (v[i] == v[n - i - 1]) result = true;
            else result = false;
        }
  return result;
}

void main()
{
    int m;
    bool m_result;
    float v[100];

    read_vector(&m, v);
    m_result = check_sym(m, v);
    printf("%s\n", m_result ? "True" : "False");
    display_vector(&m, v);
}