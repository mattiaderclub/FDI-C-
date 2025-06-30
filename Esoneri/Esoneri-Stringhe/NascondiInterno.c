/* Programma che legge una stringa di caratteri da tastiera */
/* La funzione controlla la stringa e:
 * se incontra un blocco di due caratteri alfabetici uguali consecutivi non fa nulla
 * se il blocco è di tre o più caratteri alfabetici uguali consecutivi lascia il primo
 * e l'ultimo carattere del blocco e inserisce un '-' al centro tra i due
 * eliminando eventuali elementi superflui */

#include <stdio.h>
#include <string.h>
/* Funzione di supporto */
void nascondiInterno(char* stringa);

/* Funzione principale */
int main(){
	/* Input */
	char stringa[50];
	printf("\nIntroduci una stringa: ");
	fgets(stringa, 50, stdin);

	/* Rimuovi \n */
	stringa[strlen(stringa)-1] = '\0';
	/* Invoca la funzione per modificare la stringa */
	nascondiInterno(stringa);

	/* Output */
	printf("\nEcco la stringa modificata: %s\n\n", stringa);
}

void nascondiInterno(char* stringa){
	int i, j;			// Contatori
	i = 0;

	/* Vai avanti fino all'ultimo carattere */
	while(stringa[i]!='\0'){
		/* Il carattere è alfabetico ? */
		if(stringa[i]>='a' && stringa[i]<='z'){
			/* Il successivo è alfabetico / uguale al carattere controllato ? */
			if(stringa[i+1]==stringa[i]){
				/* Ho almeno tre caratteri alfabetici di fila ? */
				if(stringa[i+2]==stringa[i]){
					/* Potrei avere un blocco di caratteri alfabetici */
					if(stringa[i+3]==stringa[i]){

						j = i+1;
						/* Cancelliamo ogni volta il secondo carattere del blocco fino
						 * ad avere un blocco di 3 caratteri per entrare nell'else */
						while(stringa[j]!='\0'){
							stringa[j] = stringa[j+1];
							j++;
						}

					}
					/* Abbiamo un blocco di 3 caratteri che verificano la proprietà:
					 * quello intermedio lo cambiamo con "il carattere interessato" */
					else{
						stringa[i+1] = '-';
						i++;
					}
				}
				else
					i++;		// Non ho 3 caratteri vicini che verificano la proprietà
			}
			else
				i++;
		}
		else
			i++;			// Passa al successivo
	}
}
