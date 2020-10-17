#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "./heather.h"


char mostrarMenu(char opciones[][TAM], const char *mje) {
    int i;
    char op;
    for(i = 0; i < strlen(opciones[0]); i ++) 
        printf("\t\t\t%c - %s \n", opciones[0][i] , opciones[i + 1]);
    printf("\n\n\t\t%s",mje);
    scanf(" %c", &op); 
    return op;
}

int validarOpcion(char *opciones, char op) {
    while(*opciones && opciones && *opciones != op) 
        opciones ++;
    return op == *opciones;
}

char seleccionarOpcion(char opciones[][TAM], const char * titulo) {
    char op;
    system("cls");
    printf("\n\t\t\t\t%s\n\n", titulo);
    op =  mostrarMenu(opciones, "Seleccione una opcion: ");
    while(!validarOpcion(opciones[0], toupper(op))) {
       system("cls");
       op =  mostrarMenu(opciones, "(Err) Ingrese de vuelta la opcion: ");  
    }

    return toupper(op);
}


