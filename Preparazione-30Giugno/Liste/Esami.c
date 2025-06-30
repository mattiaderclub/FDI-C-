#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Strutture */
/* Struct che contiene le informazioni di un esame */
typedef struct Info {
	char nome[20];
	char docente[30];
	int voto;
	char tipo;
} ES;

/* Struct che gestisce il nodo di una lista */
typedef struct Lista {
	ES esame;
	struct Lista *next;
} N;

/* Dichiarazione funzioni di supporto */
void reminder();
void campoDati(N *leggi);
void inserisciInTesta(N **registra);
void stampaEsame(ES *stampa);
void visualizzaLista(N *elenco);
void cancellaCoda(N **head);
void leggiDaBin(N **puntaHead);
void salvaSuBin(N *head);

/* Corpo del programma */
int main() {
	N *esami;
	leggiDaBin(&esami);
	int scelta = -1;

	while (scelta != 0) {
		reminder();
		printf("\nInserisci un codice comando : ");
		scanf("%d%*c", &scelta);

		if (scelta == 1)
			inserisciInTesta(&esami);
		else if (scelta == 2)
			visualizzaLista(esami);
		else if (scelta == 3)
			cancellaCoda(&esami);
	}
	/* Salvo su file binario */
	salvaSuBin(esami);
	/* Chiusura del programma */
	printf("\nChiusura del programma...\n");
}

void reminder() {
	printf("\nCOMANDI:\n");
	printf("\n0 - Termina il programma.");
	printf("\n1 - Inserisci un esame in testa alla lista.");
	printf("\n2 - Visualizza l'elenco corrente degli esami.");
	printf("\n3 - Cancella l'ultimo esame dall'elenco.\n");
}

void campoDati(N *leggi) {
	printf("\nRegistrazione dati...\n");
	printf("\nNome dell'esame : ");
	fgets(leggi->esame.nome, 20, stdin);
	leggi->esame.nome[strlen(leggi->esame.nome) - 1] = '\0';

	printf("Docente : ");
	fgets(leggi->esame.docente, 30, stdin);
	leggi->esame.docente[strlen(leggi->esame.docente) - 1] = '\0';

	do {
		printf("Voto conseguito : ");
		scanf("%d%*c", &leggi->esame.voto);
		if (leggi->esame.voto < 0 || leggi->esame.voto > 33)
			printf("\nRegistrazione fallita: reinserire il dato riguardante il voto...\n");
	} while (leggi->esame.voto < 0 || leggi->esame.voto > 33);

	do {
		printf("Tipo d'esame : ");
		scanf("%c%*c", &leggi->esame.tipo);
		if (leggi->esame.tipo != 'f' && leggi->esame.tipo != 'o')
			printf("\nRegistrazione fallita: reinserire il dato riguardante il tipo...\n");
	} while (leggi->esame.tipo != 'f' && leggi->esame.tipo != 'o');
}

void inserisciInTesta(N **registra) {
	N *nuovo = malloc(sizeof(N));

	campoDati(nuovo);

	nuovo->next = *registra;
	*registra = nuovo;
}

void stampaEsame(ES *stampa) {
	printf("\nNome esame : %s", stampa->nome);
	printf("\nDocente : %s", stampa->docente);
	printf("\nEsito : %d", stampa->voto);
	if (stampa->tipo == 'f')
		printf("\nEsame facoltativo.\n");
	else if (stampa->tipo == 'o')
		printf("\nEsame obbligatorio.\n");
}

void visualizzaLista(N *elenco) {
	if (elenco == NULL)
		printf("\nLista vuota...\n");
	else {
		printf("\nEcco la lista d'esami registrati:\n");
		while (elenco != NULL) {
			stampaEsame(&elenco->esame);
			elenco = elenco->next;
		}
	}
}

void cancellaCoda(N **head) {
	if (*head == NULL)
		printf("\nElenco vuoto...\n");
	else {
		N *check;
		N *prec;

		if ((*head)->next == NULL) {
			check = *head;
			*head = (*head)->next;
			free(check);
			printf("\nUn solo esame in elenco : cancellazione effettuata con successo...\n");
		}
		else {
			check = (*head)->next;
			prec = *head;

			while (check->next != NULL) {
				prec = check;
				check = check->next;
			}
			prec->next = check->next;
			free(check);
			printf("\nCancellazione in coda riuscita...\n");
		}
	}
}

void leggiDaBin(N **puntaHead) {
	*puntaHead = NULL;

	FILE *leggi = fopen("Esami.dat", "rb");

	if (leggi == NULL)
		printf("\nFile inesistente...\n");
	else {
		ES appoggio;
		if (fread(&appoggio, sizeof(ES), 1, leggi) > 0) {
			N *nodo = malloc(sizeof(N));
			nodo->esame = appoggio;
			*puntaHead = nodo;
			while (fread(&appoggio, sizeof(ES), 1, leggi) > 0) {
				nodo->next = malloc(sizeof(N));
				nodo = nodo->next;
				nodo->esame = appoggio;
			}
			nodo->next = NULL;
			printf("\nLettura riuscita, dati recuperati...\n");
		}
		else
			printf("\nFile vuoto...\n");
		fclose(leggi);
	}
}

void salvaSuBin(N *head) {
	FILE *salva = fopen("Esami.dat", "wb");

	if (salva == NULL)
		printf("\nApertura file fallita...\n");
	else {
		while (head != NULL) {
			fwrite(&head->esame, sizeof(ES), 1, salva);
			head = head->next;
		}
		printf("\nSalvataggio effettuato...");
		fclose(salva);
	}
}