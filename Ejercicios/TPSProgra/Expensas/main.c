#include "./include/header.h"

/***
	Ejercicio 5 de funciones
*/
int main(int argc, char *argv[]) {
	
	// Valores de entrada enteros
	int nroDepto, 
		esProfesional, 
		// Salida cantidad Dos Amb profesionales
		// Contador
		cantDeptoDProf = 0;
		
	char condFin , // Condicion de fin
		 // Valores char de entrada 
		 categoria, 
		 tieneCochera, 
		 tieneMultas;
	// Salidas montos a abonar
	float montoExp, 
		  montoMultas;
	
	/*
		Funcion que limpia la pantalla y muestra 
		un titulo descriptivo.
	*/
	titulo("Calculo de gastos en los departamentos");
	
	// Funcion que devuelve el valor 
	// ingresado por el usuario
	// S / N
	condFin = condicionFin();
	
	while( COND_FIN(condFin) ) {
		
		// Funcion que copia los datos de entrada en sus respectivas 
		// Recibe la direccion de las variables
		ingresarDatosEntrada(&nroDepto, &categoria, &esProfesional, &tieneCochera ,&tieneMultas);
		
		// Si el depto tiene acumuladas multas S las suma al monto a pagar
		if( tieneMultas == 's' || tieneMultas == 'S' ) {
			
			// Devuelve el monto de multas asignado al depto
			montoMultas = ingresarMontoMultas();
			
			// Monto a pagar
			montoExp = 
				montoMultas + montoExpensas( categoria, esProfesional, tieneCochera );
		} else 
			montoExp = montoExpensas(categoria,esProfesional,tieneCochera);
		
		// Macros DOS_AMB es verdadero y ES_PROFESIONAL es verdadero
		// incrementa el contador de dosambientes profesionales
		if( DOS_AMB( categoria ) && ES_PROFESIONAL( esProfesional ) ) 
			cantDeptoDProf ++;
			
		// Muestra los gastos del depto 
		mostrarGastosDepto(nroDepto, montoExp);	
		
		// Vuelve a mostrar la condicion de fin
		titulo("Calculo de gastos en los departamentos");
		condFin = condicionFin();
	} // Fin del while	
	
	// Muestra el valor del contador
	// dos ambientes profesionales
	mostrarResultadoFinal(cantDeptoDProf);
	
	
	return 0;
}
