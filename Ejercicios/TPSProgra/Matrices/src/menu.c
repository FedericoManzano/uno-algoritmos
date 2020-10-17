
#include "../include/menu.h"


void crearMenu( t_menu *menu, char opciones[][TAM_MENU], const char * listaOp, const char * titulo, const char * pedirOpcion, const char * opcionErronea, const char * decoracion) {
	int i, cantidadOpciones = strlen( listaOp );	
	for( i = 0; i < cantidadOpciones; i ++ ) 
		strcpy(menu->opciones[i], opciones[i]);
		
	strcpy(menu->titulo, titulo);
	strcpy(menu->pedirOpcion, pedirOpcion);
	strcpy(menu->opcionErronea, opcionErronea);
	strcpy(menu->listaOp, listaOp);

	if(decoracion == NULL || !strcmp("", decoracion)) 
		strcpy(menu->decoracion, "()");
	else
		strcpy(menu->decoracion, decoracion);	
}

void mostrarMenu (t_menu *menu) {
	int i;
	int cantidadOpciones = strlen(menu->listaOp);
	
	printf("\n\t\t\t\t%s\n", menu->titulo);
	printf("\t\t\t\t");
	for( i = 0; i <  strlen(menu->titulo); i ++)
		printf("%c", '=');
	printf("\n\n");
	for( i = 0; i < cantidadOpciones; i ++ ) 
		printf("\t\t\t%c %c %c %s\n", 
			menu->decoracion[0], 
			menu->listaOp[i],
			menu->decoracion[1], 
			menu->opciones[i]
		);
}

char seleccionarOpcion(t_menu *menu) {
	char op;
	int val = 0;
	do {
		system("cls");
		mostrarMenu(menu);
		if(val) 
			printf("\n\n\t\t%s: ", menu->opcionErronea);
		else 
			printf("\n\n\t\t%s: ", menu->pedirOpcion);
		fflush(stdin);
		scanf("%c", &op);
		val = 1;
	} while( !strchr(menu->listaOp, toupper(op) ) );
	return toupper(op);
}

