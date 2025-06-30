#include <stdio.h>

int main(){
	int x, y;
	int est1, est2;
	int i;

	printf("Introduci gli estremi di un intervallo\n");
	scanf("%d%d", &x, &y);

	if(x>y){
		est1=y;
		est2=x;
	}
	else{
		est1=x;
		est2=y;
	}

	printf("I numeri non divisibili per 3 appartenenti a [%d/%d] sono: ", est1, est2);

	for(i=1; i<=est2; i++){
		if(i%3!=0)
			printf("%d  ", i);
	}
	printf("\n");
}
