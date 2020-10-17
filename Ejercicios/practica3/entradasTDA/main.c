#include "./include/header.h"

/**
	Ejercicio festival de musica
*/


int main(int argc, char *argv[]) {
	// TDA Venta de entradas
	t_venta venta;
	
	// inicializar el TDA
	crearVentas(&venta);
	
	char op = condicionFin();
	
	while ( op == 'S' || op == 's' ) { 
		
		// Cargo el dia seleccionado en el TDA
		ingresarDia(&venta);
		
		// Cargo la ubicación seleccionada en el TDA
		ingresarUbicacion(&venta);
		
		// Genero la venta
		if( venderEntrada( &venta ) ) 
			// Si la venta se puede hacer muestro el ticket
			mostrarTicket( &venta );
		else
			// Muestro mje de falta de espacio
			mostrarFaltaEspacio(&venta);
		
		// Cond fin
		op = condicionFin();
	} // fin del while
	
	// Resultados Finales
	mostrarResultadosFinales (&venta);
	
	
	return 0;
}


