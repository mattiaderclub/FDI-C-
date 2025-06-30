#include <stdio.h>
#include <string.h>

/* Programma che consiste di almeno tre funzioni */

/* Funzioni di supporto */
/* Funzione che riceve come parametro una stringa e la modifica rimuovendo ogni
 * sequenza di esattamente due caratteri numerici uguali consecutivi. */
void cancellaDueNumericiUguali(char* stringa);

/* Funzione che realizza un test a scatola nera per verificare la correttezza
 * della funzione cancellaDueNumericiUguali. Stampa a schermo il test su vari casi */
void testCancellaDueNumericiUguali();

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utnte, sono un programma che legge una stringa da tastiera e la modifica\n");
	printf("rimuovendo ogni sequenza di esattamente due numeri uguali consecutivi.\n");
	char stringa[50];
	printf("\nIntroduci una stringa: ");
	fgets(stringa, 50, stdin);

	/* Rimuovi \n */
	stringa[strlen(stringa)-1] = '\0';
	/* Invoca la funzione per modificare la stringa */
	cancellaDueNumericiUguali(stringa);

	/* Output */
	printf("\nEcco la stringa modificata: %s\n\n", stringa);
	/* Test di correttezza della funzione cancellaDueNumericiUguali */
	testCancellaDueNumericiUguali();
}

void cancellaDueNumericiUguali(char* stringa){
	int i, j;
	i = 0;

	while(stringa[i]!='\0'){
		if(stringa[i]>='0' && stringa[i]<='9'){
			if(stringa[i]==stringa[i+1] && stringa[i+1]!=stringa[i+2]){
				for(j=i; stringa[j]!='\0'; j++)
					stringa[j]=stringa[j+2];
			}
			else
				i++;
		}
		else
			i++;
	}
}

void testCancellaDueNumericiUguali(){
	/* Stringa vuota */
	char stringa1[] = "";
	cancellaDueNumericiUguali(stringa1);
	printf("Test cancellaDueNumericiUguali (\"\"): Atteso = \"\", Calcolato = \"%s\"\n", stringa1);

	/* Stringa senza sequenze di esattamente due numerici uguali */
	char stringa2[] = "aa5550p";
	cancellaDueNumericiUguali(stringa2);
	printf("Test cancellaDueNumericiUguali (\"aa5550p\"): Atteso = \"aa5550p\", Calcolato = \"%s\"\n", stringa2);

	/* Stringa con due caratteri numerici uguali all'inizio */
	char stringa3[] = "22aaa";
	cancellaDueNumericiUguali(stringa3);
	printf("Test cancellaDueNumericiUguali (\"22aaa\"): Atteso = \"aaa\", Calcolato = \"%s\"\n", stringa3);

	/* Stringa con due caratteri numerici uguali alla fine */
	char stringa4[] = "bbb00";
	cancellaDueNumericiUguali(stringa4);
	printf("Test cancellaDueNumericiUguali (\"bbb00\"): Atteso = \"bbb\", Calcolato = \"%s\"\n", stringa4);

	/* Stringa con due caratteri numerici uguali in mezzo */
	char stringa5[] = "aaa55ll";
	cancellaDueNumericiUguali(stringa5);
	printf("Test cancellaDueNumericiUguali (\"aaa55ll\"): Atteso = \"aaall\", Calcolato = \"%s\"\n", stringa5);

	/* Stringa senza numerici */
	char stringa6[] = "aapphh";
	cancellaDueNumericiUguali(stringa6);
	printf("Test cancellaDueNumericiUguali (\"aapphh\"): Atteso = \"aapphh\", Calcolato = \"%s\"\n", stringa6);

	/* Stringa con due caratteri numerici non consecutivi */
	char stringa7[] = "0PP0gg";
	cancellaDueNumericiUguali(stringa7);
	printf("Test cancellaDueNumericiUguali (\"0PP0gg\"): Atteso = \"0PP0gg\", Calcolato = \"%s\"\n", stringa7);

	/* Stringa con solo sequenze di esattamente due numerici uguali */
	char stringa8[] = "33gg55hh66hh77";
	cancellaDueNumericiUguali(stringa8);
	printf("Test cancellaDueNumericiUguali (\"33gg55hh66hh77\"): Atteso = \"gghhhh\", Calcolato = \"%s\"\n", stringa8);

	/* Stringa con più sequenza di caratteri numerici uguali consecutivi */
	char stringa9[] = "11RRR777dd88911222";
	cancellaDueNumericiUguali(stringa9);
	printf("Test cancellaDueNumericiUguali (\"11RRR777dd88911222\"): Atteso = \"RRR777dd9222\", Calcolato = \"%s\"\n", stringa9);
}