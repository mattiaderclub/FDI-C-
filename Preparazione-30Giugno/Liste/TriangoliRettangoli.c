/* Realizzare un'applicazione per gestire una lista di triangoli rettangoli che hanno i cateti paralleli agli assi coordinati 
 * ed il vertice incidente sull’angolo retto in basso a sinistra. I triangoli sono ordinati all’interno della lista per area 
 * crescente (ovvero il primo triangolo ha un’area non maggiore del secondo, il secondo triangolo ha un’area non maggiore del terzo e così via).

 * L’applicazione deve gestire ciascun triangolo come una struttura con due campi, che rappresentano il vertice in alto a sinistra (as in figura) 
 * ed il vertice in basso a destra (bd in figura) del triangolo. Ciascun vertice deve essere gestito come una struttura con due campi, che 
 * rappresentano le coordinate reali del vertice nel piano.
 
 * La funzione main deve creare una lista di triangoli inizialmente vuota, quindi deve ripetutamente permettere all’utente di inserire un 
 * nuovo triangolo all’interno della lista, in una posizione tale da mantenere l’ordinamento per area crescente dei triangoli nella lista. 
 * Alternativamente, la funzione che inserisce un nuovo triangolo nella lista può inserire il triangolo in una posizione a piacere 
 * (ad esempio in testa alla lista) e quindi invocare una funzione per ordinare la lista per area crescente. 
 * Tale funzione di ordinamento deve essere realizzata dallo studente e può implementare un qualsiasi algoritmo di ordinamento. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Strutture */
/* Struct che gestisce le coordinate di un punto */
typedef struct Coordinate {
	float x;
	float y;
} P;

/* Struct che gestisce le informazioni di un triangolo rettangolo */
typedef struct Triangolo {
	P as;
	P bd;
} T;

/* Struct che gestisce il nodo di una lista */
typedef struct Lista {
	T triRett;
	struct Lista *next;
} N;

/* Funzioni di supporto */
void reminder();
void registra(N *leggi);
float distanza(T *tri);
float perimetro(T *tri);
float area(T *tri);
void inserimentoOrd(N **nodo);
void inserisciTesta(N **nodo);
void stampaTri(T *stampa);
void visualizzaLista(N *elenco);
int precede(T *tri1, T *tri2);
void scambia(N *n1, N *n2);
void ordinaArea(N **triangoli);
void cancellaAreaLetta(N **lista);
void acquisizione(N **elenco);
void salvataggio(N *lista);

/* Corpo del programma */
int main() {
	printf("\nCiao utente, sono un programma che gestisce un elenco di triangoli rettangolo.\n");

	N *triangoli;
	acquisizione(&triangoli);
	int scelta = -1;

	while (scelta != 0) {
		reminder();
		printf("\nInserisci un codice comando : ");
		scanf("%d", &scelta);

		if (scelta == 1)
			inserisciTesta(&triangoli);
		else if (scelta == 2)
			inserimentoOrd(&triangoli);
		else if (scelta == 3)
			ordinaArea(&triangoli);
		else if (scelta == 4)
			visualizzaLista(triangoli);
		else if (scelta == 5)
			cancellaAreaLetta(&triangoli);
	}
	salvataggio(triangoli);
	printf("\nChiusura programma...\n");
}

void reminder() {
	printf("\nCOMANDI:\n");
	printf("\n0 - Termina il programma.");
	printf("\n1 - Inserisci un triangolo in testa alla lista.");
	printf("\n2 - Inserisci un triangolo nell'elenco mantenendo l'ordinamento.");
	printf("\n3 - Ordina la lista di triangoli per valori dell'area crescenti.");
	printf("\n4 - Visualizza la lista corrente di triangoli rettangoli.");
	printf("\n5 - Cancella dalla lista tutti i triangoli che hanno un area minore di un valore letto da tastiera.\n");
}


void registra(N *leggi) {
	printf("\nRegistro i dati del prossimo triangolo rettangolo...\n");

	printf("\nInserisci la coordinata x del vertice alto sinistra : ");
	scanf("%f", &leggi->triRett.as.x);
	printf("Inserisci la coordinata y del vertice alto sinistra : ");
	scanf("%f", &leggi->triRett.as.y);

	do {
		printf("\nInserisci la coordinata x del vertice basso destra : ");
		scanf("%f", &leggi->triRett.bd.x);
		printf("Inserisci la coordinata y del vertice basso destra : ");
		scanf("%f", &leggi->triRett.bd.y);
		if (leggi->triRett.bd.x <= leggi->triRett.as.x || leggi->triRett.as.y <= leggi->triRett.bd.y)
			printf("\nRegistrazione fallita...\n");
	} while (leggi->triRett.bd.x <= leggi->triRett.as.x || leggi->triRett.as.y <= leggi->triRett.bd.y);	

	printf("\nTriangolo registrato...\n");
}


float distanza(T *tri) {
	return sqrt((tri->as.x - tri->bd.x)*(tri->as.x - tri->bd.x) + (tri->as.y - tri->bd.y)*(tri->as.y - tri->bd.y));
}


