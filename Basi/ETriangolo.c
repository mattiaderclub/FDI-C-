#include <stdio.h>

//Programma che dati 3 interi dice se possono 
//essere lati di un triangolo

int main(){
	int a, b, c, somma;
	printf("Dammi 3 interi e ti dico se possono\n");
	printf("essere i lati di un triangolo: ");
	scanf("%d%d%d", &a, &b, &c);
	
	if(a>0 && b>0 && c>0){
		if(c<(a+b) && a<(b+c) && b<(a+c))
			printf("I tre interi possono formare un triangolo");
		else
			printf("Dammi altri interi");
	}
	else
		printf("Dammi 3 interi tutti positivi");

}