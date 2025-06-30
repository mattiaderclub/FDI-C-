/* Virtualizzazione di un magazzino di un negozio d'abbigliamento.
 * Descrizione del programma:
 * L'utente controlla il magazzino di un negozio attraverso un array di struct. Attraverso un ciclio while, a ogni passo iterativo
 * comunica al compilatore attraverso la lettura di un valore booleano "aggiungi" da tastiera la volontà di aggiungere un elemento
 * al magazzino o meno. Il ciclo si conclude al riempimento dell'array o in caso di inserimento di un valore negativo in "aggiungi"
 * 
 * Uscito dal while, continua l'interazione utente - compilatore in un ciclo di lettura di caratteri.
 * Ogni carattere è associato a una funzionalità diversa del programma tra le seguenti:
 *
 * Terminare il programma stampando la lista di elementi memorizzati
 * Stampare a schermo un reminder della funzionalità che è possibile "scegliere" con i rispettivi comandi associati
 * Registrare un nuovo capo d'abbigliamento nel sistema
 * Rimuovere un capo d'abbigliamento memorizzato nel sistema
 * Sostituire un capo d'abbigliamento salvato con un altro 
 * Ordinare la lista di elementi per prezzo, quantità di capi, ordine alfabetico
 * Stampare la lista di elementi
 * Stampare il valore del prezzo totale del magazzino
 * Stampare il valore della quantità totale di pezzi d'abbigliamento contenuti nel magazzino
 */

/* Il programma sfrutta il meccanismo delle struct (array) e degli algoritmi di ordinamento */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Definizione del tipo SHOP */
typedef struct Negozio {
	char nome[30];				// Identificativo capo d'abbigliamento
	char taglia[3];				// Taglia item (può essere anche una sequenza di caratteri numerici)
	float prezzo; 				// Prezzo item
	int quanti;					// Quantità di capi di quel tipo
} SHOP;

/* Dichiarazione funzioni secondarie */
void introduzione();
void helpReminder();
void leggiDati(SHOP *abb);
void scambia(SHOP *array, int i, int j);
void ordinaPrezzo(SHOP array[], int lung);
void prezzoTot(SHOP *array, int l);
void ordinaQuanti(SHOP array[], int lung);
void quantiTot(SHOP *array, int l);
int codiceChar(char c);
void stampaLista(SHOP *array, int n);

