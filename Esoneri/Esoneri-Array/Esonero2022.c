#include <stdio.h>

/* Progettare un algoritmo per risolvere il seguente problema. 
 * Data una sequenza di interi,verificare se esistono tre elementi 
 * adiacenti nella sequenza tali che due dei tre elementi sono 
 * divisibili per il terzo. Ad esempio, la sequenza [3, 4, 2, 8, 9] 
 * è un’istanza positiva del problema, in quanto esistono tre elementi 
 * adiacenti nella sequenza (4, 2, 8) tali che due dei tre elementi 
 * (4 e 8) sono divisibili per il terzo (2). La sequenza [4, 8, 6] è invece
 * un’istanza negativa del problema, in quanto, nell’unica tripla di 
 * elementi adiacenti, 4 e 8 non sono divisibili per 6, 4 e 6 non sono 
 * divisibili per 8, e 8 e 6 non sono (entrambi) divisibili per 4. */

int dueDivisibiliPerTerzo(int array[], int dimensione);

int main(){
	int lunghezza;
	int i=1;
	int divPerTerzo;

	printf("\nIntroduci la lunghezza: ");
	scanf("%d", &lunghezza);
	printf("\n");

	int sequenza[lunghezza];
	for(i=0; i<lunghezza; i++){
		printf("Aggiungi un valore alla sequenza: ");
		scanf("%d", &sequenza[i]);
	}

	divPerTerzo=dueDivisibiliPerTerzo(sequenza, lunghezza);
	
	if(divPerTerzo){
		printf("\nEsiste un tripla di elementi della sequenza in cui due di loro sono divisibili per il terzo.\n");
	}
	else
		printf("\nNon esiste alcuna tripla di elementi in cui due di loro sono divisibili per il terzo.\n");
}

int dueDivisibiliPerTerzo(int array[], int dimensione){
	int controllo=0;
	for(int i=0; i<dimensione-2; i++){
		if((array[i]%array[i+2]==0 && array[i+1]%array[i+2]==0)||
			(array[i]%array[i+1]==0 && array[i+2]%array[i+1]==0)||
			(array[i+1]%array[i]==0 && array[i+2]%array[i]==0)){

			return controllo=1;
		}
	}
	return controllo;
}