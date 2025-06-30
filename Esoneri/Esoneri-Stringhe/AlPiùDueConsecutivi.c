#include <stdio.h>
#include <string.h>

/* Programma che legge una stringa da tastiera e la modifica così che ogni sequenza
 * di almeno due caratteri consecutivi uguali venga trasformata in una sequenza di
 * esattamente due caratteri consecutivi uguali */

/* Funzioni ausiliarie */
void alPiuDueConsecutivi(char* stringa);

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge una stringa di caratteri e la modifica\n");
	printf("così che ogni sequenza di almeno due caratteri consecutivi uguali venga trasformata\n");
	printf("in una sequenza di esattamente due caratteri consecutivi uguali\n");
	char stringa[50];
    printf("\nIntroduci una stringa: ");
    fgets(stringa, 50, stdin);

    /* Rimuovi \n */
    stringa[strlen(stringa)-1] = '\0';
    /* Invoca la funzione alPiuDueConsecutivi */
    alPiuDueConsecutivi(stringa);

    /* Output */
    printf("Ecco la stringa trasformata: %s\n\n", stringa);
}

/* Funzione che riceve una stringa come parametro e la modifica trasformando sequenze
 * di almeno due caratteri di fila uguali in una sequenza di esattamente due caratteri
 * di fila uguali */
void alPiuDueConsecutivi(char* stringa){
	int i, j;
	i = 0;

	/* Leggo la stringa fino alla fine */
	while(stringa[i]!='\0'){
		/* Controllo se ho un blocco di più di 2 caratteri di fila uguali */
		if(stringa[i]==stringa[i+1] && stringa[i+1]==stringa[i+2]){
			/* Lo trasformo in un sequenza di 2 caratteri */
			j = i+2;
			while(stringa[j]!='\0'){
				stringa[j] = stringa[j+1];
				j++;
			}
		}
		else
			i++;
	}
}
