#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*
Funzione per cifrare una stringa.
In input è passato per riferimento una stringa e per valore un intero.
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
Funzione per trovare un elemento nella scacchiera di Polybius
Ritorna il numero di riga al quale si trova il carattere cercato
In input è passata la scacchiera e l'elemento da trovare.
*/
int trovaRiga();

/*
Funzione per trovare un elemento nella scacchiera di Polybius
Ritorna il numero di colonna al quale si trova il carattere cercato
In input è passato il vettore riga e l'elemento da trovare
*/
int trovaColonna();

int main()
{
	char tmp_stringa[30];
	char *stringa;
	printf("La scacchiera di Polybius e' un algoritmo di crittografia che converte caratteri in numeri\n");
	printf("Ogni lettera e' sostituita con il la coordinata corrispondente nella seguente scacchiera\n");
	
	printf("#  1  2  3  4  5\n");
	printf("1  a  b  c  d  e\n");
	printf("2  f  g  h  ij k\n");
	printf("3  l  m  n  o  p\n");
	printf("4  q  r  s  t  u\n");
	printf("5  v  w  x  y  z\n");

	printf("Vediamo un esempio.\n");
	printf("Se prendo la stringa 'ab' ottengo '1112'\n");
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
	printf("Ecco la stringa cifrata con la scacchiera di Polybius\n");
	cifraStringa(stringa);
	stringa[2*l]='\0';
	printf("Stringa cifrata: %s\n",stringa);
}


void cifraStringa(char* stringa){
	int i=0;
	int j=0;
	int carattere=97;
	int **scacchieraDiPoli;
	
	//crea la scacchiera
	scacchieraDiPoli = malloc(5 * sizeof(int));
  	for (i=0; i<5; i++)
    	scacchieraDiPoli[i] = malloc(5 * sizeof(int));

	for(i=0; i<5;i++){
		for(j=0;j<5;j++){
			scacchieraDiPoli[i][j]=carattere;
			carattere++;
			if(carattere==106)
				carattere++;
		}
	}

	int l = strlen(stringa);

	int tmprighe[l];
	int tmpcolonne[l];
	int tmp[2*l];

	//riempi tmprighe e tmpcolonne
	for(i=0; i<l;i++){
		int riga = trovaRiga(scacchieraDiPoli,stringa[i]);
		int colonna = trovaColonna(scacchieraDiPoli[riga],stringa[i]);

		tmprighe[i]=riga+1;
		tmpcolonne[i]=colonna+1;
	}

	//raddoppia stringa
	realloc(stringa, 2*l*sizeof(char));

	//riempi tmp
	for(i=0, j=0;i<(l*2);i++,j++){
		tmp[i]=tmprighe[j];
		tmp[i+1]=tmpcolonne[j];
		i++;
	}
 
 	//riempi stringa
	for(i=0; i<(2*l);i++){
		stringa[i]=48+tmp[i];
	}
	

  	free(tmp);
  	free(tmprighe);
  	free(tmpcolonne);
}

int stringaCorretta(char* stringa){
	int i=0;
	int l = strlen(stringa);
	for(i=0; i<l;i++)
		if(stringa[i]<97 || stringa[i]>122)
			return 0;

	return 1;
}

int trovaRiga(int** scacchieraDiPoli, int lettera){
	if(lettera==105 || lettera==106)
		return 1;

	int i=0;
	int j=0;

	for(i=0; i<5;i++)
		for(j=0; j<5;j++)
			if(scacchieraDiPoli[i][j]==lettera){
				return i;
			}

	return 0;
}

int trovaColonna(int* vettore, int lettera){
	if(lettera==105 || lettera==106)
		return 3;
	int i=0;
	int j=0;

	for(i=0; i<5;i++)
		if(vettore[i]==lettera){
			return i;
		}


	return 0;
}

