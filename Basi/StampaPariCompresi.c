#include <stdio.h>

int main(){
	int num1, num2;
	int min, max;
	printf("Dammi gli estremi di un intervallo\n");
	scanf("%d%d", &num1, &num2);

	if(num1<num2){
		min=num1;
		max=num2;
	}
	else{
		min=num2;
		max=num1;
	}

	printf("I pari compresi tra %d e %d sono: ", min, max);

	for(int i=min; i<=max; i++){
		if(i%2==0){
			printf("%d ", i);
			if(i==num1+num2){
				printf("(Questo intero vale quanto la somma tra %d e %d) ", num1, num2);
			}
		}
	}
	printf("\n\n");
}