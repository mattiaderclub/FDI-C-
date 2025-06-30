#include <stdio.h>
#include <string.h>
/* Programma che legge una stringa di caratteri e la modifica
 * rimpiazzando sequenze di almeno due caratteri alfabetici maiuscoli
 * uguali consecutivi con il solo carattere alfabetico maiuscolo */
/* Funzioni di supporto */
void nienteDoppieMaiuscole(char* stringa);

/* Funzione principale */
int main(){
	/* Input */
	char stringa[50];
    printf("\nIntroduci una stringa: ");
    fgets(stringa, 50, stdin);

    /* Rimuovi \n */
    stringa[strlen(stringa)-1] = '\0';
    /* Invoca la funzione nienteDoppieMaiuscole */
    nienteDoppieMaiuscole(stringa);

    /* Output */
    printf("Ecco la stringa trasformata: %s\n\n", stringa);
}

void nienteDoppieMaiuscole(char* stringa){
	int i, j;
	i = 0;

	while(stringa[i]!='\0'){
		/* Controllo se il carattere è alfabetico maiuscolo e se il prossimo
		 * è uguale a esso */*
		if(stringa[i]>='A' && stringa[i]<='Z'){
			if(stringa[i]==stringa[i+1]){
				/* Cancella caratteri */
				j = i+1;
				while(stringa[j]!='\0'){
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
