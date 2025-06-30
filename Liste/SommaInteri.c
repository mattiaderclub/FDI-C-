/* Programma che setta una lista dinamica di interi e somma gli interi della lista che sono multipli
 * di un certo valore dato in input attraverso un funzione somma che riceve come parametro la testa della lista.
 * Viene tornato -1 se la lista è vuota */

#include <stdio.h>
#include <stdlib.h>

/* Struct per lista che contiene interi */
typedef struct Interi {
	int dato;
	struct Interi *next;
} NODO;

/* Funzioni di supporto */
void inserimentoInTesta(NODO **puntaHead);
int somma(NODO *head);

/* Corpo del programma */
int main() {
	/* Input */
	NODO *head = NULL;
	printf("\nSono un programma che legge una lista di interi e ne ritorna la somma.\n");

	int scelta = 1;

	while(scelta == 1) {
		printf("\nVuoi aggiungere un nuovo valore alla lista ? ");
		scanf("%d", &scelta);

		if(scelta == 1)
			inserimentoInTesta(&head);
	}

	if (somma(head) == -1) {
		printf("\nLista vuota.\n");
	}
	else {
		printf("\nSomma interi della lista: %d", somma(head));
	}
}

/* Funzione che riceve come parametro l'indirizzo della testa della lista e salva interi all'interno della lista */
void inserimentoInTesta(NODO **puntaHead) {
	NODO *nuovoNodo;
	nuovoNodo = malloc(sizeof(NODO));

	printf("Nuovo valore: ");
	scanf("%d", &(nuovoNodo->dato));

	nuovoNodo->next = *puntaHead;
	
	*puntaHead = nuovoNodo;
}

int somma(NODO *head) {
	int s = 0;

	if (head == NULL) {
		s = -1;
	}
	else {
		while (head != NULL) {
			s += head->dato;
			head = head->next;
		}
	}

	return s;
}
