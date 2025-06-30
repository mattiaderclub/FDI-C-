#include <stdio.h>

/*Funzione di supporto*/
float cambioPrezzo(float p, int s);

/*Programma che letto un valore prezzo e un valore sconto da tastiera
 *utilizza una funzione ausiliaria per calcolare il nuovo prezzo scontato*/
int main(){
	//Dichiarazione variabili
	float prezzo;
	int sconto;
	/*INPUT*/
	printf("\nQuanto costa l'articolo?\n");
	scanf("%5.2f", &prezzo);
	printf("Quanto %c scontato?\n", 138);
	scanf("%2d", &sconto);
	/*OUTPUT*/
	float risparmiato = prezzo - cambioPrezzo(prezzo, sconto);
	printf("\nIl tuo articolo scontato viene a costare %.2f$.\n ", cambioPrezzo(prezzo, sconto));
	printf("Hai risparmiato %.2f$.\n\n", risparmiato);
}

/*Funzione che calcola il nuovo prezzo di un articolo dato lo sconto*/
float cambioPrezzo(float p, int s){
	float sconto;
	float risultato;
	sconto = p*s/100;			//proporzione per calcolare lo sconto
	risultato = p - sconto;		//nuovo prezzo
	return risultato;			//valore di ritorno
}