#include <stdio.h>
#include <string.h>

/* COMMENTO PROF: In questa soluzione quando si trova un carattere "interessante", si verifica
 * se il successivo è pure lui interessante e quello dopo no. Se la verifica ha successo si cancella,
 * altrimenti si superano tutti i caratteri interessanti con un ciclo. Questa seconda operazione
 * è necessaria per evitare di cancellare gli ultimi due caratteri di una sequenza lunga più di due */

/* FUNZIONI DI SUPPORTO */
int isChar(char c);
void viaParoleDaDue(char *stringa);
void testViaParoleDaDue();

/* Funzione principale */
int main(){
    /* Input */
    printf("\nCiao utente, sono un programma che legge una stringa e la modifica rimuovendo\n");
    printf("ogni sequenza di esattamente due caratteri alfabetici consecutivi\n\n");
    char stringa[50];
    printf("Introduci una stringa: ");
    fgets(stringa, 50, stdin);

    /* Rimuovi \n */
    stringa[strlen(stringa)-1] = '\0';
    /* Invoca la funzione viaParoleDaDue */
    viaParoleDaDue(stringa);

    /* Output */
    printf("Ecco la stringa trasformata: %s\n\n", stringa);
    /* Fai partire il test */
    testViaParoleDaDue();
}

/* Funzione che controlla se il carattere è alfabetico */
int isChar(char c){
    return (c>='a' && c<='z')||(c>='A' && c<='Z');
}

/* Funzione che riceve come parametro una stringa e la modifica rimuovendo ogni sequenza
 * di esattamente due caratteri alfabetici consecutivi */
void viaParoleDaDue(char *stringa){
    int i, j;           //contatori
    i = 0;
    /* Vai avanti fino alla fine della stringa */
    while(stringa[i]!='\0'){
        /* Se il carattere non è alfabetico vai avanti */
        if(!isChar(stringa[i])){
            i++;
        }
        else{      //Il carattere corrente è alfabetico
            /* Hai esattamente due caratteri alfabetici consecutivi? */
            if(isChar(stringa[i+1]) && (!isChar(stringa[i+2]))){
                /* Devi cancellare i due caratteri alfabetici */
                for(j=i; stringa[j]|='\0'; j++){
                    stringa[j] = stringa[j+2];
                }
            }
            else{      //Hai più di due caratteri alfabetici consecutivi
                while(isChar(stringa[i])){
                    i++;            //Passa al prossimo elemento
                }
            }
        }
    }
}

/* Funzione di test per viaParoleDaDue */
void testViaParoleDaDue(){

    /* Stringa vuota */
    char stringa1[] = "";
    viaParoleDaDue(stringa1);
    printf("test viaParoleDaDue(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa1);

    /* Stringa senza sequenze di esattamente due caratteri alfabetici */
    char stringa2[] = "12abc34fgh";
    viaParoleDaDue(stringa2);
    printf("test viaParoleDaDue(\"12abc34fgh\"): Atteso = \"12abc34fgh\", Calcolato = \"%s\" \n", stringa2);

    /* Stringa di esattamente due caratteri alfabetici */
    char stringa3[] = "ab";
    viaParoleDaDue(stringa3);
    printf("test viaParoleDaDue(\"ab\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa3);

    /* Stringa con una sola sequenza di esattamente due caratteri alfabetici all'inizio */
    char stringa4[] = "ab123abc";
    viaParoleDaDue(stringa4);
    printf("test viaParoleDaDue(\"ab123abc\"): Atteso = \"123abc\", Calcolato = \"%s\" \n", stringa4);

    /* Stringa con una sola sequenza di esattamente due caratteri alfabetici alla fine */
    char stringa5[] = "abc123ab";
    viaParoleDaDue(stringa5);
    printf("test viaParoleDaDue(\"abc123ab\"): Atteso = \"abc123\", Calcolato = \"%s\" \n", stringa5);

    /* Stringa con una sola sequenza di esattamente due caratteri alfabetici al centro */
    char stringa6[] = "123ab4abc";
    viaParoleDaDue(stringa6);
    printf("test viaParoleDaDue(\"123ab4abc\"): Atteso = \"1234abc\", Calcolato = \"%s\" \n", stringa6);

    /* Stringa normale con più sequenze di esattamente due caratteri alfabetci */
    char stringa7[] = "abc4ab45de6g;ju";
    viaParoleDaDue(stringa7);
    printf("test viaParoleDaDue(\"abc4ab45de6g;ju\"): Atteso = \"abc4456g;\", Calcolato = \"%s\" \n", stringa7);
}