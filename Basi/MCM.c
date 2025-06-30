#include <stdio.h>

int main(){
	int x, y;
	int ris;
	
	printf("Inserire due interi maggiori di 0:\n");
	scanf("%d%d", &x, &y);
	
	if(x>0 && y>0){
		
		if(x>y)
			ris=x;
		else
			ris=y;

		while(ris%y!=0 || ris%x!=0)
			ris++;
		printf("mcm = %d\n", ris);
	}
	else
		printf("Almeno un intero inserito %c nullo o negativo!", 138);
}