#include <stdio.h>

int contaPos(int interi[], int l){
	int contatore=0;
	
	for(int i=0; i<l; i++){
		if(interi[i]>0)
			contatore++;
	}

	return contatore;
}

int main(){
	int lung;
	int quanti;
	int i, j;

	printf("\nQuanti elementi contiene la tua sequenza? ");
	scanf("%d", &lung);
	printf("\n");

	int sequenza[lung];
	for(i=0; i<lung; i++){
		printf("Aggiungi un valore: ");
		scanf("%d", &sequenza[i]);
	}

	quanti = contaPos(sequenza, lung);
	int nuovaSequenza[quanti];

	j=0;
	for(i=0; i<lung; i++){
		if(sequenza[i]>0){
			nuovaSequenza[j] = sequenza[i];
			j++;
		}
	}
	printf("Ecco la nuova sequenza: ");
	for(i=0; i<quanti; i++)
		printf("%d ",nuovaSequenza[i]);

	printf("\n");
}