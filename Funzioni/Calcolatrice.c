#include <stdio.h>

/*Funzione che verifica che il primo dei valori inseriti sia maggiore del secondo*/
int maggiore(int a, int b){
	int confronto;		//valore booleano
	if(a>b)
		return confronto=1;		//valore di ritorno
	else
		return confronto=0;		//valore di ritorno
}

/*Funzione che calcola il massimo tra due valori inseriti da tastiera*/
int massimo(int x, int y){
	int massimo;		//dichiarazione variabili
	if(maggiore(x,y))	//richiamo funzione maggiore nell'istruzione if
		massimo=x;
	else
		massimo=y;

	return massimo;				//valore di ritorno
}

/*Funzione che calcola il quoziente tra due interi inseriti da tastiera. 
 *Il più grande dei valori viene diviso per il più piccolo, sennò verrebbe sempre 0*/
int quoziente(int a, int b){
	int risultato;		//dichiarazione variabili
	if(a==b)
		risultato=1;
	else{
		if(a>b){
			for(int i=0; i*b<=a; i++)	//ciclo for se primo>secondo valore
				risultato=i;
		}
		else{
			for(int j=0; j*a<=b; j++)	//ciclo for se secondo>primo valore
				risultato=j;
		}
	}
	return risultato;			//valore di ritorno
}

/*Funzione che calcola il resto tra due interi immessi da tastiera. 
 *Come per quella del quoziente viene effettuato un controllo su quale sia il valore più grande*/
int resto(int x, int y){
	int risultato;		//dichiarazione variabili
	if(x==y)
		risultato=0;
	else{
		if(x>y){
			for(int i=0; i*y<=x; i++)
				risultato=(x-i*y);
		}
		else{
			for(int j=0; j*x<=y; j++)
				risultato=(y-j*x);
		}
	return risultato;			//valore di ritorno
	}
}

/*Funzione che controllo che l'intero da tastiera sia pari o meno. Restituisce un valore booleano*/
int isPari(int a){
	int pari;			//valore booleano
	if(a%2==0)
		return pari=1;			//valore di ritorno
	else
		return pari=0;			//valore di ritorno
}

/*Funzione che controlla se l'intero da tastiera può essere il quadrato di un numero positivo*/
int isQuadrato(int b){
	int equadrato;		//valore booleano
	for(int i=0; i*i<=b; i++)
		if(i*i==b)
			equadrato=1;	
		else
			equadrato=0;	
	return equadrato;			//valore di ritorno
}

/*Funzione che prende un intero da tastiera e ne restituisce la radice quadrata intera del parametro*/
int radice(int x){
	int risultato;		//dichiarazione variabili
	for(int i=0; i*i<=x; i++)
		risultato=i;
	return risultato;
}

/*Funzione che controlla se l'intero da tastiera inserito è pari alla somma dei quadrati di due numeri positivi*/
int isSommaQuadrati(int y){
	int verdetto=0;		//valore booleano inizializzato
	int somma=0;		//dichiarazione con inizializzazione
	for(int i=0; i*i<y; i++){
		somma=i*i;
		for(int j=0; j*j<y; j++){
			somma=(i*i+j*j);
			if(somma==y){
				return verdetto=1;	/*ritorna subito il valore di ritorno
									 *in modo tale che si interrompa il for*/
			}
			else
				verdetto=0;
		}
	}
	return verdetto;			//valore di ritorno
}

/*Programma che legge due valori da tastiera e in seguito chiede all'utentenche funzione va eseguita
 *su quei valori leggendo un numero tra 1 e 8 (estremi inclusi) inserito dall'utente.
 *A ogni numero è assegnata una funzione diversa*/
int main(){
	int valore1, valore2;		//variabili
	int scelta;					//può assumere un valore tra 1 e 8

	/*INPUT*/
	printf("Introduci due interi.\n");
	scanf("%d%d", &valore1, &valore2);
	printf("Scegli che funzione vuoi che esegua su questi interi.\n");
	printf("Introduci un numero da 1 da 8: ");
	scanf("%d", &scelta);
	
	/*OUTPUT*/
	if(scelta==1)
		printf("%d %c maggiore di %d? %d\n", valore1, 138, valore2, maggiore(valore1, valore2));
	else if(scelta==2)
		printf("Il massimo tra %d e %d %c %d.\n", valore1, valore2, 138, massimo(valore1, valore2));
	else if(scelta==3)
		printf("Il quoziente della divisione tra %d e %d %c %d.\n", valore1, valore2, 138, quoziente(valore1, valore2));
	else if(scelta==4)
		printf("Il resto della divisione tra %d e %d %c %d.\n", valore1, valore2, 138, resto(valore1, valore2));
	else if(scelta==5){
		printf("%d %c pari? %d\n", valore1, 138, isPari(valore1));
		printf("%d %c pari? %d\n", valore2, 138, isPari(valore2));
	}
	else if(scelta==6){
		printf("%d %c il quadrato di un numero positivo? %d\n", valore1, 138, isQuadrato(valore1));
		printf("%d %c il quadrato di un numero positivo? %d\n", valore2, 138, isQuadrato(valore2));
	}
	else if(scelta==7){
		printf("La radice di %d %c %d.\n", valore1, 138, radice(valore1));
		printf("La radice di %d %c %d.\n", valore2, 138, radice(valore2));
	}
	else if(scelta==8){		
		printf("%d %c pari alla somma dei quadrati di due numeri positivi? %d\n", valore1, 138, isSommaQuadrati(valore1));
		printf("%d %c pari alla somma dei quadrati di due numeri positivi? %d\n", valore2, 138, isSommaQuadrati(valore2));
	}
	else
		printf("Mi serve un numero compreso tra 1 e 8.\n");
}