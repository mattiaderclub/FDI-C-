#include <stdio.h>

/* Funzione ausialiaria */
int trasformazione(int seq[], int dimensione);

/* Programma che dato in input un numero binario positivo
 * ne restituisce la decodifica in valore decimale */

int main(){
	int lung;		//lunghezza array
	int i;			//per scandire i cicli
	int valoreDecimale;
	/* INPUT: lunghezza array */
	printf("\nIntroduci un valore lunghezza: ");
	scanf("%d", &lung);
	printf("Introduci una sequenza di '1' o '0':\n\n");
	//Dichiarazione array
	int array[lung];
	/* INPUT: valori */
	for(i=0; i<lung; i++){
		printf("Elemento dell'array di indice %d: ", i);
		scanf("%d", &array[i]);
		//Controllo numero binario
		if(array[i]<0 || array[i]>1){
			printf("Devi introdurre un numero binario!\n\n");
			i--;		//Contatore scende in quanto
						//va reinserito il numero
		}
	}
	/* OUTPUT */
	valoreDecimale = trasformazione(array, lung);
	printf("\nEcco il numero ");
	//Ristampa numero binario
	for(i=0; i<lung; i++){
		printf("%d ", array[lung-1-i]);
	}
	printf("decodificato in base 10: %d\n\n", valoreDecimale);
}

/* Funzione che riceve come parametro un numero binario
 * attraverso un array e ne restituisce il suo valore decimale
 * attraverso un ciclo di potenze del 2 */
int trasformazione(int seq[], int dimensione){
	int potenza;		//variabile per fare potenze del 2
	int somma=0;		//somma potenze
	int j;				//j per scandire ciclo potenze
	int i;				//i per scorrere array

	for(i=0; i<dimensione; i++){
		potenza=1;
		if(seq[i]==1){					//se compare l'1 si entra nel
										//ciclo di potenze in base 2
			for(j=0; j<i; j++){
				potenza*=2;
			}
			somma+=potenza;		//uscito dal for di potenze si somma
								//il risultato a somma
		}
		else
			somma=somma;
	}
	return somma;			//valore di ritorno
}