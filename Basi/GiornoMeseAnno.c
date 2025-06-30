#include <stdio.h>

//Programma che dice quale sia il giorno successivo al giorno g 
//del mese m dell'anno a

int main(){
	int g, m, a;
	printf("Caro utente scegli un giorno, un mese e un anno\n");
	scanf("%d%d%d", &g, &m, &a);

	if(g>0 && m>0 && a>0){

		if((m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) && g<32){
			if(g==31 && m==12){
				g=1;
				m=1;
				a++;
				printf("Buon anno nuovo");
			}
			else if(g==31 && m!=12){
				g=1;
				m++;
				printf("%d/%d/%d", g, m, a);
			}
			else if(g!=31){
				g++;
				printf("%d/%d/%d", g, m, a);
			}
		}
		else if(m==2 && g<29){
			if(g==28){
				g=1;
				m++;
				printf("%d/%d/%d", g, m, a);
			}
			else{
				g++;
				printf("%d febbraio %d", g, a);
			}
		}
		else if((m==4 || m==6 || m==9 || m==11) && g<31){
			if(g==30){
				g=1;
				m++;
				printf("%d/%d/%d", g, m, a);
			}
			else{
				g++;
				printf("%d/%d/%d", g, m, a);
			}
		}
		else
			printf("Scegli altri numeri");	
	}
	else
		printf("Numeri negativi");
}


