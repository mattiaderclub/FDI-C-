#include <stdio.h>

int main(){
	int x, y, z;
	int max = x;
	int min = x;

	printf("Introdurre tre interi: ");
	scanf("%d%d%d", &x, &y, &z);

	if(x>y && x>z){
		max = x;
		if(y>z)
			min = z;
		else
			min = y;
	}
	else if(x>y && x<z){
		max = z;
		min = y;
	}
	else if(x<y && x<z){
		min = x;
		if(y>z)
			max = y;
		else
			max = z;
	}
	printf("Massimo = %d\n", max);
	printf("Minimo = %d\n", min);
}