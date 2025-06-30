#include <stdio.h>

int main(){
	float reali[8];
	float somma=0;
	float media;
	printf("inserisci i valori all'interno delle celle:\n");
	for(int i=0; i<8; i++){
		scanf("%f", &reali[i]);
		somma+=reali[i];
	}
	media = somma/8;

	printf("Hai sommato 8 numeri. La loro somma %c %f.\nLa media %c %f", numero, 138, somma, 138, media);

}