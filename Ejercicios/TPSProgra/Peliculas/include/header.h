#include <stdio.h>
#include <stdlib.h>

#define CANT_PEL  	3
#define STOCK  		80

#define VENTA_OK 1
#define VENTA_NO 0

#define IP_MAN_1 0

#define PROMO 600
#define PRECIO_X_PELICULA 250

float 	calcularPecio( int * );
int 	hayStock( const int );
int 	puedeVender( int  *, int * );
void 	ingresarSeleccion( int *  );
void 	ingresarSeleccion( int * );
void 	mostrarMensaje( const int * , const int, const float );
void 	titulo( char * );
void 	mostrarTotales ( const float, const int );


