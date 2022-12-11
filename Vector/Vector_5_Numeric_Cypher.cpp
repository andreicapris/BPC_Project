#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void display_vector(int n, int v[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (v[i] == 32) printf(" ");
        else printf("|%d|", v[i]);
        
    }
}

void display_vector_c(int n, char v[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("|%c|", v[i]);
    }
}

void create_dict(char a[], int a_num[])   //This is done to remove the NULL at the end of the vector string.
{
    char dict[] = "abcdefghijklmnopqrstuvwxyz";
    int i;
    for (i = 0; i < 26; i++)
    {
        a[i] = dict[i];
        a_num[i] = i + 1;
    }
}

void encrypt(char a[], char dict[], int num_dict[], int num[], int len)
{
    int i, j;
    for (i = 0; i < 26; i++)
        for (j = 0; j < len; j++)
        {
            if (dict[i] == a[j]) num[j] = num_dict[i];
            if (a[j] == ' ') num[j] = ' ';
        }
}

void main()
{
    char alpha[26];
    int num_alpha[26], w_num[100];
    char w[100]={0}, temp;

    create_dict(alpha, num_alpha);
    //display_vector(26, num_alpha);
    printf("\n");
    printf("Introduceti un cuvant:");
    (void)scanf("%[^\n]", &w);
    printf("Numarul de caractere introduse: %d ", (int)strlen(w));
    printf("\n");
    display_vector_c((int)strlen(w), w);
    encrypt(w, alpha, num_alpha, w_num, (int)strlen(w));
    printf("\n");
    display_vector((int)strlen(w), w_num);

    //display_vector_c(26, alpha);
}