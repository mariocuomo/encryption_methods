#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


typedef struct param{
   int primaLettera;
   int secondaLettera;
   int rigaPrimaLettera;
   int colonnaPrimaLettera;
   int rigaSecondaLettera;
   int colonnaSecondaLettera;
} parametro;


const int matrice[5][5]=
{
    {'e','s','m','p','i'},
    {'o','c','h','a','v'},
    {'b','d','f','g','k'},
    {'l','n','q','r','t'},
    {'u','w','x','y','z'}
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
Funzione per verificare in che condizione mi trovo
1. Se entrambe le lettere sono uguali (o singola), si aggiunga un 'X' dopo la prima lettera
2. Se le due lettere si trovano sulla stessa riga, si sostituiscono con le due lettere che le seguono a destra
3. Se le due lettere sono sulla stessa colonna, si prendono le due lettere sottostanti
4. Si codificano le lettere del digrafo considerando gli angoli opposti del rettangolo definito dalla coppia

Ha in input la struttura con i due valori
Ritorna il numero della condizione
*/
int verificaCondizione();

/*
Funzione per sostituire i caratteri che rispondono alla condizione 2.
Ha in input la struttura con i due valori
*/
void sostituzioneColonna();

/*
Funzione per sostituire i caratteri che rispondono alla condizione 3.
Ha in input la struttura con i due valori
*/
void sostituzioneRiga();

/*
Funzione per sostituire i caratteri che rispondono alla condizione 4.
Ha in input la struttura con i due valori
*/
void sostituzioneDiagonale();

/*
Funzione per sostituire i valori all'interno di una stringa con quelli della matrice
La posizione del valore da copiare si trova nei parametri della strutta passata
*/
void sostituisciValore();

/*
Funzione per verificare se i 2 valori sono presenti nella stessa riga o nella stessa colonna
Ritorna 2 nel caso sono presenti nella stessa riga, ritorna 0 nel caso sono presenti nella stessa colonna
In input riceve i due valori e l'indice della riga/colonn da analizzare
*/
int esistonoIDueValori();

/*
Funzione per modificare i campi della struttura 
   int rigaPrimaLettera;
   int colonnaPrimaLettera;
   int rigaSecondaLettera;
   int colonnaSecondaLettera;
*/
void modificaCampiStruttura();

int main()
{
	char tmp_stringa[30];
	char *stringa;
	printf("Il cifrario di Playfair e' un algoritmo di crittografia effettuando una cifratura simmetrica\n");
	printf("Ogni lettera e' sostituita con un'altra lettera seguendo 4 semplici regole\n");
	printf("Si utilizza una matrice 5x5 inserendo la chiave al suo interno e l'alfabeto eliminando le ripetizioni\n");
	printf("Se si utilizza come chiave 'esempiochiave' la matrice 5x5 e' la seguente\n");

	printf("#  1  2  3  4  5\n");
	printf("1  e  s  m  p  i\n");
	printf("2  o  c  h  a  v\n");
	printf("3  b  d  f  g  k\n");
	printf("4  l  n  q  r  t\n");
	printf("5  u  w  x  y  z\n");

	printf("Si noti come in questo caso si considera i=j in quanto si hanno disponibili solo 25 posizioni\n");
	printf("La prima cosa da fare e' dividere in digrafi la stringa da cifrare\n");
	printf("Le regole da seguire sono le seguenti, considerando ogni digrafo\n");
	printf("1. Se entrambe le lettere sono uguali (o singola), si aggiunga un 'X' dopo la prima lettera.\n");
	printf("2. Se le due lettere si trovano sulla stessa riga, si sostituiscono con le due lettere che le seguono a destra.\n");
	printf("3. Se le due lettere sono sulla stessa colonna, si prendono le due lettere sottostanti.\n");
	printf("4. Si codificano le lettere del digrafo considerando gli angoli opposti del rettangolo definito dalla coppia\n");

	printf("Vediamo un esempio.\n");
	printf("Se prendo la stringa 'ciao come sta' ottengo 'ci ao co me st ai'\n");
	printf("'ci' segue la regola 4 e si traduce con 'vs'\n");
	printf("'ao' segue la regola 2 e si traduce con 'vc'\n");
	printf("'co' segue la regola 2 e si traduce con 'hc'\n");
	printf("'me' segue la regola 2 e si traduce con 'ps'\n");
	printf("'st' segue la regola 4 e ti traduce con 'in'\n");
	printf("'ai' segue la regola 4 e ti traduce con 'vp'\n");

	printf("Inserisci la stringa che vuoi cifrare\n");
	printf("Stringa: ");
	scanf("%s",tmp_stringa);


	while(!stringaCorretta(tmp_stringa)){
		printf("Per semplicita' scegliamo l'alfabeto internazionale composto di 26 caratteri minuscoli\n");
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
	printf("Ecco la stringa cifrata con il cifrario di Playfair\n");
	cifraStringa(stringa);
	printf("Stringa cifrata: %s\n",stringa);
}


void cifraStringa(char* stringa){
	int l=strlen(stringa);
	int condizione=0;

	if(l%2==1){
		realloc(stringa, (l+1)*sizeof(char));
		stringa[l+1]='x';
		l++;
	}

	for(int i=0;i<l-1;i+=2){
		parametro p={0,0, 0, 0, 0, 0};
		p.primaLettera=stringa[i];
		p.secondaLettera=stringa[i+1];
		modificaCampiStruttura(&p);
		//questa variabile mi dice in che situazione delle 4 mi trovo
		/*
		1. Se entrambe le lettere sono uguali (o singola), si aggiunga un 'X' dopo la prima lettera
		2. Se le due lettere si trovano sulla stessa riga, si sostituiscono con le due lettere che le seguono a destra
		3. Se le due lettere sono sulla stessa colonna, si prendono le due lettere sottostanti
		4. Si codificano le lettere del digrafo considerando gli angoli opposti del rettangolo definito dalla coppia\
		*/
		condizione=verificaCondizione(&p);
		switch (condizione){
					case 1: 
						break;
						stringa[i]='x';
						i-=4;
					case 2: 
						sostituzioneColonna(&p);
						sostituisciValore(p,stringa,i);
						break;
					case 3: 
						sostituzioneRiga(&p);
						sostituisciValore(p,stringa,i);
						break;
					case 4: 
						sostituzioneDiagonale(&p);
						sostituisciValore(p,stringa,i);
						break;
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

int verificaCondizione(parametro* p){
	int i=0;
	int tmp=0;

	//condizione 1
	if(p->primaLettera == p->secondaLettera){
		return 1;
	}

	//condizione 2
	for(i=0; i<5;i++){
		tmp=esistonoIDueValori(p->primaLettera, p->secondaLettera,i);
		if(tmp!=0)
			return tmp;
	}

	//condizione 4
	return 4;
}

void sostituzioneRiga(parametro* p){
	p->rigaPrimaLettera++;
	p->rigaSecondaLettera++;

	p->rigaPrimaLettera = (p->rigaPrimaLettera)%5;
	p->rigaSecondaLettera = (p->rigaSecondaLettera)%5;
}

void sostituzioneColonna(parametro* p){
	p->colonnaPrimaLettera++;
	p->colonnaSecondaLettera++;

	p->colonnaPrimaLettera = (p->colonnaPrimaLettera)%5;
	p->colonnaSecondaLettera = (p->colonnaSecondaLettera)%5;
}

void sostituzioneDiagonale(parametro* p){
	int tmpRigaPrimaLettera=p->rigaPrimaLettera;
	int tmpColonnaPrimaLettera=p->colonnaPrimaLettera;

	int tmpRigaSecondaLettera=p->rigaSecondaLettera;
	int tmpColonnaSecondaLettera=p->colonnaSecondaLettera;

	p->colonnaPrimaLettera=tmpColonnaSecondaLettera;
	p->colonnaSecondaLettera=tmpColonnaPrimaLettera;

}

void sostituisciValore(parametro p, char* stringa, int posizione ){
	stringa[posizione]=matrice[p.rigaPrimaLettera][p.colonnaPrimaLettera];
	stringa[posizione+1]=matrice[p.rigaSecondaLettera][p.colonnaSecondaLettera];
}

int esistonoIDueValori(int primaLettera, int secondaLettera, int i){
	int j=0;
	int k=0;

	//verifica di riga
	for(int j=0; j<4;j++)
		for(int k=j+1;k<5;k++){
			if((matrice[i][j]==primaLettera && matrice[i][k]==secondaLettera) || (matrice[i][j]==secondaLettera && matrice[i][k]==primaLettera))
				return 2;
		}

	//verifica di colonna
	for(int j=0; j<4;j++)
		for(int k=j+1;k<5;k++)
			if((matrice[j][i]==primaLettera && matrice[k][i]==secondaLettera) || (matrice[j][i]==secondaLettera && matrice[k][i]==primaLettera) )
				return 3;

	return 0;
}

void modificaCampiStruttura(parametro* p){
	int i=0;
	int j=0;

	for(i=0; i<5;i++)
		for(j=0;j<5;j++){
			if(matrice[i][j]==p->primaLettera){
				p->rigaPrimaLettera=i;
				p->colonnaPrimaLettera=j;
				p->primaLettera=matrice[i][j];
			}
			if(matrice[i][j]==p->secondaLettera){
				p->rigaSecondaLettera=i;
				p->colonnaSecondaLettera=j;
				p->secondaLettera=matrice[i][j];
			}
		}
}