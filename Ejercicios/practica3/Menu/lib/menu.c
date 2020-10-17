#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#define TAM 10



char mostrarMenu(char opciones[][TAM], char * mje) {
    int i;
    char op;
    for(i = 0; i < strlen(opciones[0]); i ++) 
        printf("%c - %s \n", opciones[0][i] , opciones[i + 1]);
    printf("%s",mje);
    scanf(" %c", &op); 
    return op;
}

int validarOpcion(char *opciones, char op) {
    while(*opciones && opciones && *opciones != op) 
        opciones ++;
    return op == *opciones;
}

char seleccionarOpcion(char opciones[][TAM]) {

    char op;
    
    system("clear");
    op =  mostrarMenu(opciones, "Seleccione una opcion: ");
    while(!validarOpcion(opciones[0], toupper(op))) {
       system("clear");
       op =  mostrarMenu(opciones, "(Err) Ingrese de vuelta la opción: ");  
    }

    return toupper(op);
}


