#include "./include/header.h"

/**
* Ejercicio 1 Funciones 
*/
int main(int argc, char *argv[]) {
	
	
	char 	categoria[9], 	// moto, auto, camion, camioneta 
		 	horario, 	  	// a,b (A: pico B: no pico)	
		 	condFin;
		 
	float 	importeEnt, 	// Importe otorgado por el conductor
		  	importeCob, 	// Importe calculado del peaje
		  	vuelto, 
		  	total = 0;
		  
	int 	cantidadPases = 0, 
			dia;
	
	/*
		Funcion que limpia la pantalla 
		y muestra un titulo descriptivo 
		en la parte superior de la misma
	*/
	titulo("Pases por peaje");
	
	/*
		Caracter que permite finalizar la ejecución del 
		ciclo while
	*/
	condFin = condicionFin();
	
	/*
		Si condFin != 'S' && condFin != 's' 
		El siclo sigue
	*/
	while(	!COND_FIN( condFin ) ) {
		
		// LLena las variables de entrada con los datos 
		// ingresados por el usuario
		cargarEntradas( categoria, &dia, &horario, &importeEnt );
		
		// importe a cobrar por el valor del peaje
		// La funcion obtenerBase devuelve el precio base según la 
		// categoria seleccionada
		importeCob = calcularImporte( obtenerBase(categoria), dia, horario );
		
		// Diferencia entre el importe pagado por el conductor 
		// y el importe del peaje
		vuelto = calcularVuelto(importeEnt, importeCob);
		
		// Si la categoria es auto y el horario es 'a'(pico)
		// incrementa el contador de autos en horario pico
		if( !strcmpi( categoria, "Auto" ) && ES_PICO( horario )) 
			cantidadPases ++;
		
		// Limpia la pantalla
		// Muestra el titulo importe
		// y muestra Lo cobrado al conductor y el vuelto que le corresponde
		titulo("Importe");
		mostarImporte(importeCob, vuelto);
		
		total += importeCob;
		
		// Vuelve a pedir la cond de fin
		titulo("Pases por peaje");
		condFin = condicionFin();
	} // Fin del while
	
	// Muesra el total facturado de todos los vehiculos que pasaron por el peaje
	// Cantidad de autos en horario pico
	mostarResultados(total, cantidadPases);
	
	return 0;
}


