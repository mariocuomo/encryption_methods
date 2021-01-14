#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

const int matrice[5][5]=
{
    {'b','t','a','l','p'},
    {'d','h','o','z','k'},
    {'q','f','v','s','n'},
    {'g','i','c','u','x'},
    {'m','r','e','w','y'}
};

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
Funzione per cifrare una stringa con il metodo di Polybius.
Si consideri la matrice 
	#  A  D  F  G  X
	A  b  t  a  l  p
	D  d  h  o  z  k
	F  q  f  v  s  n
	G  g  i  c  u  x
	X  m  g  e  w  y

In input è passato per riferimento la stringa e la stringa dove codificare.
*/
void cifraConPolybius();

/*
Funzione per trovare un elemento nella scacchiera di Polybius
Ritorna il numero del carattere identificativo della riga al quale si trova il carattere cercato
In input è passato l'elemento da trovare.
*/
int trovaRiga();

/*
Funzione per trovare un elemento nella scacchiera di Polybius
Ritorna il numero del carattere identificativo della colonna al quale si trova il carattere cercato
In input è passato l'elemento da trovare
*/
int trovaColonna();

/*
Funzione per riempire una matrice con i valori di un array
Si parte da sinistra verso destra e dall'alto verso il basso
In input è passato il vettore, la matrice e il numero di righe. Le colonne son fisse a 5 perchè dipendono dalla chiave
*/
void riempiMatrice();

/*
Funzione per effettuare la trasposizione di una matrice
Si considera la chiave ZAINO

colonne 12345 sono permutate in 23451
*/
void trasposizioneColonneMatrice();

/*
Funzione per copiare una matrice in una stringa
Si parte da dall'alto verso il basso e da sinistra verso destra
In input è passata la matrice e la stringa
*/
void cifraDaMatriceAStringa();


int main()
{
	char tmp_stringa[30];
	char *stringa;
	printf("Il cifrario ADFGX e' un metodo crittografico a trasposizione con frazionamento\n");
	printf("Prende nome ADFGX perche' queste sono le uniche lettere che compaiono nel messaggio finale cifrato\n");
	printf("Si prende in considerazione una matrice 5x5 con l'alfabeto mescolato considerando i=j\n");
	printf("La matrice che consideriamo e' la seguente\n");


	printf("#  A  D  F  G  X\n");
	printf("A  b  t  a  l  p\n");
	printf("D  d  h  o  z  k\n");
	printf("F  q  f  v  s  n\n");
	printf("G  g  i  c  u  x\n");
	printf("X  m  r  e  w  y\n");

	printf("Vediamo un esempio.\n");
	printf("Se prendo la stringa 'ciao come stai' la prima cosa da fare e' decifrarla come avviene nel codice di Polybius\n");
	printf("RICORDA: a ogni lettera e' sostituita la coppia riga/colonna\n");
	printf("Al posto di 'ciao' si ottiene 'GF GD AF DF\n");
	printf("Al posto di 'come' si ottiene 'GF DF XA XF\n");
	printf("Al posto di 'stai' si ottiene 'FG AD AF GD\n");
	printf("La stringa finale e' 'GF GD AF DF GF DF XA XF FG AD AF GD\n");

	printf("A questo punto si considera una chiave e per semplicita' la scegliamo di 5 caratteri.\n");
	printf("La chiave che consideriamo e' 'ZAINO'.\n");
	printf("Si costruisce una matrice di 5(perche' la chiave e' lunga 5) colonne\n");
	printf("Si scrive il messaggio cifrato in essa partendo da sinistra verso destra e dall'alto verso il basso\n");
	printf("Nell'esempio il risultato e' il seguente\n");

	printf("Z  A  I  N  O\n");
	printf("G  F  G  D  A\n");
	printf("F  D  F  G  F\n");
	printf("D  F  X  A  X\n");
	printf("F  F  G  A  D\n");
	printf("A  F  G  D    \n");

	printf("A questo punto si effettua la trasposizione colonnare ordinando alfabeticamente la chiave\n");
	printf("La matrice che si ottiene e' la seguente\n");

	printf("A  I  N  O  Z\n");
	printf("F  G  D  A  G\n");
	printf("D  F  G  F  F\n");
	printf("F  X  A  X  D\n");
	printf("F  G  A  D  F\n");
	printf("F  G  D     A \n");

	printf("L'ultimo passaggio da effettuare e' estrarre il messaggio cifrato colonna per colonna partendo dall'alto verso il basso e da sinistra verso destra\n");
	printf("Il messaggio cifrato e' il seguente FDFFF GFXGG DGAAD AFXD GFDFA\n");
	printf("Per semplicita' scegliamo l'alfabeto internazionale composto di 26 caratteri minuscoli\n");

	printf("Inserisci la stringa che vuoi cifrare\n");
	printf("Stringa: ");
	scanf("%s",tmp_stringa);


	while(!stringaCorretta(tmp_stringa)){
		printf("Per semplicita' scegliamo l'alfabeto internazionale composto di 26 caratteri minuscoli\n");
		printf("Inserisci la stringa che vuoi cifrare\n");
		printf("Stringa: ");
		scanf("%s",tmp_stringa);
	}


	stringa=malloc(strlen(tmp_stringa) * sizeof(char));
	strcpy(stringa,tmp_stringa);
	free(tmp_stringa);
	int l=strlen(stringa);
	cifraStringa(stringa);
	stringa[2*l]='\0';
	printf("\nEcco la stringa cifrata con il cifrario ADFGX\n");
	printf("Stringa cifrata: %s\n",stringa);
}


