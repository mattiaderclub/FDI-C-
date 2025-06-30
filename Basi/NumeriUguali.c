#include <stdio.h>

int main(){
	int a, b, c, d;
	
	printf("Introduci quattro valori e te li controllero'\n");
	scanf("%d%d%d%d", &a, &b, &c, &d);

	if(a==b && a==c && a==d && b==c && b==d && c==d)
		printf("Ci sono esattamente 4 numeri uguali tra loro\n");
	else if(a==b && a==c && a!=d && b==c)
		printf("Ci sono esattamente 3 numeri uguali tra loro\n");
	else if(a==b && a!=c && c==d)
		printf("Ci sono esattamente 2 coppie di numeri uguali tra loro\n");
	else if(a==b && a!=c && a!=d && c!=d)
		printf("Ci sono esattamente 2 numeri uguali tra loro\n");
	else if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d)
		printf("Ci sono esattamente 0 numeri uguali tra loro\n");
}