/* Funzione principale */
int main(){
	/* Allocazione di memoria iniziale attraverso la lettura di un valore memoria */
	int memoria;
	printf("\nMemoria da allocare: ");
	scanf("%d", &memoria);

	SHOP *abbigliamento = (SHOP *)malloc(memoria * (sizeof(SHOP)));		// Allocazione memoria per un array dinamico di struct

	/* Allocazione di memoria non andata a buon fine */
	if (abbigliamento == NULL)
		printf("\nAllocazione di memoria non riuscita, riprovare.\n");
	/* Allocazione di memoria andata a buon fine */
	else {
		/* Descrizione del programma */
		introduzione();

		/* Input */
		int i = 0;								// Contatore
		int aggiungi = 1;						// Variabile booleana per inserimento dati struct

		/* Aggiungo elementi al magazzino */
		/* Il ciclo si arresta al raggiungimento della capienza massima o alla lettura di una risposta negativa */
		while (i < memoria && aggiungi) {
			/* L'utente interagisce con il compilatore e decice se aggiungere elementi alla lista */
			printf("\nVuoi aggiungere un nuovo capo alla lista?\n");
			scanf("%d%*c", &aggiungi);
			if(aggiungi) {
				leggiDati(abbigliamento + i);		// Aggiungo elemento alla lista
				i++;								// Passo all'elemento successivo
			}
		}

		/* Memoria piena */
		if (i == memoria && aggiungi) {
			/* Chiede all'utente se ha intenzione di incrementare la memoria dell'array dinamico */
			printf("\nHai intenzione di incrementare la memoria ? ");
			scanf("%d", &aggiungi);

			/* Vogliamo incrementare la memoria */
			if(aggiungi) {
				int boost;				// Memoria aggiuntiva inserita da tastiera
				printf("\nQuante celle di memoria vuoi aggiungere? ");
				scanf("%d", &boost);

				/* Aggiorno la variabile memoria */
				memoria += boost;
				/* Rialloco altra memoria */
				abbigliamento = (SHOP *)realloc(abbigliamento, memoria * (sizeof(SHOP)));

				/* Riallocazione memoria non andata a buon fine */
				if(abbigliamento == NULL) {
					printf("\nMemoria non incrementata, riprovare.\n");
				}
				/* Riallocazione memoria riuscita */
				else {
					/* Richiamo il ciclo per memorizzare i valori con il meccanismo dell'interazione */
					while (i < memoria && aggiungi) {
						/* L'utente interagisce con il compilatore e decice se aggiungere elementi alla lista */
						printf("\nVuoi aggiungere un nuovo capo alla lista?\n");
						scanf("%d%*c", &aggiungi);
						if(aggiungi) {
							leggiDati(abbigliamento + i);		// Aggiungo elemento alla lista
							i++;								// Passo all'elemento successivo
						}
					}			
				}
			}
		}
		/* Elementi memorizzati: come voglio usarli ? */
		char codice = '5';

		/* Ciclo while di lettura codici che richiama tutte le funzioni secondarie */
		while (codiceChar(codice)) {
			printf("\nInserisci un codice comando: ");
			scanf("%c%*c", &codice);

			/* Ogni codice ha una funzione del programma assegnata */
			if (codice == '1') 
				helpReminder();
			if (codice == '2')
				stampaLista(abbigliamento, i);
			if (codice == '3')
				prezzoTot(abbigliamento, i);
			if (codice == '4')
				quantiTot(abbigliamento, i);
			if (codice == 'A') {
				/* Controlla se è necessario incrementare lo spazio in memoria */
				if (i == memoria) {
					memoria++;						// Aggiungo uno spazio alla memoria
					abbigliamento = (SHOP *)realloc(abbigliamento, memoria * (sizeof(SHOP)));			// Incremento memoria

					if(abbigliamento == NULL)
						printf("\nNon %c possibile aggiungere articoli alla lista!\n", 138);

					/* Senza interazione utente - compilatore, la scelta è stata fatta inserendo il codice 'A' */
					else {
						leggiDati(abbigliamento + i);
						i++;
					}
				}
				/* Spazio presente in memoria */
				else {
					leggiDati(abbigliamento + i);
					i++;
				}
			}
			if (codice == 'B') {
				int posizione;				// Variabile posto da scambiare
				printf("\nPosizione dell'articolo da sostituire: ");
				scanf("%d%*c", &posizione);

				/* Mi accerto che il valore inserito sia coerente con la memoria presente dell'array */
				if (posizione < 0 || posizione >= memoria) {
					printf("\nERRORE!");
				}
				else {
					printf("\nRegistrazione del nuovo articolo in corso -->\n");
					leggiDati(abbigliamento + posizione);			// Registro il nuovo elemento nel posto scelto
					printf("...Operazione riuscita\n");
				}
			}
			if (codice == 'C')
				stampaLista(abbigliamento, i);		// Completare
			if (codice == 'D')
				stampaLista(abbigliamento, i);		// Completare
			if (codice == 'E')
				ordinaPrezzo(abbigliamento, i);
			if (codice == 'F')
				ordinaQuanti(abbigliamento, i);
		}
		/* Output */
		stampaLista(abbigliamento, i);
	}
	/* Libera l'area di memoria */
	free(abbigliamento);
}

/* -----> Definizione funzioni secondarie <----- */

