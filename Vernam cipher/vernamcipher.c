#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

const int matrice[26][5]=
{
    {1,1,0,0,0}, //A
    {1,0,0,1,1}, //B
    {0,1,1,1,0}, //C
    {1,0,0,1,0}, //D
    {1,0,0,0,0}, //E
    {1,0,1,1,0}, //F
    {0,1,0,1,1}, //G
    {0,0,1,0,1}, //H
	{0,1,1,0,0}, //I
	{1,1,0,1,0}, //J
	{1,1,1,1,0}, //K
	{0,1,0,0,1}, //L
	{0,0,1,1,1}, //M
	{0,0,1,1,0}, //N
	{0,0,0,1,1}, //O
	{0,1,1,0,1}, //P
	{1,1,1,0,1}, //Q
	{0,1,0,1,0}, //R
	{1,0,1,0,0}, //S
	{0,0,0,0,1}, //T
	{1,1,1,0,0}, //U
	{0,1,1,1,1}, //V
	{1,1,0,0,1}, //W
	{1,0,1,1,1}, //X
	{1,0,1,0,1}, //Y
	{1,0,0,0,1}, //Z
};


//chiave gatto già cifrata con codice Baudot
const int chiave[25]={0,1,0,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1};

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
Funzione per scrivere un carattere in Baudot a partire da una determinata posizione in una stringa
In input è passato per riferimento la stringa, il carattere e la posizione
*/
void copiaConCodiceBaudot();

/*
Funzione per trovare il carattere ASCII associato a uno descritto in Baudot
In input sono passati i 5 bit che lo rappresentano
*/
int convertiDaBaudotAAscii();

int main()
{
	char tmp_stringa[30];
	char *stringa;
	printf("Il cifrario di Vernam e' un algoritmo di crittografia a sostituzione\n");
	printf("La condizione necessaria affinche' sia garantita la sicurezza e' che la chiave ha la stessa lunghezza della parola da cifrare\n");
	printf("Per semplicita' utilizziamo una chiave lunga 5, 'gatto'\n");
	printf("Si effettua l'xOR tra i bit seguendo il codice Baudot\n");
	printf("Ecco la tabella del codice Baudot\n");


	printf("A  1  1  0  0  0\n");
	printf("B  1  0  0  1  1\n");
	printf("C  0  1  1  1  0\n");
	printf("D  1  0  0  1  0\n");
	printf("E  1  0  0  0  0\n");
	printf("F  1  0  1  1  0\n");
	printf("G  0  1  0  1  1\n");
	printf("H  0  0  1  0  1\n");
	printf("I  0  1  1  0  0\n");
	printf("J  1  1  0  1  0\n");
	printf("K  1  1  1  1  0\n");
	printf("L  0  1  0  0  1\n");
	printf("M  0  0  1  1  1\n");
	printf("N  0  0  1  1  0\n");
	printf("O  0  0  0  1  1\n");
	printf("P  0  1  1  0  1\n");
	printf("Q  1  1  1  0  1\n");
	printf("R  0  1  0  1  0\n");
	printf("S  1  0  1  0  0\n");
	printf("T  0  0  0  0  1\n");
	printf("U  1  1  1  0  0\n");
	printf("V  0  1  1  1  1\n");
	printf("W  1  1  0  0  1\n");
	printf("X  1  0  1  1  1\n");
	printf("Y  1  0  1  0  1\n");
	printf("Z  1  0  0  0  1\n");

	printf("Con 5 bit e' possibile effettuare 32 combinazioni\n");
	printf("Le restanti combinazioni rappresentano numeri e caratteri speciali.\n");
	printf("Supponiamo che le restanti combinazioni rappresentino tutte il carattere speciale '0'\n");

	printf("Vediamo un esempio.\n");
	printf("Se prendo la stringa 'pippo' con la chiave 'gatto' ottengo 'nsii0'\n");
	printf("'p' e' tradotto con 01101\n");
	printf("'g' e' tradotto con 01011\n");
	printf("L'xOR tra i due e' '00110' che rappresenta la lettera 'n'\n");
	printf("Le restanti lettere seguono la medesima regola\n");

	printf("Inserisci la stringa che vuoi cifrare\n");
	printf("Stringa: ");
	scanf("%s",tmp_stringa);


	while(!stringaCorretta(tmp_stringa)){
		printf("Per semplicita' scegliamo l'alfabeto internazionale composto di 26 caratteri minuscoli e la lunghezza della stringa e' fissata a 5 caratteri\n");
		printf("Inserisci la stringa che vuoi cifrare\n");
		printf("Stringa: ");
		scanf("%s",tmp_stringa);
	}

	for(int i=0;i<strlen(tmp_stringa);i++)
		if(tmp_stringa[i]=='j')
			tmp_stringa[i]='i';


	stringa=malloc(strlen(tmp_stringa) * sizeof(char));
	strcpy(stringa,tmp_stringa);
	free(tmp_stringa);
	printf("Ecco la stringa cifrata con il cifrario di Vernam\n");
	cifraStringa(stringa);
	stringa[5]='\0';
	printf("Stringa cifrata: %s\n",stringa);
}


void cifraStringa(char* stringa){
	int i=0;
	int j=0;
	int* tmp;
	tmp=malloc(25 * sizeof(int));

	//converti stringa in codice Baudot
	for(i=0;i<25;i=i+5,j++)
		copiaConCodiceBaudot(stringa[j],i,tmp);

	//effettua xor
	for(i=0;i<25;i++)
		if(tmp[i]==chiave[i])
			tmp[i]=0;
		else
			tmp[i]=1;

	//converti in lettere
	for(i=0,j=0;i<26;i=i+5,j++){
		stringa[j]=convertiDaBaudotAAscii(tmp[i],tmp[i+1], tmp[i+2], tmp[i+3], tmp[i+4]);
	}

}

int stringaCorretta(char* stringa){
	if(strlen(stringa)!=5)
		return 0;

	int i=0;
	int l = strlen(stringa);
	for(i=0; i<l;i++)
		if(stringa[i]<97 || stringa[i]>122)
			return 0;

	return 1;
}

void copiaConCodiceBaudot(int lettera, int posizione, int* stringa){
	//rappresenta l'indice della lettera nella matrice
	int indice;
	indice=lettera-97;
	int i=0;
	for(i=0;i<5;i++){
		stringa[posizione+i]=matrice[indice][i];
	}
}

int convertiDaBaudotAAscii(int zero, int uno, int due, int tre, int quattro){
	int i=0;
	for(i=0;i<26;i++){
		if(matrice[i][0]==zero && matrice[i][1]==uno && matrice[i][2]==due && matrice[i][3]==tre && matrice[i][4]==quattro)
			return i+97;
	}
	return '0';
}