float perimetro(T *tri) {
	return ((tri->bd.x - tri->as.x) + (tri->as.y - tri->bd.y) + distanza(tri));
}


float area(T *tri) {
	return ((tri->bd.x - tri->as.x)*(tri->as.y - tri->bd.y)/2);
}


void inserimentoOrd(N **nodo) {
	N *nuovo = malloc(sizeof(N));

	registra(nuovo);

	if (*nodo == NULL || area(&nuovo->triRett) < area(&(*nodo)->triRett)) {
		nuovo->next = *nodo;
		*nodo = nuovo;
		printf("Inserimento in testa riuscito...\n");
	}
	else {
		N *check = (*nodo)->next;
		N *prec = *nodo;

		while (check != NULL && area(&nuovo->triRett) >= area(&check->triRett)) {
			prec = check;
			check = check->next;
		}
		prec->next = nuovo;
		nuovo->next = check;
		printf("\nInserimento ordinato effettuato...\n");
	}
}


void inserisciTesta(N **nodo) {
	N *nuovo = malloc(sizeof(N));

	registra(nuovo);
	nuovo->next = *nodo;
	*nodo = nuovo;
	printf("Inserimento in testa riuscito...\n");
}


void stampaTri(T *stampa) {
	printf("\nVertice alto sinistra : (%.2f,%.2f)", stampa->as.x, stampa->as.y);
	printf("\nVertice basso destra : (%.2f,%.2f)", stampa->bd.x, stampa->bd.y);
	printf("\nVertice basso sinistra : (%.2f,%.2f)", stampa->as.x, stampa->bd.y);
	printf("\nPerimetro : %.2f", perimetro(stampa));
	printf("\nArea : %.2f\n", area(stampa));
}


void visualizzaLista(N *elenco) {
	if (elenco == NULL)
		printf("\nLista vuota...\n");
	else {
		printf("\nTRIANGOLI RETTANGOLI:\n");
		printf("\n**********************************\n");
		while (elenco != NULL) {
			stampaTri(&elenco->triRett);
			elenco = elenco->next;
		}
		printf("\n**********************************\n");
	}
}


int precede(T *tri1, T *tri2) {
	return (area(tri1) < area(tri2));
}


void scambia(N *n1, N *n2) {
	T temp = n1->triRett;
	n1->triRett = n2->triRett;
	n2->triRett = temp;
}


void ordinaArea(N **triangoli) {
	if (*triangoli == NULL || (*triangoli)->next == NULL)
		printf("\nNulla da ordinare...\n");
	else {
		N *appoggio = *triangoli;
		N *minimo;
		N *check;

		while (appoggio->next != NULL) {

			minimo = appoggio;
			check = appoggio->next;

			while (check != NULL) {
				if (precede(&check->triRett, &minimo->triRett))
					minimo = check;

				check = check->next;
			}
			scambia(appoggio, minimo);
			appoggio = appoggio->next;
		}
		printf("\nOrdinamento per area crescente riuscito...\n");
	}
}


void cancellaAreaLetta(N **lista) {
	if (*lista == NULL)
		printf("\nLista vuota...\n");
	else {
		float limiteA;
		printf("\nInserisci un valore minimo di area per i triangoli nell'elenco : ");
		scanf("%f", &limiteA);

		while (*lista != NULL && area(&(*lista)->triRett) < limiteA) {
			N *cancella = *lista;
			*lista = (*lista)->next;
			free(cancella);
		}

		if (*lista == NULL) {
			printf("\nTutti i triangoli in lista avevano un'area minore di %.2f\n", limiteA);
			printf("Lista svuotata...\n");
		}

		else {
			N *check = (*lista)->next;
			N *prec = *lista;

			while (check != NULL) {
				if (area(&check->triRett) < limiteA) {
					prec->next = check->next;
					free(check);
					check = prec->next;
				}
				else {
					prec = check;
					check = check->next;
				}
			}
			printf("\nCancellazione multipla per valore effettuata...\n");
		}
	}
}


void salvataggio(N *lista) {
	FILE *salva = fopen("Tri_Rettangoli.dat", "wb");

	if (salva == NULL)
		printf("\nApertura file fallita...\n");
	else {
		while (lista != NULL) {
			fwrite(&lista->triRett, sizeof(T), 1, salva);
			lista = lista->next;
		}
		printf("\nSalvataggio riuscito...");
		fclose(salva);
	}
}


void acquisizione(N **elenco) {
	*elenco = NULL;
	FILE *leggi = fopen("Tri_Rettangoli.dat", "rb");

	if (leggi == NULL)
		printf("\nFile inesistente...\n");
	else {

		T lettura;
		if (fread(&lettura, sizeof(T), 1, leggi) > 0) {

			N *memorizza = malloc(sizeof(N));
			memorizza->triRett = lettura;
			*elenco = memorizza;

			while (fread(&lettura, sizeof(T), 1, leggi) > 0) {

				memorizza->next = malloc(sizeof(N));
				memorizza = memorizza->next;
				memorizza->triRett = lettura;
			}
			printf("\nDati recuperati...\n");
		}
		else
			printf("\nFile vuoto...\n");
		fclose(leggi);
	}
}