#include <stdio.h>
#include <string.h>

/* Funzioni di supporto */
void sommaNumeri(char* stringa);
void testSommaNumeri();
int isNumerico(char c);
/* Funzione princiaple */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge una stringa di caratteri e la modifica in modo tale\n");
	printf("che nella stringa compaiano solo i numeri (ovvero le sequenze massimali di caratteri numerici)\n");
	printf("della stringa parametro dove ogni due numeri consecutivi sono separati da un '+'.\n");
	char stringa[50];
    printf("\nIntroduci una stringa: ");
    fgets(stringa, 50, stdin);

    /* Rimuovi \n */
    stringa[strlen(stringa)-1] = '\0';
    /* Invoca la funzione sommaNumeri */
    sommaNumeri(stringa);

    /* Output */
    printf("Ecco la stringa trasformata: %s\n\n", stringa);
    /* Fai partire il test */
    testSommaNumeri();
}

/* Funzione che riceve come parametro una stringa e la modifica così che nella
 * stringa compaiano solo i numeri (ovvero le sequenze massimali di caratteri numerici)
 * della stringa parametro, dove ogni due numeri consecutivi sono separati da un '+' */
void sommaNumeri(char* stringa){
	int i, j;
	i = 0;

	/* Vai avanti fino alla fine della stringa */
	while(stringa[i] != '\0'){
		/* Se il carattere attuale è numerico, vai avanti */
		if(isNumerico(stringa[i]))
			i++;
		else{		// Carattere attuale non numerico
			/* Sostituisci il carattere attuale con uno spazio solo se il prossimo
			 * è numerico e quello corrente non ha indice 0; altrimenti cancellalo */
			if(i!=0 && isNumerico(stringa[i+1])){
				/* Sostituisci il carattere con uno spazio e poi vai avanti */
				stringa[i] = '+';
				i++;
			}
			else{
				/* Cancellalo */
				for(j=i; stringa[j]!='\0'; j++)
					stringa[j] = stringa[j+1];
			}
		}
	}
}
/* Funzione che stampa un test di correttezza dell'algoritmo */
void testSommaNumeri(){
	
}
/* Funzione che torna 1 se il carattere controllato è numerico, 0 altrimenti */
int isNumerico(char c){
	int numero = 0;
	if(c>='0' && c<='9')
		numero = 1;
	return numero;
}