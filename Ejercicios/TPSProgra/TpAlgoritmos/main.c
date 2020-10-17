#include <stdio.h>
#include <stdlib.h>

#include "./heather.h"


int comp(const void *e1, const void *e2) {
	int *ele1 = (int *)e1;
	int *ele2 = (int *)e2;
	return *ele2 - *ele1;
}

int main(int argc, char *argv[]) {

	char op;
    
    char opciones[][TAM] = {
        "123456789ABCDETS",
        "Potencia",
        "Intercambiados",
        "Areas",
        "Es Par",
        "Media",
        "Negativo",
        "Edades",
        "Sueldos",
        "Sueldos2",
        "Multiplos de 5",
        "Pares hasta 200",
        "Factorial",
        "Es primo",
        "Anteriores",
        "Calculadora",
        "Salir"
    } ;

    do {
        op = seleccionarOpcion(opciones, "TP 3 Algoritmos");
        switch(op) {
            case '1': 
              	pbaPotencia();
            break;
            case '2': 
              	pbaPedirValores();
            break;
            case '3': 
              	pbaAreas();
            break;
            case '4': 
              	pbaEsPar();
            break;
            case '5': 
              	pbaMedia();
            break;
            case '6': 
              	pbaNegativo();
            break;
            case '7': 
              	pbaEdades();
            break;
            case '8': 
              	pbaEmpleado();
            break;
            case '9': 
              	pbaSalario();
            break;
            case 'A': 
              	pbaMultiplos5();
            break;
            case 'B': 
              	pbaPares200();
            break;
            case 'C': 
              	pbaFactorial();
            break;
            case 'D': 
              	pbaPrimo();
            break;
            case 'E': 
              	pbaAntSig();
            break;
            case 'T': 
              	pbaCalculadora();
            break;
        }
    }while(op != 'S');
    return 0;
}
