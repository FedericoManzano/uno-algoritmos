#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define TAM_MENU 100


typedef struct {
	char opciones [TAM_MENU][TAM_MENU],
	 	 titulo[40],
		 listaOp[TAM_MENU],
		 pedirOpcion[50],
		 opcionErronea[50],
		 decoracion[3];
} t_menu;


void crearMenu(
	t_menu *, 
	char opciones[][TAM_MENU],
	const char *, 
	const char *, 
	const char *, 
	const char *, 
	const char *
);
char seleccionarOpcion(t_menu *);



