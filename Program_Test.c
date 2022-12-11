#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int colors[9] = {0x000000, 0xFFFFFF, 0xFFFF00, 0x00FFFF, 0x008000, 0xFF00FF, 0xFF0000, 0x0000FF, 0x000000 };
//colors contine valorile pentru mira de bare
int i, j;

	/*int white = 0xFFFFFF;
	int yellow = 0xFFFF00;
	int cyan = 0x00FFFF;
	int green = 0x008000;
	int magenta = 0xFF00FF;
	int red = 0xFF0000;
	int blue = 0x0000FF;
	int black = 0x000000;*/

typedef struct RGB
{
	int R, G, B; //structura folosita ca sa pot returna valorile RGB dupa separare
}RGB;

 typedef struct coord
{
	int x, y, value; //structura ca sa pot returna pozitia in matrice si valoarea 
}coord;

void RGB_color_bars(int* height, int* width, int display_matrix[][40])
{
	//procedura aceasta citeste dimensiunea matricei si o populeaza cu mira de bare 
	int count = 0;
	int bar_width = 0;

	printf("\nInaltimea ecranului(Numarul de linii) = ");
	(void)scanf("%d", height);
	printf("\nLungimea ecranului(Numarul de coloane) = ");
	(void)scanf("%d", width);

	
	if (*width < 8) bar_width = 2; // variabila utilizata ca sa putem repeta culoarea pe coloane adiacente
	else bar_width = *width / 8;

	for (i = 0; i < *height; i++)
	{
		count = 0;
		for (j = 0; j < *width; j++)
		{
			if (j % bar_width == 0) count++; //nu se incrementeaza decat atunci cand j depasesete un multiplu de bar_width
			display_matrix[i][j] = colors[(8 + count) % 8];//artificiu ca sa nu mi iasa din matricea de culori
			

		}
	}

}

void randomize_matrix(int *height, int *width, int display_matrix[][40])
{
	//procedura ce populeaza matricea cu valori random utilizand rand() din stdlib.h
	printf("\nInaltimea ecranului(Numarul de linii) = ");
	(void)scanf("%d", height);
	printf("\nLungimea ecranului(Numarul de coloane = ");
	(void)scanf("%d", width);
	
	for (i = 0; i < *height; i++)
		for (j = 0; j < *width; j++)
			display_matrix[i][j] = 0xFFFFFF - rand() % 0xFFFFFF;
	//pt scopul meu valorile nu erau destul de random asa ca le-am scazut din FFFFFF
}

RGB convert_to(int input)
{
	//functia aceasta converteste un hexa RGB in elementele componente R G B
	RGB value;
	
	value.R = input >> 16; //shift ca sa luam primele doua hexa din numar pt R
	value.G = (input >> 8) & 0x00FF;//shift si masca pentru G
	value.B = input & 0x0000FF;//masca pentr B F & orice hexa imi va returna acel hexa

	return value;
}
RGB value_return(int x, int y, int mat[][40])
{
	//functie creata ca sa pot pasa direct si coordonatele
	return convert_to(mat[x][y]);
}

void pixel_value(int h, int w, int mat[][40])
{
	int x, y;
	RGB temp;
	do {
		printf("Introduceti coordonata liniei:");
		(void)scanf("%d", &x);
	} while (x > h || x <= 0); // sa nu depasesc dimensiunile matricei
	do {
		printf("Introduceti coordonata coloanei:");
		(void)scanf("%d", &y);
	} while (y > w || y <= 0);
	temp = value_return(x, y, mat);
	printf("\nR:%X, G:%X , B:%X", temp.R, temp.G, temp.B);//valorile individuale hexa
	printf("\nR:%d, G:%d , B:%d", temp.R, temp.G, temp.B);//valorile individuale int
	printf("\n");
}



void grayscale_matrix(int height, int width, int display_matrix[][40])
{
	//procedura pentru a aplica grayscale pe matricea curenta si a converti totul in nivele de gri
	RGB buffer;
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
		{
			buffer = convert_to(display_matrix[i][j]);
			//display_matrix[i][j] =(int)(0.299 * buffer.R + 0.587 * buffer.G + 0.114 * buffer.B);
			//Modalitatea moderna de calcul a grayscale-ului.
			display_matrix[i][j] = buffer.R / 3 + buffer.G / 3 + buffer.B / 3;
			//impartim individual la 3 ca sa nu depasim FFFFFF in suma. 
		}
}


void display_matrix(int height, int width, int m[][40])
{
	//procedura de afisare a matricei depinzand de latimea ecranului arata bine pana pe la 40 de elemente 
	//dupa aceea formatarea se strica
	int i = 0, j = 0;
	printf("\n       ");//creat pentru formatare
	for (j = 0; j < width; j++)
		printf(" a[][%2d]", j);

	for (i = 0; i < height; i++)
	{
		printf("\na[%2d][]", i);
		for (j = 0; j < width; j++)
		{
			printf(" x%06X", m[i][j]);
		}
	}
}

void rotate_matrix(int w, int h, int in_m[][40], int out_m[][40])
{   //procedura de rotire cu 90 de grade la stanga a valorilor din matrice
	//are si matrice de iesire ca sa mi fie mai usor cand programul face asta de multiple ori.
	int i, j;
	for (j = 0; j < h; j++)
	{
		for (i = 0; i < w; i++)
			out_m[w - i - 1][j] = in_m[j][i];
	}

}

