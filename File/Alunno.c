/* Creare una struct alunno che contiene il nome, il cognome e il voto.
 * Dopo inserire 5 studenti e memorizzarli in un file binario di nome archivio.txt. */

#include <stdio.h>
#include <string.h>

/* Struct alunno */
typedef struct Alunni {
	char nome[20];
	char cognome[20];
	int voto;
	int matricola;
} STUD;

/* Funzione di supporto */
void leggiDati(STUD *alu);

/* Funzione principale */
int main(){
	/* Input */
	STUD alunno[5];
	FILE *fp = fopen("Archivio.txt", "w");
	printf("\nSono un archivio che registra i dati di 5 studenti dell'istituto.\n");

	/* Registro i dati degli studenti */
	for(int i = 0; i <= 4; i++) {
		leggiDati(alunno + i);
		fprintf(fp, "Nome %s , Cognome %s , ", (alunno + i)->nome, (alunno + i)->cognome);
		fprintf(fp, "Voto %d , Matricola %d\n", (alunno + i)->voto, (alunno + i)->matricola);
	}
	/* Chiusura file */
	fclose(fp);
}
	
/* Funzione che riceve un puntatore a struct come parametro e registra i dati delle
 * variabili della struct */
void leggiDati(STUD *alu){
	/* Leggo il nome dello studente da tastiera */
	printf("\nNome alunno : ");
	fgets(alu->nome, 20, stdin);
	alu->nome[strlen(alu->nome) - 1] = '\0';

	/* Leggo il cognome dello studente da tastiera */
	printf("Cognome alunno : ");
	fgets(alu->cognome, 20, stdin);
	alu->cognome[strlen(alu->cognome) - 1] = '\0';

	/* Voto conseguito */
	printf("Voto conseguito : ");
	scanf("%d", &alu->voto);

	/* Codice matricola */
	printf("Codice matricola : ");
	scanf("%d%*c", &alu->matricola);
}



