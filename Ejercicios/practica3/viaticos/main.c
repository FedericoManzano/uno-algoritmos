#include "./include/header.h"

/**
* 	Ejercicio de calcular gastos de viaticos de los empleados
*/

int main(int argc, char *argv[]) {
	
	t_viatico viatico;
	
	// Inicializo el TDA viatico
	inicializarViatico( &viatico );
	
	// Condicion de fin
	char op = condicionFin ();
	
	while( op == 's' || op == 'S') {
		// Ingreso los datos de entrada
		ingresarDatos( &viatico );
		
		// Calcular gastos de viaticos
		calcularGasto( &viatico );
		
		// incremento el vendedor que cumple con la condicion
		if( verCategoria( &viatico ) == 'v' && verKm( &viatico ) > 2000 ) 
			incrementarVendedor2000( &viatico );
			
		// Muestro los gastos de viatico del vendedor
		mostrarGastos( &viatico );
		
		// Condicion de fin
		op = condicionFin ();
	} // Fin del while
	
	// Muestro el resultado de la cantidad de vendedores 
	// que recorrieron mas de 2000 km
	mostrarCantVendedoresA2000( &viatico );
	
	return 0;
}


