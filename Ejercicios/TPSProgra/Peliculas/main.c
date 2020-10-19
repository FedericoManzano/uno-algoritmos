#include "./include/header.h"



int main(int argc, char *argv[]) {
	
	int 	seleccion [ CANT_PEL ], 
			stock     [ CANT_PEL ]  =  
				 { 
				 	STOCK, 
					STOCK, 
					STOCK 
				 }, 
				 cantIp1 = 0;
	
	float 	monto, 
			total = 0;
	
	char op;
	
	titulo( "Ventas de peliculas de IP MAN" );
	op = ingresarCondFin();
	
	while( ( op == 's' || op == 'S' ) && stockTotal( stock ) ) {
		
		
		ingresarSeleccion( seleccion );
		
		if( puedeVender( seleccion, stock ) ) {
			
			monto = calcularPecio(seleccion);
			actualizarStock(seleccion, stock);
			
			titulo("Precio de la compra");
			mostrarMensaje(stock, VENTA_OK, monto);
			total += monto;
			
			if( seleccion[ IP_MAN_1 ] )
				cantIp1 ++;
				
		} else {
			titulo("Stock insuficiente");
			mostrarMensaje(stock, VENTA_NO, monto);
		}
		
		
		titulo("Ventas de peliculas de IP MAN");
		op = ingresarCondFin();
	}
	
	mostrarTotales(total, cantIp1);
	
	return 0;
}
