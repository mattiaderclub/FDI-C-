#include <stdio.h>

//Programma che dice quale sia il mese successivo a quello m
//dell'anno a

int main(){
	int mese, anno;
	printf("Caro scegli un mese e un anno: ");
	scanf("%d%d", &mese, &anno);

	if(mese<13 && mese>0){
		if(mese==12){
			mese=1;
			anno++;
			printf("%d/%d", mese, anno);
		}
		else{
			mese++;
			printf("%d/%d", mese, anno);
		}
	}
	else
		printf("Scegli altri interi");
}