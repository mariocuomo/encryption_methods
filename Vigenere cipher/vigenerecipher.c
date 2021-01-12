#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Funzione per cifrare una stringa.
In input è passato per riferimento una stringa da cifrare e la chiave di cifratura.
La funzione cifra la stringa in input.
*/
void cifraStringa();

/*
Funzione per verificare se una stringa è composta da soli catteri dell'alfabeto internazionale minuscoli
In input è passato per riferimento una stringa
Ritorna 1 in caso positivo, 0 in caso negativo
*/
int stringaCorretta();


int main()
{
	char tmp_stringa[30];
	char tmp_chiave[30];
	char *stringa;
	char *chiave;

	printf("Il cifrario di Vigenère e' un algoritmo di crittografia a sostituzione\n");
	printf("Ogni lettera e' sostituita con un'altra a distanza descritta da una chiave\n");
	printf("Vediamo un esempio.\n");
	printf("Se prendo la stringa 'ciao' e scelgo la chiave 'abba' ottengo 'cjbo'\n");
	printf("Il codice e' ciclico, se prendo la stringa 'yz' e scelgo la chiave 'dd' ottengo 'bc'\n");
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

	printf("Inserisci la chiave di cifratura\n");
	printf("La chiave deve avere al piu' (maggiore di 0) la lunghezza della stringa da cifrare\n");
	printf("Se la chiave e' piu' grande verra' troncata. Se la chiave e' piu' piccola verra' ripetuta\n");
	printf("Chiave: ");
	scanf("%s", tmp_chiave);


	while(strlen(tmp_chiave)<=0){
		printf("La chiave deve avere al piu' (maggiore di 0) la lunghezza della stringa da cifrare\n");
		printf("Se la chiave e' piu' grande verra' troncata. Se la chiave e' piu' piccola verra' ripetuta\n");
		printf("Chiave: ");
		scanf("%s", tmp_chiave);
	}

	chiave=malloc(strlen(tmp_chiave) * sizeof(char));
	strcpy(chiave,tmp_chiave);
	free(tmp_chiave);

	printf("Ecco la stringa cifrata con il cifrario di Vigenere\n");

	cifraStringa(stringa, chiave);
	printf("Stringa cifrata: %s",stringa);
}


void cifraStringa(char* stringa, char* chiave){
	int s= strlen(stringa);
	int c= strlen(chiave);
	int i=0;
	int j=0;
	int tmp;

	for(i=0,j=0;i<s;i++,j++){
		if(j==c)
			j=0;
		tmp=chiave[j]-97;
		stringa[i]+=tmp;

		if(stringa[i]>122){
			int x=stringa[i]-123;
			stringa[i]=97+x;
		}
	}


}




int stringaCorretta(char* stringa){
	int i=0;
	int l = strlen(stringa);
	for(i=0; i<l;i++)
		if(stringa[i]<97 || stringa[i]>122)
			return 0;

	return 1;
}