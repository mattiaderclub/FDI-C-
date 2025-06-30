#include <stdio.h>
#include <string.h>

/* Programma che consiste di almeno tre funzioni */

/* Funzioni ausiliarie */
void paroleBenSeparate(char* stringa);

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge una stringa da tastiera e la modifica \n");
	printf("in modo tale che nella stringa compaiano solo le parole minuscole separate da '-'.\n");
	char stringa[50];
	printf("\nIntroduci una stringa: ");
	fgets(stringa, 50, stdin);

	/* Rimuovi \n */
	stringa[strlen(stringa)-1] = '\0';
	/* Invoca la funzione e modifica la stringa */
	paroleBenSeparate(stringa);

	/* Output */
	printf("\nEcco la stringa modificata: %s\n\n", stringa);
	/* Stampa test di correttezza della funzione paroleBenSeparate */
}

void paroleBenSeparate(char* stringa){
	int i, j;				// Contatori
	i = 0;

	/* Controlla la stringa fino all'ultimo carattere */
	while(stringa[i]!='\0') {
		if(i==0) {
			if(stringa[i]>='a' && stringa[i]<='z') {
				i++;
			}
			else{
				for(j=i; stringa[j]!='\0'; j++)
					stringa[j] = stringa[j+1];
			}
		}
		else {
			if(stringa[i]>='a' && stringa[i]<='z') {
				i++;
			}
			else {
				stringa[i] = '-';

				if(!(stringa[i+1]>='a' && stringa[i+1]<='z')) {
					for(j = i; stringa[j]!='\0'; j++) {
						stringa[j] = stringa[j+1];
					}
				}
				else
					i++;
			}
		}
	}
}