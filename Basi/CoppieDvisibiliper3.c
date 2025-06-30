#include <stdio.h>

int main(){
	int i, j;
	int n;
	
	printf("Inserisci un intero maggiore di 1, per favore.\n");
	scanf("%d", &n);

	printf("Ecco le tue coppie.\n");

	for(i=1; i<=n; i++){
		printf("Coppie il cui primo elemento %c %d: ", 138, i);
		for(j=1; j<=n; j++){
			
			if((i+j)%3==0 && i<=j)
			printf("(%d,%d) ", i, j);
		}
		printf("\n");	
	}
}