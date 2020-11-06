#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM_MAX 50
#define __ERROR_DIV_CERO -1


void titulo(char * tit);
void mostrarMenu();
char seleccionarOpcion();
void ingresarDatos(float *, float *, char *);
float realizarCalculos(float *, float *, char *);
void guardarDatos(float *, float *, char *, float *, float *, char *);
void mostrarDatos(float *, float *, char *);