/* Funzione che stampa a schermo una breve presentazione del programma e delle sue possibili funzionalità */
void introduzione() {
	printf("\nCiao utente, sei a capo del magazzino di un negozio d'abbigliamento.");
	printf("\nPuoi interagire con me e registrare i capi d'abbigliamento da aggiungere al deposito.");
	printf("\nIn seguito puoi accedere alle varie funzionalit%c del sistema inserendo i codici seguenti.", 133);
	helpReminder();
}

/* Funzione di stampa che ricorda tutte le possibili funzionalità del programma con i rispettivi comandi */
/* Può essere richiamata dall'utente durante l'esecuzione del programma */
void helpReminder() {
	printf("\nIstruzioni e codici:\n");
	printf("\n1 - Stampa a schermo un messaggio che ricorda i codici e le funzionalit%c associate all'interno del programma.", 133);
	printf("\n2 - Stampa la lista di elementi.");
	printf("\n3 - Stampa il prezzo totale dei capi del magazzino.");
	printf("\n4 - Stampa il numero totale di pezzi d'abbigliamento contenuti nel magazzino.");
	printf("\n5 - Codice che serve a entrare e/o rimanere nel ciclo di lettura dei codici.");
	printf("\nA - Aggiunge un elemento al magazzino.");
	printf("\nB - Sostituisce un capo d'abbigliamento del magazzino con uno nuovo aggiunto dall'utente.");
	printf("\nC - Elimina un elemento memorizzato dal sistema.");
	printf("\nD - Ordina la lista di elementi in ordine alfabetico.");
	printf("\nE - Ordina la lista di elementi in ordine decrescente di prezzo.");
	printf("\nF - Ordina la lista di elementi in ordine decrescente di quantit%c.\n", 133);	
	printf("\nQualsiasi altro codice inserito fa stampare la lista di elementi memorizzati nell'ordine corrente e fa terminare il programma.\n");
}

/* Funzione che legge da tastiera i dati di un nuovo capo d'abbigliamento */
void leggiDati(SHOP *abb) {
	/* Lettura nome del capo */
	printf("\nNome articolo: ");
	fgets(abb->nome, 30, stdin);
	/* Rimuovi \n */
	abb->nome[strlen(abb->nome) - 1] = '\0';

	/* Lettura stringa taglia del capo */
	printf("Taglia: ");
	fgets(abb->taglia, 3, stdin);
	/* Rimuovi \n */
	abb->taglia[strlen(abb->taglia) - 1] = '\0';

	/* Lettura valore prezzo del vestito */
	printf("Prezzo: ");
	scanf("%f", &abb->prezzo);

	/* Lettura valore quantità del pezzo d'abbigliamento */
	printf("Quantit%c: ", 133);
	scanf("%d%*c", &abb->quanti);
}

/* Funzione che scambia di posto gli elementi di una sequenza.
 * Supporto indispensabile per le funzioni "ordina" */
void scambia(SHOP *array, int i, int j) {
 	SHOP temp = *(array + i);			// Utilizzo variabile temporanea come appoggio
 	*(array + i) = *(array + j);
 	*(array + j) = temp;
}

/* Funzione che riordina la lista di dati in ordine di prezzo (decrescente) */
void ordinaPrezzo(SHOP *articolo, int lung) {
	float minimo;				// Prezzo minimo di un elemento della sequenza
	int indice;					// Variabile per memorizzare il posto

	/* Sfoglio l'array senza controllare l'ultimo elemento (controllo superfluo) */
	for(int i = 0; i <= lung-2; i++) {
		minimo = articolo[i].prezzo;		// Memorizzo a ogni passo del for il nuovo minimo
		indice = i;						// Memorizzo a ogni passo del for l'indice dell'elemento controllato

		/* Parto dall'elemento successivo e confronto tutta la sequenza con il minimo memorizzato
		 * Se entro nell'if significa che devo memorizzare il nuovo minimo e il suo indice per poi
		 * scambiarlo con l'elemento del primo for attraverso la funzione invocata */
		for(int j = i+1; j <= lung-1; j++) {
			/* Confronto minimo memorizzato con il prossimo elemento della sequenza */
			if(minimo > articolo[j].prezzo) {
				minimo = articolo[j].prezzo;
				indice = j;
			}
		}
		/* Invoco la funzione per scambiare gli elementi (riceve gli indici e l'array in input) */
		scambia(articolo, i, indice);
	}
}

