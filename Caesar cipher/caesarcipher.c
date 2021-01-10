#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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



int main()
{
	char tmp_stringa[30];
	char *stringa;
	int distanza=0;

	printf("Il cifrario di Cesare è un algoritmo di crittografia a sostituzione\n");
	printf("Ogni lettera e' sostituita con un'altra a distanza fissa\n");
	printf("Vediamo un esempio.\n");
	printf("Se prendo la stringa 'ab' e scelgo distanza 3 ottengo 'de'\n");
	printf("Il codice e' ciclico, se prendo la stringa 'yz' e scelgo distanza 3 ottengo 'bc'\n");
	printf("Per semplicità scegliamo l'alfabeto internazionale composto di 26 caratteri minuscoli\n");

	printf("Inserisci la stringa che vuoi cifrare\n");
	printf("Stringa: ");
	scanf("%s",tmp_stringa);


	while(!stringaCorretta(tmp_stringa)){
		printf("Per semplicità scegliamo l'alfabeto internazionale composto di 26 caratteri minuscoli\n");
		printf("Inserisci la stringa che vuoi cifrare\n");
		printf("Stringa: ");
		scanf("%s",tmp_stringa);
	}


	stringa=malloc(strlen(tmp_stringa) * sizeof(char));
	strcpy(stringa,tmp_stringa);
	free(tmp_stringa);

	printf("Inserisci la distanza di cifratura\n");
	printf("Distanza: ");
	scanf("%d", &distanza);

	while(distanza<=0){
		printf("La distanza deve essere positiva\n");
		printf("Distanza: ");
		scanf("%d", &distanza);
	}

	distanza=distanza%26;
	printf("Distanza %d\n",distanza);
	printf("Ecco la stringa cifrata con il cifrario di Cesare\n");

	cifraStringa(stringa, distanza);
	printf("Stringa cifrata: %s",stringa);
}


void cifraStringa(char* stringa, int distanza){
	char *tmp;
	strcpy(tmp, stringa);
	int i=0;
	int l = strlen(tmp);
	int _tmp;

	for(i=0; i<l;i++){
		_tmp = tmp[i]+distanza;
		
		if(_tmp-122>0)
			tmp[i]= 97+(_tmp-122);
		else
			tmp[i]=_tmp;
	}


	strcpy(stringa,tmp);
  	free(tmp);
}

int stringaCorretta(char* stringa){
	int i=0;
	int l = strlen(stringa);
	for(i=0; i<l;i++)
		if(stringa[i]<97 || stringa[i]>122)
			return 0;

	return 1;
}