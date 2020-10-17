#include "./include/header.h"


int main(int argc, char *argv[]) {
	
	t_menu menu;
	char op;
	
	
	char opciones[TAM_MENU][TAM_MENU] = {
		"Sumar",
		"Restar",
		"Multiplicar",
		"Dividir",
		"Salir"
	};
	
	
	crearMenu(&menu, opciones, "ARMDS", "CALCULADORA MENU", "Selecciones una opcion", "Err seleccione nuevamente", "<>");
	
	
	do {
		op = seleccionarOpcion(&menu);	
	} while(op != 'S');
	
	
	return 0;
}
