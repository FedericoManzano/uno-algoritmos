#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM 100


char mostrarMenu(char opciones[][TAM], const char *mje);
int validarOpcion(char *opciones, char op);
char seleccionarOpcion(char opciones[][TAM], const char * titulo);
