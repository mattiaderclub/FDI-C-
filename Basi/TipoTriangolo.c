#include <stdio.h>

//Programma che dati 3 interi a, b, c li legge e stampa
//un messaggio dove dice di che tipo è

int main(){
	int a, b, c;
	printf("Ciao, dammi 3 lati di un triangolo: ");
	scanf("%d%d%d", &a, &b, &c);

	if(a==b || b==c || a==c){
		if(a==b && b==c && a==c)
			printf("Triangolo equilatero");
		else
			printf("Triangolo isoscele");
	}
	else
		printf("Triangolo scaleno");
}