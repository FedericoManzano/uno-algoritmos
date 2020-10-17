
#include "./include/header.h"
#include "./include/pba.h"
#include "./include/menu.h"


int main(int argc, char *argv[]) {
	
	
	t_menu menu;
	char op;

	char opciones[TAM_MENU][TAM_MENU] = {
		"Leer Matriz",
		"Mostrar Matriz",
		"Sumar Matrices",
		"Multiplicar Matrices",
		"Reducir matriz",
		"Diagonal Secundatia",
		"Salir"		
	};
	
	crearMenu(&menu, opciones, "ABCDEFS", "Matrices","Ingrese una opcion", "Err Ingrese nuevamente", "[]");
	
	do {
		op = seleccionarOpcion(&menu);
		switch(op) {
			case 'A': pbaLeer();
				break;
			case 'B': pbaMostrar();
				break;
			case 'C': pbaSumar();
				break;
			case 'D': pbaMultiplicar();
				break;
			case 'E':pbaReducirMatriz(); 
				break;
		}
	}while(op != 'S');
	return 0;
}