/* Funzione che calcola il prezzo totale dei pezzi d'abbigliamento all'interno del magazzino */
void prezzoTot(SHOP *array, int l) {
	float somma = 0;			// Somma prezzi degli elementi memorizzati

	/* Sommo i prezzi di tutti gli elementi dell'array */
	for(int i = 0; i < l; i++)
		somma += (*(array + i)).prezzo;			// Aritmetica puntatori

	/* Output */
	printf("\nPrezzo totale del magazzino: %.2f\n", somma);
}

/* Funzione che riordina la lista di dati in ordine di quantità (decrescente) */
void ordinaQuanti(SHOP *capo, int lung) {
	int minimo;					// Quantità minima di un elemento della sequenza
	int indice;					// Variabile per memorizzare il posto

	/* Sfoglio l'array senza controllare l'ultimo elemento (controllo superfluo) */
	for(int i = 0; i <= lung-2; i++) {
		minimo = capo[i].quanti;			// Salvo il nuovo valore minimo
		indice = i;							// Salvo l'indice del minimo salvato

		/* Parto dall'elemento successivo e confronto tutta la sequenza con il minimo memorizzato
		 * Se entro nell'if significa che devo memorizzare il nuovo minimo e il suo indice per poi
		 * scambiarlo con l'elemento del primo for attraverso la funzione invocata */
		for(int j = i+1; j <= lung-1; j++) {
			/* Confronto minimo memorizzato con il prossimo elemento della sequenza */
			if(minimo > capo[j].quanti) {
				minimo = capo[j].quanti;
				indice = j;
			}
		}
		/* Invoco la funzione per scambiare gli elementi (riceve gli indici e l'array in input) */
		scambia(capo, i, indice);
	}
}

/* Funzione che calcola il numero totale di capi contenuti nel magazzino */
void quantiTot(SHOP *array, int l) {
	int conta = 0;			// Variabile che conta la quantità totale di capi nel magazzino

	/* Sommo le quantità di tutti gli elementi della sequenza */
	for(int i = 0; i < l; i++)
		conta += (array + i)->quanti;			// Aritmetica puntatori

	/* Output */
	printf("\nQuantit%c totale di capi d'abbigliamento: %d\n", 133, conta);
}

/* Funzione che controlla che il codice inserito sia coerente al programma */
int codiceChar(char c) {
	return c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F';
}

/* Funzione che stampa a schermo la lista di dati */
void stampaLista(SHOP *array, int n) {
	for(int i = 0; i < n; i++) {
		printf("Nome: %s , Taglia: %3s , ", (array + i)->nome, (array + i)->taglia);
		printf("Prezzo: %4.2f , Quantit%c: %3d , ", (array + i)->prezzo, 133, (array + i)->quanti);
		printf("Codice prodotto: %d\n", (array + i));
	}
}

/* AGGIORNAMENTI DA FARE:
* Allocazione di memoria per struct per interagire ancora meglio con il compilatore: 
* Liberare memoria di un capo e inserire un altro pezzo d'abbigliamento
* Eliminare capo dal database
* Elementi salvati rimangono memorizzati
* Aumentare lunghezza array di struct

* Elencare a tabella output di stampa della lista dei capi
* Funzione per ordinare capi in ordine alfabetico (dovrebbe esistere funzione stringa apposita)
* Aggiungere altre caratteristiche (tipi, variabili) alla struct
*/