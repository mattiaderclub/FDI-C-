/* Funzione che legge il contenuto di un file e lo inserisci in una lista */
void leggiDaFile(N **crea) {
	*crea = NULL;					// Inizializzo la testa
	/* Apro file in lettura */
	FILE *fpin = fopen("Menu'.txt", "r");
	/* Apertura file non andata a buon fine */
	if (fpin == NULL) {
		printf("\nFile inesistente o apertura fallita...\n");
	}
	/* File aperto */
	else {
		F piatto;				// Variabile per appoggiarsi in lettura

		/* Leggo primo nodo se è presente qualcosa nel file */
		if (fscanf(fpin, "%[^\n]%*c%f%*c%c%*c", &piatto.nome, &piatto.prezzo, &piatto.tipo) > 0) {
			N *nuovo = malloc(sizeof(N));			// Alloco nodo nell'heap
			nuovo->fritto = piatto;					// Inserisco valori letti nel nodo
			*crea = nuovo;							// Collego nodo alla testa (doppio puntatore modifica automaticamente nel main)

			/* Leggo finchè c'è qualcosa da leggere */
			while (fscanf(fpin, "%[^\n]%*c%f%*c%c%*c", &piatto.nome, &piatto.prezzo, &piatto.tipo) > 0) {
				
				/* Ho qualcosa da leggere : alloco memoria nel nodo successivo, mi sposto nella lista
				 * e memorizzo ciò che ho letto nel contenuto del nodo corrente */
				nuovo->next = malloc(sizeof(N));
				nuovo = nuovo->next;
				nuovo->fritto = piatto;
			}
			nuovo->next = NULL;			// Fine lista : coda punta NULL
			printf("\nLettura effettuata...	\n");
		}
		/* Nulla nel file */
		else
			printf("\nFile vuoto...\n");
		/* Chiusura file di lettura */
		fclose(fpin);
	}
}