/* SPECIFICA

* Input: n, (x1, x2, ..., xn)
* Pre-condizione: n>=0, (x1, x2, ..., xn) sono interi
* Output: valore booleano ugualiCompresi
* Post-condizione:  ugualiCompresi vale 1 se esiste una tripla di elementi
					consecutivi tale che almeno due elementi delle tripla
					hanno una somma è compresa tra 10 e 20 ed esattamente 
					due elementi della tripla sono fra loro uguali.
*
* TIPO DI PROBLEMA: Verifica esistenziale */

#include <stdio.h>

/* Funzione ausiliaria */
int ugualiCompresi(int seq[], int l);

int main(){
	int dimensione;
	int i;
	int esiste;

	printf("\nQuanti interi vuoi introdurre? ");
	scanf("%d", &dimensione);
	printf("\n");

	int array[dimensione];
	for(i=0; i<dimensione; i++){
		printf("Elemento della sequenza di indice %d ha valore ", i);
		scanf("%d", &array[i]);
	}
	
	esiste=ugualiCompresi(array, dimensione);
	if(esiste){
		printf("\nEsiste una tripla di consecutivi in cui almeno due hanno somma compresa\n"); 
		printf("tra 10 e 20 ed esattamente due elementi della tripla sono fra loro uguali.\n");
	}	
	else{
		printf("\nNon esiste una tripla di consecutivi in cui almeno due hanno somma compresa\n");
		printf("tra 10 e 20 ed esattamente due elementi della tripla sono fra loro uguali.\n");

	}
}

int ugualiCompresi(int seq[], int l){
	int i;
	int controllo=0;
	for(i=0; i<l-2; i++){
		if(((seq[i]==seq[i+1] && seq[i]!=seq[i+2])||
			(seq[i]==seq[i+2] && seq[i]!=seq[i+1])||
			(seq[i+1]==seq[i+2] && seq[i+1]!=seq[i]))
			&&
			((seq[i]+seq[i+1]>=10 && seq[i]+seq[i+1]<=20)||
			(seq[i]+seq[i+2]>=10 && seq[i]+seq[i+2]<=20)||
			(seq[i+2]+seq[i+1]>=10 && seq[i+2]+seq[i+1]<=20))){

			return controllo=1;
		}
	}
	return controllo;
}
