#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*
Funzione per cifrare una stringa.
In input è passato per riferimento una stringa.
La funzione cifra la stringa in input.
*/
void cifraStringa();

/*
Funzione per verificare se una stringa è composta da soli catteri dell'alfabeto internazionale minuscoli
In input è passato per riferimento una stringa.
Ritorna 1 in caso positivo, 0 in caso negativo
*/
int stringaCorretta();

/*
Funzione per creare un vettore di interi a partire da una stringa.
La stringa contiene caratteri da a a z.
La conversione avviene seguendo questo schema a=0, b=1, c=2, ... 
In input è passato per riferimento la stringa e il vettore.
*/
void riempiVettoreDiInteri();

/*
Funzione per calcolare il prodotto scalare tra due vettori
*/
int prodottoScalare();

int main()
{
	char tmp_stringa[30];
	char *stringa;
	printf("Il Cifrario di Hill e' un algoritmo di crittografia a sostituzione polialfabetica\n");
	printf("Ogni lettera e' sostituita con una nuova lettera effettuando un prodotto scalare con una matrice.\n");
	printf("La matrice rappresenta la chiave.\n");
	printf("Se ho una stringa di lunghezza n ho bisogno di una matrice nxn\n");
	printf("Per semplicita' consideriamo n=3 e la seguente matrice come chiave\n");

	printf("#  1   2   3\n");
	printf("1  15  2   4\n");
	printf("2  3   13  5\n");
	printf("3  1   3   3\n");

	printf("Vediamo un esempio.\n");
	printf("Se prendo la stringa 'cde' devo effettuare i seguenti passi\n");
	printf("c=2 d=3 e=4 rappresenta il vettore (2,3,4)\n");
	printf("Il primo carattere si ottiene come (2,3,4)x(15 2 4) = 2x15 + 3x2 + 4x4 = 30 + 6 + 16 = 52.\n");
	printf("52 modulo 26 restituisce 0 che rappresenta lo 0. Si sostituisce il primo carattere con'a'\n");
	
	printf("Il secondo carattere si ottiene come (2,3,4)x(3 13 5) = 2x3 + 3x13 + 4x5 = 6 + 39 + 20 = 65.\n");
	printf("65 modulo 26 restituisce 13. Si sostituisce il secondo carattere con 'n'\n");

	printf("Il terzo carattere si ottiene come (2,3,4)x(1 3 3) = 2x1 + 3x3 + 4x3 = 2 + 9 + 12 = 23.\n");
	printf("23 modulo 26 restituisce 23. Si sostituisce il terzo carattere con 'x'\n");

	printf("Inserisci la stringa di lunghezza 3 che vuoi cifrare\n");
	printf("Stringa: ");
	scanf("%s",tmp_stringa);


	while(!stringaCorretta(tmp_stringa)){
		printf("Per semplicita' scegliamo l'alfabeto internazionale composto di 26 caratteri minuscoli\n");
		printf("Inserisci la stringa di lunghezza 3 che vuoi cifrare\n");
		printf("Stringa: ");
		scanf("%s",tmp_stringa);
	}


	stringa=malloc(strlen(tmp_stringa) * sizeof(char));
	strcpy(stringa,tmp_stringa);
	free(tmp_stringa);
	int l=strlen(stringa);
	printf("Ecco la stringa cifrata con il cifrario di Hill\n");
	cifraStringa(stringa);
	stringa[2*l]='\0';
	printf("Stringa cifrata: %s\n",stringa);
}


void cifraStringa(char* stringa){
	int i=0;
	int j=0;
	int tmp=0;
	int matrice[3][3] ={{15, 2, 4}, {3, 13, 5}, {1, 3, 3}}; 
	int vettore_stringa[3];
	riempiVettoreDiInteri(vettore_stringa, stringa);

	for(i=0;i<3;i++){
		stringa[i]=(prodottoScalare(matrice[i], vettore_stringa))%26;
		stringa[i]+=97;
	}
}

int stringaCorretta(char* stringa){
	if(strlen(stringa)!=3)
		return 0;

	int i=0;
	int l = strlen(stringa);
	for(i=0; i<l;i++)
		if(stringa[i]<97 || stringa[i]>122)
			return 0;

	return 1;
}

void riempiVettoreDiInteri(int* vettore_stringa, char* stringa){
	int i=0;

	for(i=0;i<3;i++)
		vettore_stringa[i]=stringa[i]-97;
}

int prodottoScalare(int* vettore1, int* vettore2){
	int tmp=0;
	int i=0;
	for(i=0;i<3;i++)
		tmp+=vettore1[i]*vettore2[i];
	return tmp;
}