void swap_matrix(int h, int w, int in_m[][40], int out_m[][40])
{//procedura creata pentru a ajuta rotirea ca atunci cand rotirea e selectata matricea principala sa devina cea rotita
	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
			out_m[i][j] = in_m[i][j];
}

coord max_point(int h, int w, int mat[][40])
{
	//functie care mi returneaza valoarea minima si ultima pozitie gasita
	int max = mat[0][0];
	coord temp = {0};
	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
		{
			if (mat[i][j] >= max)
			{
				max = mat[i][j];
				temp.x = i;
				temp.y = j;
				temp.value = max;
			}
		}
	return temp;
}
coord min_point(int h, int w, int mat[][40])
{
	//functie care mi returneaza valoarea maxima si ultima pozitie gasita
	int min = mat[0][0];
	coord temp = {0};
	for (i = 0; i < h; i++)
		for (j = 0; j < w; j++)
		{
			if (mat[i][j] <= min)
			{
				min = mat[i][j];
				temp.x = i;
				temp.y = j;
				temp.value = min;
			}
		}
	return temp;
}


void meniu(int* opt)
{ //procedura meniu
	printf("\n ------Aplicatie de simulare a proceselor dintr-un ecran------");
	printf("\n Optiunile sunt:");
	printf("\n 1. Afiseaza starea curenta a ecranului.");
	printf("\n 2. Genereaza stare ecran aleatorie.");
	printf("\n 3. Genereaza mira de bare.");
	printf("\n 4. Aplica grayscale.");
	printf("\n 5. Roteste ecranul.");
	printf("\n 6. Returneaza valorile RGB hexa si intregi ale unui pixel.");
	printf("\n 7. Returneaza coordonatele minimului din ecran.");
	printf("\n 8. Returneaza coordonatele maximului din ecran.");
	printf("\n 9. Detalii despre program.");
	printf("\n 0. IESIRE");
	printf("\n Optiunea dvs. este:");
	(void)scanf("%d", opt);
}



int main(int argc, char **argv)
{
	int h = 10, w = 10, o;//initializam h si w deoarece daca in case se selecteaza direct afisare ecran ele nu vor avea valori.
	int temp_h; //utilizata ca sa inversam inaltimea si latimea cand facem rotatia. 
	int screen[40][40] = { 0 }, out[40][40]; //nu am alocat dinamic deoarece nu sunt destul de increzator in skillurile mele cu alocarea
	coord poz;//utilizata cand se selecteaza min sau maxim
	
	
	do
	{
		meniu(&o);
		switch (o)
		{
		case 1:
			display_matrix(h, w, screen);
			break;

		case 2:
			randomize_matrix(&h, &w, screen);
			display_matrix(h, w, screen);
			break;

		case 3:
			RGB_color_bars(&h, &w, screen);
			display_matrix(h, w, screen);
			break;

		case 4:
			grayscale_matrix(h, w, screen);
			display_matrix(h, w, screen);
			break;

		case 5:
			rotate_matrix(w, h, screen, out);
			display_matrix(w, h, out);
			temp_h = h;
			h = w;
			w = temp_h;
			swap_matrix(h, w, out, screen);
			break;

		case 6:
			pixel_value(h, w, screen);
			break;

		case 7:
			poz = min_point(h, w, screen);
			printf("\nMinimul este %X se gaseste la coordonata x:%d y:%d.", poz.value, poz.x, poz.y);
			printf("\n");
			break;
		case 8:
			poz = max_point(h, w, screen);
			printf("\nMaximul este %X se gaseste la coordonata x:%d y:%d.", poz.value, poz.x, poz.y);
			printf("\n");
			break;

		case 9:
			printf("\nProgramul trateaza o matrice ca un display de latimea si lungimea matricei.");
			printf("\nFiecare element din matrice este considerat un pixel cu o valoare hexa corespunzatoare fiecarei culori.");
			printf("\nNu are procedura de populare manuala a matricei iar datele de intrare sunt dimensiunile.");
			printf("\nOptiunea 1 afiseaza starea curenta a matricei care este initializata cu 0.");
			printf("\nOptiunea 2 cere input de dimensiuni si o populeaza cu valori random.");
			printf("\nOptiunea 3 cere input de dimensiuni si o populeaza cu aceleasi valori pe coloane asemanator cu mira de bare din televiziune");
			printf("\nOptiunea 4 aplica grayscale pe valori care in esenta este o medie aritmetica a valorilor RGB.");
			printf("\nOptiunea 5 roteste matricea cu 90 de grade la stanga.");
			printf("\nOptiunea 6 returneaza valorile RGB ale unui element din matrice dupa introducerea coordonatelor lui.");
			printf("\nOptiunea 7 returneaza locatia elementului minim din matrice, in cazul mai multor puncte de minim doar ultimul este returnat.");
			printf("\nOptiunea 8 returneaza locatia elementului maxim din matrice, in cazul mai multor puncte de maxim doar ultimul este returnat.");
			printf("\n");
			break;

		case 0:
			printf("\n Ati ales sa parasiti aplicatia!");
			break;

		default: printf("\n Optiune invalida!"); break;
		}
	} while (o != 0);

return 0;

	

}