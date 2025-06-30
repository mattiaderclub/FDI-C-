#include <stdio.h>
#include <string.h>

/* Programma che consiste di almeno tre funzioni */
/* Funzioni di supporto */
void occorenzeConsecutive(char* stringa);
void testOccorenzeConsecutive();

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge una stringa da tastiera e stampa un messaggio\n");
	printf("che indica quale carattere ha il maggior numero di occorrenza nella stringa e quante sono.");
	char stringa[50];
	printf("\n\nIntroduci una stringa: "),
	fgets(stringa, 50, stdin);

	/* Rimuovi \n */
	stringa[strlen(stringa)-1] = '\0';
	/* Invoca la funzione che stampa a schermo il messaggio di output */
	occorenzeConsecutive(stringa);
	printf("\n\n");

	/* Stampa test di correttezza della funzione */
	testOccorenzeConsecutive();
}

/* Funzione che riceve come parametro una stringa. La funzione stampa un messaggio
 * che indica quale carattere ha il maggior numero di occorrenze consecutive nella
 * stringa e quante sono tali occorrenze */
void occorenzeConsecutive(char* stringa){
	int i, j;				// Contatori
	int quante;				// Contatore delle occorrenze di un carattere
	int contaMax = 1;		// Contatore inizializzato al minimo del numero di occorrenze consecutive
	char carattere;			// Carattere controllato

	i = 0;

	/* Va avanti fino al carattere */
	while(stringa[i]!='\0'){
		/* Il carattere controllato è uguale al prossimo */
		if(stringa[i] == stringa[i+1]){
			/* Se sì memorizzo il numero 2 nel contatore di occorrenze e procedo a contare
			 * quante altre volte si ripete */
			quante = 2;
			j = i+1;
			/* Finchè il carattere è uguale al successivo incremento il contatore e passo avanti */
			while(stringa[j] == stringa[j+1]){
				quante++;
				j++;
			}
			/* Controllo se il contatore di occorrenze consecutive supera il contatore minimo */
			if(quante>contaMax){
				contaMax = quante;			// Memorizzo nuovo valore
				carattere = stringa[j];		// Memorizzo il carattere che sto controllando
			}
			/* Riparto dall'indice j (incrementare sarebbe inutile qualora
			 * ci fosse un gran blocco di caratteri uguali) */
			i = j;
		}
		else
			i++;		// Altrimenti passo al successivo

	}
	if(contaMax!=1){
		printf("Il carattere con il maggior numero di occorrenze consecutive\n");
		printf("%c '%c' che ha %d occorrenze consecutive.", 138, carattere, contaMax);
	}
	else
		printf("O nessun carattere si ripete piu' di una volta di seguito o la stringa %c vuota.", 138);
}

/* Funzione che stampa un test di correttezza della funzione occorrenzeConsecutive
 * Deve realizzare un test a scatola nera prendendo in considerazioni tutti i casi possibili */
void testOccorenzeConsecutive(){
	/* Stringa vuota */
	char stringa1[] = "";
	printf("Test occorenzeConsecutive (\"\"): Atteso = \"O nessun carattere si ripete piu'");
	printf(" di una volta di seguito o la stringa %c vuota.\", Calcolato = \"", 138);
	occorenzeConsecutive(stringa1);
	printf("\"\n\n");

	/* Stringa con solo ripetizioni dello stesso carattere */
	char stringa2[] = "aaaaa";
	printf("Test occorenzeConsecutive (\"aaaaa\"): Atteso = \"Il carattere con il maggior numero di occorrenze consecutive");
	printf(" %c 'a' che ha 5 occorrenze consecutive.\", Calcolato = \"", 138);
	occorenzeConsecutive(stringa2);
	printf("\"\n\n");


	/* Stringa in cui la ripetizione massima è lunga 1 */
	char stringa3[] = "9A67MHI5GC";
	printf("Test occorenzeConsecutive (\"9A67MHI5GC\"): Atteso = \"O nessun carattere si ripete piu'");
	printf(" di una volta di seguito o la stringa %c vuota\", Calcolato = \"", 138);
	occorenzeConsecutive(stringa3);
	printf("\"\n\n");

	/* Stringa con il carattere più ripetuto all'inizio */
	char stringa4[] = "bbb668mmii";
	printf("Test occorenzeConsecutive (\"bbb668mmii\"): Atteso = \"Il carattere con il maggior numero di occorrenze consecutive");
	printf(" %c 'b' che ha 3 occorrenze consecutive.\", Calcolato = \"", 138);
	occorenzeConsecutive(stringa4);
	printf("\"\n\n");

	/* Stringa con il carattere più ripetuto alla fine */
	char stringa5[] = "mmkk9344oooo";
	printf("Test occorenzeConsecutive (\"mmkk9344oooo\"): Atteso = \"Il carattere con il maggior numero di occorrenze consecutive");
	printf(" %c 'o' che ha 4 occorrenze consecutive.\", Calcolato = \"", 138);
	occorenzeConsecutive(stringa5);
	printf("\"\n\n");

	/* Stringa con il carattere più ripetuto in mezzo */
	char stringa6[] = "aas3333pp00";
	printf("Test occorenzeConsecutive (\"aas3333pp00\"): Atteso = \"Il carattere con il maggior numero di occorrenze consecutive");
	printf(" %c '3' che ha 4 occorrenze consecutive.\", Calcolato = \"", 138);
	occorenzeConsecutive(stringa6);
	printf("\"\n\n");

	/* Stringa con diverse ripetizioni lunga */
	char stringa7[] = "aaGGGGG669bcddddff";
	printf("Test occorenzeConsecutive (\"aaGGGGG669bcddddff\"): Atteso = \"Il carattere con il maggior numero di occorrenze consecutive");
	printf(" %c 'G' che ha 5 occorrenze consecutive.\", Calcolato = \"", 138);
	occorenzeConsecutive(stringa7);
	printf("\"\n\n");
}