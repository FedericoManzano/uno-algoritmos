#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include "./matematica.c"



void pbaContinuar() {
    char cont;
    printf("Presione una tecla para continuar ...");
    scanf(" %c", &cont);
}
void pbaPotencia() {
    long num;
    int pot;
    system("clear");
    printf("Ingrese el numero: ");
    scanf(" %ld", &num);
    printf("Ingrese la potencia: ");
    scanf(" %d", &pot);
    printf("\n\n El resultado es: %ld\n\n", potencia(num, pot));
    pbaContinuar();
    
}