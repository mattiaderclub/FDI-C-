#include <stdio.h>
#include <string.h>
/* Programma che legge una stringa di caratteri da tastiera e per ogni blocco
 * di esattamente due caratteri numerici consecutivi, somma i numeri e sostituisce
 * il risultato nella stringa */
/* Funzione di supporto */
void sommaDueNumerici(char* stringa);

/* Funzione principale */
int main(){
	/* Input */
	char stringa[50];
	printf("\nIntroduci una stringa: ");
	fgets(stringa, 50, stdin);

	/* Rimuovi \n */
	stringa[strlen(stringa)-1] = '\0';

	/* Modifico la stringa */
	sommaDueNumerici(stringa);
	/* Output */
	printf("\nEcco la stringa modificata: %s\n\n", stringa);
}

void sommaDueNumerici(char* stringa){
	int i, j;			// Contatori
	int somma;
	i = 0;

	/* Leggo stringa fino all'ultimo carattere */
	while(stringa[i]!='\0'){
		/* Il primo carattere è numerico ? */
		if(stringa[i]>='0' && stringa[i]<='9'){
			/* Controllo se anche il secondo è numerico */
			if(stringa[i+1]>='0' && stringa[i+1]<='9'){

				/* Ho bisogno che il terzo non sia numerico per sommare i numeri tra loro */
				if(!(stringa[i+2]>='0' && stringa[i+2]<='9')){
					/* Sommo trasformando i caratteri negli interi corrispondenti */
					somma = (stringa[i] - '0')+(stringa[i+1] - '0');
					/* Controllo se la somma è <10 */
					if(somma<10){
						stringa[i] = somma + '0';
						j = i+1;
						/* Cancello un carattere */
						while(stringa[j]!='\0'){
							stringa[j] = stringa[j+1];
							j++;
						}
					}
					/* Posiziono la cifre della somma nella stringa */
					else{
						stringa[i] = somma/10 + '0';
						stringa[i+1] = somma%10 + '0';
					}
					i++;
				}
				else
					while(stringa[i]>='0' && stringa[i]<='9')
						i++;		// Passo al carattere successivo finchè il carattere è numerico
			}
			else
				i++;			// Passo al carattere successivo
		}
		else
			i++;			// Passo al carattere successivo
	}
}