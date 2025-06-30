#include <stdio.h>
#include <string.h>

/* Programma che consiste di almeno tre funzioni */

/* Funzioni di supporto */
void dueMinuscolePerVolta(char* stringa);

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge una stringa da tastiera e la modifica \n");
	printf("in modo tale che ogni sequenza di almeno due caratteri alfabetici minuscoli venga\n");
	printf("trasformata in una sequenza di esattamente due caratteri alfabetici minuscoli.\n");
	char stringa[50];
	printf("\nIntroduci una stringa: ");
	fgets(stringa, 50, stdin);

	/* Rimuovi \n */
	stringa[strlen(stringa)-1] = '\0';
	/* Invoca la funzione e modifica la stringa */
	dueMinuscolePerVolta(stringa);

	/* Output */
	printf("\nEcco la stringa modificata: %s\n\n", stringa);
}

void dueMinuscolePerVolta(char* stringa){
	int i, j;
	i = 0;

	while(stringa[i]!='\0'){
		if(stringa[i]>='a' && stringa[i]<='z') {
			if(stringa[i+1]>='a' && stringa[i+1]<='z' && stringa[i+2]>='a' && stringa[i+2]<='z') {
				j = i+2;
				while(stringa[j]!='\0') {
					stringa[j] = stringa[j+1];
					j++;
				}
			}
			else
				i++;
		}
		else
			i++;
	}
}