void cifraStringa(char* stringa){
	int l=strlen(stringa);
	char tmpPolybius[2*l];
	int **matricetmp;
	int i=0;

	int righe;

	if( ((2*l)%5)!=0)
		righe=(2*l/5)+1;
	else
		righe=2*l/5;


	matricetmp = malloc(righe * sizeof(int));
  	for (i=0; i<righe; i++)
    	matricetmp[i] = malloc(5 * sizeof(int));

	cifraConPolybius(stringa,tmpPolybius);

	riempiMatrice(matricetmp, tmpPolybius,righe);

	trasposizioneColonneMatrice(matricetmp, righe);

	realloc(tmpPolybius, righe*5*sizeof(char));

	cifraDaMatriceAStringa(matricetmp, tmpPolybius, righe);

	realloc(stringa, righe*5*sizeof(char));
	strcpy(stringa,tmpPolybius);
	free(tmpPolybius);
}

int stringaCorretta(char* stringa){
	int i=0;
	int l = strlen(stringa);
	for(i=0; i<l;i++)
		if(stringa[i]<97 || stringa[i]>122)
			return 0;

	return 1;
}


void cifraConPolybius(char* stringa, char* stringaCifrata){
	int i=0;
	int l=strlen(stringa);

	for(i=0; i<l*2;i++){
		stringaCifrata[i*2]=trovaRiga(stringa[i]);
		stringaCifrata[(i*2)+1]=trovaColonna(stringa[i]);
	}

	printf("\nEcco la stringa cifrata con Poly: %s", stringaCifrata);
}


int trovaRiga(int lettera){
	if(lettera==105 || lettera==106)
		return 'G';

	int i=0;
	int j=0;

	for(i=0; i<5;i++)
		for(j=0; j<5;j++)
			if(matrice[i][j]==lettera){
				switch (i){
					case 0: 
						return 'A';
						break;
					case 1: 
						return 'D';
						break;
					case 2: 
						return 'F';
						break;
					case 3: 
						return 'G';
						break;
					case 4: 
						return 'X';
						break;
				}
				return 'X';
			}

	return 0;
}

int trovaColonna(int lettera){
	if(lettera==105 || lettera==106)
		return 'D';
	int i=0;
	int j=0;

	for(j=0; j<5;j++)
		for(i=0; i<5;i++)
			if(matrice[i][j]==lettera){
				switch (j){
					case 0: 
						return 'A';
						break;
					case 1: 
						return 'D';
						break;
					case 2: 
						return 'F';
						break;
					case 3: 
						return 'G';
						break;
					case 4: 
						return 'X';
						break;
				}
				return j;
			}
	return 0;
}


void riempiMatrice(int** matricetmp, char* stringaCifrata, int x){
	int i=0;
	int j=0;
	int k=-1;
	while(i<strlen(stringaCifrata)){
		int valore = stringaCifrata[i];
		k++;
		if(k==5){
			k=0;
			j++;
		}
		matricetmp[j][k]=stringaCifrata[i];
		i++;
	}

	//riempi il resto della matrice con spazi
	for(k=k+1;k<5;k++)
		matricetmp[j][k]=' ';


	printf("\nEcco la matrice riempita\n");
	printf("Z  A  I  N  O\n");
	printf("-------------\n");

	for(i=0;i<x;i++){
		for(j=0;j<5;j++){
			printf("%c  ", matricetmp[i][j]);
		}
		printf("\n");
	}
}

void trasposizioneColonneMatrice(int** matricetmp, int x){
	//colonne 12345 sono permutate in 23451
	int i=0;
	int j=0;

	int **matrice;
	matrice = malloc(x * sizeof(int));
  	for (i=0; i<x; i++)
    	matrice[i] = malloc(5 * sizeof(int));


	//copia matrice
	for(i=0;i<x;i++)
		for(j=0;j<5;j++)
			matrice[i][j]=matricetmp[i][j];

	//inverti posizioni
	for(i=0;i<x;i++)
		for(j=0;j<5;j++)
			switch (j){
					case 0: 
						matricetmp[i][j]=matrice[i][1];
						break;
					case 1: 
						matricetmp[i][j]=matrice[i][2];
						break;
					case 2: 
						matricetmp[i][j]=matrice[i][3];
						break;
					case 3: 
						matricetmp[i][j]=matrice[i][4];
						break;
					case 4: 
						matricetmp[i][j]=matrice[i][0];
						break;
				}

	printf("\nEcco la matrice dopo la trasposizione\n");
	printf("A  I  N  O  Z\n");
	printf("-------------\n");

	for(i=0;i<x;i++){
		for(j=0;j<5;j++){
			printf("%c  ", matricetmp[i][j]);
		}
		printf("\n");
	}

	free(matrice);
}

void cifraDaMatriceAStringa(int** matricetmp,char* stringaCifrata, int x){
	int i=0;
	int j=0;
	int k=-1;
	printf("%d\n",x);
	for(i=0;i<5;i++)
		for(j=0;j<x;j++){
			if(matricetmp[j][i]!=' '){
				k++;
				stringaCifrata[k]=matricetmp[j][i];
			}
		}
}
