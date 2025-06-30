#include <stdio.h>
#include <string.h>
/* Programma che legge una stringa di caratteri da tastiera e per ogni blocco
 * di esattamente due caratteri numerici consecutivi, moltiplica i numeri e sostituisce
 * il risultato nella stringa */
/* Funzione di supporto */
void prodottoDueNumerici(char* stringa);

/* Funzione principale */
int main(){
	/* Input */
	char stringa[50];
	printf("\nIntroduci una stringa: ");
	fgets(stringa, 50, stdin);

	/* Rimuovi \n */
	stringa[strlen(stringa)-1] = '\0';

	/* Modifico la stringa */
	prodottoDueNumerici(stringa);
	/* Output */
	printf("\nEcco la stringa modificata: %s\n\n", stringa);
}

void prodottoDueNumerici(char* stringa){
	int i, j;			// Contatori
	int prodotto;
	i = 0;


	/* Leggo stringa fino all'ultimo carattere */
	while(stringa[i]!='\0'){
		/* Il primo carattere è numerico ? */
		if(stringa[i]>='0' && stringa[i]<='9'){
			/* Controllo se anche il secondo è numerico */
			if(stringa[i+1]>='0' && stringa[i+1]<='9'){

				/* Ho bisogno che il terzo non sia numerico per sommare i numeri tra loro */
				if(!(stringa[i+2]>='0' && stringa[i+2]<='9')){
					/* Moltiplico trasformando i caratteri negli interi corrispondenti */
					prodotto = (stringa[i] - '0')*(stringa[i+1] - '0');
					/* Il prodotto è minore di 10 */
					if(prodotto<10){
						stringa[i] = prodotto + '0';
						j = i+1;
						while(stringa[j]!='\0'){
							stringa[j] = stringa[j+1];
							j++;
						}
					}
					else{
						/* Posizono le cifre nella stringa */
						stringa[i] = prodotto/10 + '0';
						stringa[i+1] = prodotto%10 + '0';
					}
					i++;
				}
				else
					while(stringa[i]>='0' && stringa[i]<='9')
						i++;		// Passo al carattere successivo finchè è numerico
			}
			else
				i++;			// Passo al carattere successivo
		}
		else
			i++;			// Passo al carattere successivo
	}
}