/* Funzione che rivece in input le variabili giorno, mese e anno e controlla che siano
 * verosimili. Ritorna un valore booleano */
int calendario(int g, int m, int a){
	int corretto = 1;					// Variabile booleana inizializzata a TRUE

	/* Primo controllo : i dati rientrano nel calendario ? */
	if((g > 0 && g < 32) && (m > 0 && m < 13) && a >= 0) {

		/* Controllo i mesi da 30 giorni */
		if(m == 4 || m == 6 || m == 9 || m == 11) {
			if(g == 31) {
				corretto = 0;
			}
		}
		/* Controllo febbraio */
		else if(m == 2) {
			/* Anno bisestile ? (29 g) */
			if(((a%4 == 0) && (a%100 != 0)) || (a%400 == 0)) {
				if(g > 29) {
					corretto = 0;
				}
			}
			/* Anno non bisestile (28 g) */
			else {
				if(g > 28) {
					corretto = 0;
				}
			}
		}
	}
	/* Valori errati : modifico il valore della variabile booleana */
	else
		corretto = 0;

	return corretto;				// Valore di ritorno
}