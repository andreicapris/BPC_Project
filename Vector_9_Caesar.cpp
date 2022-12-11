#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void create_dict(char a[])   //This is done to remove the NULL at the end of the vector string.
{
	char dict[] = "abcdefghijklmnopqrstuvwxyz";
	int i;
	for (i = 0; i < 26; i++)
	{
		a[i] = dict[i];
	}
}

void left_shift(int step, char v[])
{
    float temp = 0;
    int i, s, l = 26;
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

void right_shift(int step, char v[])
{
    float temp = 0;
    int i, s, l = 26;
    s = step;

    do {
        temp = v[l - 1];
        for (i = l - 1; i >= 1; i--)
        {
            v[i] = v[i - 1];
        }
        v[0] = temp;
        s--;
    } while (s != 0);
}

void encrypt(char in_w[], char a[], char a_c[], char out_w[])
{
    int i, j;
    for(i = 0; i<26; i++)
        for (j = 0; j < (int)strlen(in_w); j++)
        {
            if (a[i] == in_w[j]) out_w[j] = a_c[i];
            if (in_w[j] == ' ') out_w[j] = ' ';
        }

}

void display_vector_c(int n, char v[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%c", v[i]);
    }
}

void main()
{
    char in_word[100] = { 0 }, temp, alpha[26], alpha_cipher[26], out_word[100] = { 0 };
	int s;
    create_dict(alpha);
    create_dict(alpha_cipher);


	printf("\nIntroduceti valoarea rotatiei:");
	(void)scanf("%d", &s);
	(void)scanf("%c", &temp);

    if (s > 0) right_shift(s, alpha_cipher);
    else if (s < 0)
        {
            s = -1 * s;
            left_shift(s, alpha_cipher);
        }

    display_vector_c(26, alpha_cipher);

	printf("\nIntroduceti mesajul:\n");
	(void)scanf("%[^\n]", in_word);
    //printf("%d", (int)strlen(in_word));

    encrypt(in_word, alpha, alpha_cipher, out_word);
    printf("\n");
    display_vector_c((int)strlen(in_word), out_word);

}