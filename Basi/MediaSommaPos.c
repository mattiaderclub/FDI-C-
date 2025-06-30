#include <stdio.h>

int main(){
	int num;
	int somma = 0;
	int quanti = 0;
	float media;

	do{
		printf("Introduci un intero: ");
		scanf("%d", &num);
		if(num>0){
			somma+=num;
			quanti=quanti+1;
		}
		else{
			somma+=0;
			quanti+=0;
		}
	}	
	while(num>0);

	media = somma/(float)quanti;

	printf("Somma = %d\n", somma);
	printf("Media = %f\n", media);
	printf("Quanti numeri ho contato = %d\n", quanti);

}