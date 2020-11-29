#include <pba.h>

int main(int argc, char *argv[]) {
	
	char opciones [ TAM_MENU ][ TAM_MENU ] = {
		"Burbuja",
		"Seleccion",
		"Insercion",
		"QuickSort",
		"Shell",
		"Salir"
	};
	
	char op;
	t_menu menu;
	
	crearMenu(
			&menu, 
			opciones,
			"12345S", 
			"Algoritmos de Ordenamiento", 
			"Ingrese una opcion del menu", 
			"Err Elija nuevamente", 
			"[]"
	);
	
	
	do {
		op = seleccionarOpcion(&menu);
		switch(op) {
			case '1':
				 pbaMenuAlgoritmos("Burbuja",  burbuja_gen,pbaPruebaBurbuja);
				break;
			case '2':
				 pbaMenuAlgoritmos("Seleccion",seleccion_gen,pbaPruebaSeleccion);
				break;
			case '3': 
				pbaMenuAlgoritmos("Insercion",insercion_gen,pbaPruebaInsercion);
				break;
			case '4': 
				pbaMenuAlgoritmos("QuickSort",quicksort_gen,pbaPruebaQuickSort);
				break;
			case '5': 
				pbaMenuAlgoritmos("Shell",shell_gen,pbaPruebaShell);
				break;
		}
	} while(op != 'S');

	return 0;
}
