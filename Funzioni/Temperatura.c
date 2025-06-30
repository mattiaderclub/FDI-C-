#include <stdio.h>

float toKelvin(float t){
	float k;
	k = t + 273.1;
	return k;
}

float toCelsius(float t){
	float c;
	c = (t-32)/((float)9/5);
	return c;
}

float toFahrenheit(float t){
	float f;
	f = 32+(t*(float)9/5);
	return f;
}

int main(){
	float temperatura;		//variabile temperatura
	int misura;				//variabile per scegliere come 

	printf("Scegli in cosa vuoi convertire la tua temperatura: ", 133),
	scanf("%d", &misura);
	printf("\n");
	printf("Introduci un valore temperatura: ");
	scanf("%f", &temperatura);
	printf("\n");

	if(misura==2)
		printf("Fanno %.1f C.\nLa tua temperatura in Kelvin vale %.1f K\n", temperatura, toKelvin(temperatura));
	else if(misura==1)
		printf("Fanno %.1f C.\nLa tua temperatura in Fahrenheit vale %.1f F\n", temperatura, toFahrenheit(temperatura));
	else if(misura==0)
		printf("Fanno %.1f F.\nLa tua temperatura in Celsius vale %.1f C\n", temperatura, toCelsius(temperatura));
	else
		printf("Posso ricevere valori compresi tra 0 e 2\n");

	temperatura = toCelsius(temperatura);
	temperatura = 0;

	printf("Ecco gli equivalenti Fahrenheit dei Celsius da 0 a 100 gradi.\n");

	for(int i=1; i<=10; i++){
		for(int j=1; j<=10; j++){
			printf("%.1f  ", toFahrenheit(temperatura));
			temperatura++;
		}
		printf("\n");
	}
	printf("\n\n");

	temperatura = toFahrenheit(temperatura);
	temperatura = 32;

	printf("Ecco gli equivalenti Celsius dei Fahrenheit da 32 a 212 gradi.\n");

	for(int k=1; k<=18; k++){
		for(int f=1; f<=10; f++){
			printf("%.1f  ", toCelsius(temperatura));
			temperatura++;
		}
		printf("\n");
	}
	printf("\n");
}