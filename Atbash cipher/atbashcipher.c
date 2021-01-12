#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int main()
{
	char tmp_stringa[30];
	char *stringa;

	printf("Il cifrario di Atbash e' un algoritmo di crittografia a sostituzione\n");
	printf("Ogni lettera e' sostituita la corrispondente simmetrica nell'alfabeto\n");
	printf("Vediamo un esempio.\n");
	printf("Se prendo la stringa 'ab' ottengo 'zy'\n");
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

	printf("Ecco la stringa cifrata con il cifrario di Atbash\n");

	cifraStringa(stringa);
	printf("Stringa cifrata: %s",stringa);
}


void cifraStringa(char* stringa){
	int i=0;
	int l = strlen(stringa);
	int _tmp;

	for(i=0; i<l;i++){
		_tmp = stringa[i]-97;
		stringa[i]= 122-_tmp;
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