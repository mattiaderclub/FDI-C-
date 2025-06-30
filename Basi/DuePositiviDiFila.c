#include <stdio.h>

int main(){
	int a, b;
	int max = 0;

	printf("(0 per terminare)\n");
	printf("Introduci un intero: ");
	scanf("%d", &a);
	printf("Introduci un intero: ");
	scanf("%d", &b);

	do{
		if(b>0){
			if(a>0){
				if(b>a)
					max=b;
				else
					max=a;
			}
		}

		a = b;
		printf("Introduci un intero: ");
		scanf("%d", &b);
	}
	while(a!=0 && b!=0);
	if(max>0)
		printf("Ci sono due valori positivi di fila!\n");
}