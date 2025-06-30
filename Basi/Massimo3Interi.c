#include <stdio.h>

//programma che dati 3 interi ne stampa il massimo
int main(){
	int n1, n2, n3, M;
	printf("Dammi 3 numeri e te ne stampero' il massimo\n");
	scanf("%d%d%d", &n1, &n2, &n3);
	M = n1;
	if(n1>n2)
		if(n1>n3)
			M = n1;
		else
			M = n3;
	else
		if(n2>n3)
			M = n2;
		else
			M = n3;
	printf("Il massimo tra i 3 numeri %c %d", 138, M);
}

