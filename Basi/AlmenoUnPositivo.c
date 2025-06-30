#include <stdio.h>

int main(){
	int num; 
	int max = 0;

	do{
		printf("Inserire un valore (0 per terminare): ");
		scanf("%d", &num);
		if(num>0)
			max = num;
	}
	while(num!=0);
	if(max>0)
		printf("Hai introdotto almeno un positivo!\n");
}