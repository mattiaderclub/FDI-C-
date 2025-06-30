#include <stdio.h>
#include <string.h>

/* Programma che consiste di almeno tre funzioni */

/* Funzioni ausiliarie */
void soloNumeri(char* stringa);
void testSoloNumeri();

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge una stringa da tastiera e la modifica \n");
	printf("in modo tale che nella stringa compaiano solo i numeri separati da un singolo spazio.\n");
	char stringa[50];
	printf("\nIntroduci una stringa: ");
	fgets(stringa, 50, stdin);

	/* Rimuovi \n */
	stringa[strlen(stringa)-1] = '\0';
	/* Invoca la funzione e modifica la stringa */
	soloNumeri(stringa);

	/* Output */
	printf("\nEcco la stringa modificata: %s\n\n", stringa);
	/* Stampa test di correttezza della funzione paroleBenSeparate */
	testSoloNumeri();
}

void soloNumeri(char* stringa){
	int i, j;
	i = 0;

	while(stringa[i]!='\0'){
		if(i==0){
			if(stringa[i]>='0' && stringa[i]<='9')
				i++;
			else {
				j = i;
				while(stringa[j]!='\0') {
					stringa[j] = stringa[j+1];
				}
			}
		}
		else {
			if(stringa[i]>='0' && stringa[i]<='9')
				i++;
			else {
				stringa[i] = ' ';

				if(stringa[i+1]>='0' && stringa[i+1]<='9')
					i++;
				else {
					for(j=i; stringa[j]!='\0'; j++)
						stringa[j] = stringa[j+1];
				}
			}
		}
	}
}

void testSoloNumeri(){

}