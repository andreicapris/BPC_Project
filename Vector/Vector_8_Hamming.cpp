#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
void read_vector(bool v[])
{
    int i, temp;
    for (i = 0; i < 8; i++)
    {
        do {
            printf("\nv[%d] = ", i);
            (void)scanf("%d", &temp);
            v[i] = temp;
        } while (temp != 1 && temp != 0);
    }
}

void display_vector(bool v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}

void hamming_vector(bool v[], bool h[])
{
    h[0] = v[0] ^ v[1] ^ v[3] ^ v[4] ^ v[6];
    h[1] = v[0] ^ v[2] ^ v[3] ^ v[5] ^ v[6];
    h[2] = v[1] ^ v[2] ^ v[3] ^ v[7];
    h[3] = v[4] ^ v[5] ^ v[6] ^ v[7];
}

void merge_vector(bool v[], bool h[], bool res[])
{
    int i, j = 0, k = 0;
    //bool res[12];
    for (i = 0; i < 12; i++)
        if (i == 0 || i == 1 || i == 3 || i == 7)
        {
            res[i] = h[j];
            j++;
        }
        else 
        {
            res[i] = v[k];
            k++;
        }
}

int main(int argc, char **argv)
{
    int m;
    bool v[8], ham[4], result[12];
    

   read_vector(v);  
   hamming_vector(v, ham);
   display_vector(v,8);
   printf("\n");
   display_vector(ham,4);
   merge_vector(v, ham, result);
   printf("\n");
   display_vector(result, 12);

   return 0;
}