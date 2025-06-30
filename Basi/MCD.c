#include <stdio.h>

int main(){
	int x, y;
	int r;
	printf("Ciao utente, dammi due interi\n");
	scanf("%d%d", &x, &y);

	if(x<y)
		r = x;
	else
		r = y;

	while(x%r!=0 || y%r!=0)
		r--;

	printf("Ecco il tuo MCD: %d", r);
}