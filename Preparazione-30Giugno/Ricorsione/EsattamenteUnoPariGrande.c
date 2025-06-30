#include <stdio.h>

/* Funzioni secondarie */
int esattaUnoPariGrande(int s[], int l);

/* Corpo del programma */
int main() {
	printf("\nCiao utente, sono un programma che legge una sequenza di interi da tastiera e verifica se all'interno della sequenza");
	printf("\nogni tripla di elementi consecutivi contiene almeno due interi maggiori o uguali a 10, di cui esattamente uno pari.\n");
	int lung;
	printf("\nInserisci un valore lunghezza : ");
	scanf("%d", &lung);
	printf("Scrivi %d interi.\n\n", lung);

	int array[lung];
	for (int j = 0; j < lung; j++) {
		printf("Elemento di posto %d = ", j);
		scanf("%d", &array[j]);
	}

	if (esattaUnoPariGrande(array, lung))
		printf("\nOgni tripla di elementi adiacenti della sequenza contiene almeno due interi maggiori o uguali a 10, di cui esattamente uno pari.\n");
	else
		printf("\nAlmeno una tripla di elementi adiacenti della sequenza non contiene almeno due interi maggiori o uguali a 10, di cui esattamente uno pari.\n");
	printf("\nChiusura programma...\n");
}


int esattaUnoPariGrande(int s[], int l) {
	int ris;

	if (l < 3)
		ris = 1;
	else {
		ris = ((s[l-1] >= 10 && s[l-2] >= 10) && ((s[l-1]%2 == 0 && s[l-2]%2 != 0) || (s[l-1]%2 != 0 && s[l-2]%2 == 0)) ||
				(s[l-1] >= 10 && s[l-3] >= 10) && ((s[l-1]%2 == 0 && s[l-3]%2 != 0) || (s[l-1]%2 != 0 && s[l-3]%2 == 0)) ||
				(s[l-2] >= 10 && s[l-3] >= 10) && ((s[l-2]%2 == 0 && s[l-3]%2 != 0) || (s[l-2]%2 != 0 && s[l-3]%2 == 0))) && 
				esattaUnoPariGrande(s, l-1);
	}
	return ris;
}