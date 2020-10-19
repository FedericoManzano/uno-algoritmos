#include "../include/header.h"

void titulo( char * tit ) {
	system("cls");
	printf( "\n\t\t\t\t%s\n\n", tit );
}

float calcularPecio( int * select ) {
	int i, comprados = 0;
	for( i = 0; i < CANT_PEL; i ++ )
		comprados += select[i];
	return comprados == 3 ? PROMO : PRECIO_X_PELICULA * comprados; 
}

int hayStock(const int stock) {
	return stock > 0;
}

int puedeVender( int  * select, int * stock ) {
	int puede = 1, i;
	for(i = 0; i < CANT_PEL; i ++)
		if( select[i] ) 
			if( !hayStock(stock[i]) ) 
				puede = 0;
	return puede;	
}

void ingresarSeleccion(int * selec) {
	int i;
	titulo("Seleccion de peliculas");
	for(i = 0; i < 3; i ++) {
		printf("Quiere comprar IpMan %d (1/0): ", i + 1);
		scanf("%d", selec + i);
	}	
}

void actualizarStock( int *seleccion, int * stock ) {
	int i;
	for(i = 0; i < CANT_PEL; i ++) 
		stock[i] -= seleccion[i];
}



void mostrarMensaje( const int *stock , const int opcion, const float monto ) {
	int i;
	
	if(opcion) {
		printf("El monto a abonar es %.2f\n\n", monto);
		system("pause");
		return;
	}
	
	for( i = 0; i < CANT_PEL; i ++ ) 
		if( stock[i] == 0 ) 
			printf( "La pelicula IP MAN %d no tiene stock   \n\n", i + 1);
	system("pause");
}

int stockTotal ( int * stock ) {
	return stock[0] + stock[1] + stock[2];
}

void mostrarTotales (const float total, const int cantPel1) {
	titulo( "Resultados Finales" );
	printf( "El monto total recaudado es: %.2f\n", 			   total );
	printf( "La cantidad de peliculas IP MAN 1 es: %d\n\n", cantPel1 );
	system( "pause" );
}

char ingresarCondFin() {
	char op;
	printf("Desea realizar una venta (S/N): ");
	fflush(stdin);
	scanf("%c", &op);
	return op;
}
