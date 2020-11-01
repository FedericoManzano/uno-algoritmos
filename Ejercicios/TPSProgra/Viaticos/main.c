#include "./include/include.h"


int main(int argc, char *argv[]) {
	
	float km, monto, gastoPeaje, gastoComida, anticipo;
	char categoria, condFin;
	
	int codigo, cantVen = 0;
	
	
	titulo("Calcular Viaticos");
	condFin = ingresarCondFin();
	
	while( condFin == 'S' || condFin == 's' ) {
		if(	ingresarDatosEntrada(&codigo, &categoria, &km, &gastoComida, &gastoPeaje, &anticipo)	)  
			monto = calcularMonto(km, gastoComida,gastoPeaje) - anticipo;
		else 
			monto = calcularMonto(km, gastoComida,gastoPeaje);
			
		if( ( categoria == 'v' || categoria == 'V' ) && km > 20000 ) 
			cantVen ++;
			
			
		titulo("Mostrar Gasto");
		mostrarGastoViatico(monto);
		
		titulo("Calcular Viaticos");
		condFin = ingresarCondFin();
	}
	titulo("Resultados finales");
	mostrarCantVendedores(cantVen);
	
	return 0;
}



