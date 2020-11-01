#include <stdio.h>
#include <stdlib.h>
#include <menu.h>
#include <pba.h>


int main(int argc, char *argv[]) {
	
	t_menu menu;
	char op;
	char opciones[][TAM_MENU] = {
		"Ejercicio 1",
		"Ejercicio 2",
		"Ejercicio 3",
		"Ejercicio 4",
		"Ejercicio 5",
		"Ejercicio 6",
		"Ejercicio 7",
		"Ejercicio 8",
		"Ejercicio 9",
		"Ejercicio 10",
		"Ejercicio 11",
		"Ejercicio 12",
		"Salir"
	};
	
	crearMenu(&menu,opciones,"ABCDEFGHIJKLS","TP 5 Punteros",  "Seleccione una opcion: ", 
					"Err elija nuevamente: ","[]" );
	do {
		op = seleccionarOpcion(&menu);
		switch(op) {
			case 'A': pbaEjercicio1();
				break;
			case 'B': pbaEjercicio2();
				break;
			case 'C': pbaEjercicio3();
				break;
			case 'D': pbaEjercicio4();
				break;
			case 'E': pbaEjercicio5();
				break;
			case 'F': pbaEjercicio6();
				break;
			case 'G': pbaEjercicio7();
				break;
			case 'H': pbaEjercicio8();
				break;
			case 'I': pbaEjercicio9();
				break;
			case 'J': pbaEjercicio10();
				break;
			case 'K': pbaEjercicio11();
				break;
			case 'L': pbaEjercicio12();
				break;
		}
	} while(op != 'S');
	
	titulo("Gracias por usar la app !!!!");
	return 0;
}
