#include "./include/menu.h"
#include "./include/header.h"



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
		"Ejercicio 9, 10",
		"Ejercicio 11",
		"Ejercicio 12",
		"Ejercicio 13",
		"Ejercicio 14",
		"Ejercicio 15",
		"Ejercicio 16",
		"Ejercicio 17",
		"Ejercicio 18",
		"Ejercicio 19",
		"Ejercicio 20",
		"Ordenar Vector (QSort)",
		"Ordenar Vector (Seleccion)",
		"Ordenar Vector (Burbuja)",
		"Salir"
	};

	crearMenu(
			&menu,
			opciones,
			"ABCDEFGHIJKLMNOPQRTUVWS", 
			"TRABAJO PRACTICO 4", 
			"Ingrese una opcion del menu", 
			"Err elija nuevamente", 
			"[]"
	);
	
	do {
		op = seleccionarOpcion(&menu);
		
		switch(op) {
			case 'A': numeroPares ();
				break;
			case 'B': mostrarInvertido();
				break;
			case 'C': sumResMulDiv();
				break;
			case 'D': mostrarMenorMayor();
				break;
			case 'E': mostrarBusquedaNumero();
				break;
			case 'F': mostrarCantMaySeis();
				break;
			case 'G': mostarPromedioPorcentaje();
				break;
			case 'H': mostrarMaxMinIndices();
				break;
			case 'I': mostrarPromedioProducto();
				break;
			case 'J': mostrarInvertidoMitad();
				break;	
			case 'K': calcularVendedores();
				break;	
			case 'L': mostrarNombreEdad();
				break;
			case 'M': mostrarMayorMatriz();
				break;
			case 'N': mostrarAcuPosNeg();
				break;
			case 'O': mostrarMayorMenorMatriz();
				break;	
			case 'P': contarConsVocales();
				break;
			case 'Q': palabrasIguales();
				break;	
			case 'R': mostrarCantidadLetras();
				break;
			case 'T': opracionesMatrices();
				break;
			case 'U': mostrarOrdenado();
				break;
			case 'V': mostrarOrdenadoSeleccion();
				break;
			case 'W': mostrarOrdenadoBurbuja();
				break;
		}
		
	} while(op != 'S');
	
	return 0;
}
