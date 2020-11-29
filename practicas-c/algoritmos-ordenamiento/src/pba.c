
#include <pba.h>
#include <utilitarios.h>

void pbaPruebaQuickSort() {
	pbaGenerarPrueba("QuickSort", quicksort);
	pausar();
}



void pbaPruebaSeleccion() {
	pbaGenerarPrueba("Seleccion", seleccion);
	pausar();
}

void pbaPruebaBurbuja() {
	pbaGenerarPrueba("Burbuja", burbuja);
	pausar();
}

void pbaPruebaInsercion() {
	pbaGenerarPrueba("Insercion", insercion);
	pausar();
}


void pbaPruebaShell() {
	pbaGenerarPrueba("Shell", shell);
	pausar();
}

void pbaMenuAlgoritmos(char * tit, t_ord_gen ordenar, t_prueba prueba) {
	char op;
	t_menu menu;
	
	
	char opciones [TAM_MENU][TAM_MENU] = {
		"Pruebas",
		"Enteros",
		"Reales",
		"Caracteres",
		"Salir"
	};
	
	crearMenu(&menu, opciones,"1234S", tit, "Ingrese una opcion del menu", "Err Elija nuevamente", "[]");
	
	do   {
		op = seleccionarOpcion(&menu);
		switch(op) {
			case '1':
					prueba();
				break; 
			case '2':
				 	ordenarGenerico("Ordenar Enteros", 1, ordenar);
					pausar();
				break;
			case '3': 
					ordenarGenerico("Ordenar Reales", 2, ordenar);
					pausar();
				break;
			case '4': 
					ordenarGenerico("Ordenar Caracteres", 3, ordenar);
					pausar();
				break;
		}
	} while(op != 'S');
} 

