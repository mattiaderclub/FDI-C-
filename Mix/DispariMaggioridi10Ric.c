/* Programma che sfrutta la ricorsione e gli array dinamici. 
 * Viene inizialmente utilizzata una funzione per allocare la memoria con un valore deciso dall'utente.
 * Vengono quindi letti gli interi in modo tale che l'utente possa interromperne l'inserimento
 * attraverso un istruzione interattiva tra computer e utente. Letta la sequenza, la si passa a una funzione
 * ricorsiva che verifica se in ogni tripla di elementi consecutivi della sequenza esistono
 * esattamente due elementi dispari e un elemento della tripla è maggiore di 10 */
#include <stdio.h>
#include <stdlib.h>

/* Funzioni di supporto */
int ricDispariMaggiore10(int* seq, int lung);
void stampaArray();

/* Funzione principale */
int main(){
    /* Allocazione memoria */
    int *interi = (int *)malloc(10 * (sizeof(int)));            // Array dinamico con memoria per 10 interi

    /* Verifico che l'allocazione di memoria sia andata a buon fine */
    if (interi == NULL)
        printf("\nNon c'%c memoria.\nRIPROVARE.\n", 138);
    /* Allocazione andata a buon fine */
    else {
        /* Input */
        printf("\nSono un programma che legge una sequenza di interi e verifica se in ogni tripla di elementi consecutivi\n");
        printf("della sequenza esistono esattamente due elementi dispari e un elemento della tripla %c maggiore di 10.\n", 138);
        int i = 0;                  // Contatore, Indice
        int numero;                 // Serve a interrompere la lettura di interi

        /* Assegno i valori all'array dinamico con la possibilità di interrompere 
         * il processo di lettura valori inserendo il numero 0 */
        while (i < 10 && numero != 0) {
            printf("\nInserire '0' per interrompere la lettura: ");
            scanf("%d", &numero);

            /* Se non è stato inserito 0, procedo con la lettura del nuovo interi della sequenza */
            if (numero != 0){
                printf("Nuovo intero [%d]: ", i);
                scanf("%d", interi + i);
                i++;                            // Passo al prossimo elemento
            }
        }
        /* Output */
        /* Stampo l'array */
        stampaArray(interi, i);
        /* Stampo l'esito */
        if(ricDispariMaggiore10(interi, i))
            printf("per ogni tripla esistono esattamente due elementi dispari e uno maggiore di 10.\n");
        else
            printf("esiste almeno una tripla di elementi dove o non esiste un elemento maggiore di 10 o non esistono esattamente due elementi dispari.\n");
    }
    /* Libero l'area di memoria utilizzata */
    free (interi);
}

/* Funzione ricorsiva che riceve come parametri un array dinamico e la sua lunghezza.
 * Verifica che in ogni tripla di elementi consecutivi della sequenza siano presenti
 * esattamente due elementi dispari e un elemento maggiore di 10 */
int ricDispariMaggiore10(int* seq, int lung){
    int tutte;          // Variabile booleana

    /* Passo base: ho meno di tre elementi da controllare */
    if (lung < 3)
        tutte = 1;
    /* Passo ricorsivo: controllo se viene verificata la proprietà e richiamo la funzione */
    else {
        tutte = (((*(seq + (lung - 1))%2!=0 && *(seq + (lung - 2))%2!=0 && *(seq + (lung - 3))%2==0) || 
                    (*(seq + (lung - 1))%2!=0 && *(seq + (lung - 2))%2==0 && *(seq + (lung - 3))%2!=0) ||
                    (*(seq + (lung - 1))%2==0 && *(seq + (lung - 2))%2!=0 && *(seq + (lung - 3))%2!=0)) &&
                    (*(seq + (lung - 1))>10 || *(seq + (lung - 2))>10 || *(seq + (lung - 3))>10)) && ricDispariMaggiore10(seq, lung - 1);
    }
    return tutte;           // Valore di ritorno
}

/* Funzione che stampa l'array */
void stampaArray(int* seq, int lung){
    printf("\nAll'interno dell'array {");

    for (int i = 0; i < lung - 1; i++){
        printf("%d,", *(seq + i));
    }
    printf("%d} ", *(seq + (lung - 1)));
}
