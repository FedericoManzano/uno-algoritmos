 #include <stdlib.h>
 #include <stdio.h>
 
 
 #define IP_MAN_1 				1
 #define IP_MAN_2 				2
 #define IP_MAN_3 				3
 
 #define FALTA_STOCK 			2
 
 #define COMPRAR_UNO 			1
 #define COMPRAR_DOS 			2
 #define COMPRAR_TRES 			3
 
 #define PRECIO_PELICULA 		250
 #define PRECIO_COMBO 			600
 
 #define CANT_POR_COMPRA(X)((X) == 1 || (X) == 0)
 
 #define STOCK_INICIAL 80
 
 // Pido al usuario si quiere seguir añadiendo
 // compras
 char condFin();
 
 // Pregunta al usuario si quiere la pelicula 
 int solicitud(const char *);
 
 // Devuelve el importe de la compra
 float calcularMonto(const int, const int, const int);
 
 // Funcion para mostrar el valor de la compra
 void mostrarMonto(float);
 
 // Si se cancela la compra informa 
 // La pelicula que no tiene stock
 void mensajeFaltaStock( const char *);
 
 // Verifica por cada pelicula si es posible comprarla
 // caso afirmativo devuelve 1 en caso contrario devuelve 2
 int verificarCompra( const int ,const int , const int  );
 
 // Muestra resultados finales
 void mostrarResultadosFinales(const int, const float);
 
 int main () {
 	
 	unsigned short 	stockip1 = STOCK_INICIAL,
 				 	stockip2 = STOCK_INICIAL,
 				 	stockip3 = STOCK_INICIAL,
 				 	compraIp1,
 				 	compraIp2,
 				 	compraIp3;
 				 
 				 
 	float monto, total  = 0;
 	int cantidadIp1 	= 0;
 	int faltante 		= 0;
 	
 	// Pregunta quiere  realizar una compra
 	char op 			= condFin(); 
 	
	// Si el usuario ingresa op != s (O) no hay stock de ninguna pelicula
	// El programa termina el bucle while.
 	while( ( op == 'S' || op == 's' ) && ( stockip1 || stockip2 || stockip3 )) {
 		
 		// Pide el datos de IP MAN 1 (1 / 0) Entero
 		compraIp1 = solicitud("Solicita IpMan 1: ");
 		
 		// Pide el datos de IP MAN 2 (1 / 0) Entero
 		compraIp2 = solicitud("Solicita IpMan 2: ");
 		
 		// Pide el datos de IP MAN 3 (1 / 0) Entero
		compraIp3 = solicitud("Solicita IpMan 3: "); 
		
		
		/**
			Devuelve 1 si la compra de IP man 1 se puede realizar 
			Devuelve 0 si el usuario ingreso 0 y no quiere esta pelicula 
			Devuelve 2 = FALTA_STOCK si el usuario la quiere pero no hay stock
		*/
		compraIp1 = verificarCompra(compraIp1, stockip1, IP_MAN_1);
		
		
		/**
			Devuelve 1 si la compra de IP man 2 se puede realizar 
			Devuelve 0 si el usuario ingreso 0 y no quiere esta pelicula 
			Devuelve 2 = FALTA_STOCK si el usuario la quiere pero no hay stock
		*/
		compraIp2 = verificarCompra(compraIp2, stockip2, IP_MAN_2);
		
		
		/**
			Devuelve 1 si la compra de IP man 3 se puede realizar 
			Devuelve 0 si el usuario ingreso 0 y no quiere esta pelicula 
			Devuelve 2 = FALTA_STOCK si el usuario la quiere pero no hay stock
		*/
		compraIp3 = verificarCompra(compraIp3, stockip3, IP_MAN_3);
		
		/*
			Si alguna de las peliculas no pasa la verificacion por 
			falta de stock no se calcula el monto y se cancela la compra.
		*/
		if(compraIp1 != FALTA_STOCK && compraIp2 != FALTA_STOCK && compraIp3 != FALTA_STOCK ) {
			if(compraIp1) { 	// Si es compraIp1 != 0
				stockip1 --; 	// Actualizo stock
				cantidadIp1 ++; // Cuento las peliculas IP MAN 1
			}
			if(compraIp2) 
				stockip2 --;
			if(compraIp3)
				stockip3 --;
				
			if( compraIp1 || compraIp2 || compraIp3 )  {
				monto = calcularMonto(compraIp1, compraIp2, compraIp3);
				mostrarMonto(monto);
				total += monto;
			}
		}
	
	    /**
	    	Si no hay stock de ninguna pelicula
	    	no pregunta a usuario si quiere seguir y termina la ejecución.
	    */
		if(stockip1 || stockip2 || stockip3) 
			op = condFin();  
	} 
	
	mostrarResultadosFinales(cantidadIp1, total);
 	
 	
 	return 0;
 }
 
 
 void mostrarResultadosFinales(const int cantIp1, const float total) {
 	system("cls");
 	printf("\n\t*************************************\n");
	printf("\n\tLa cantidad de peliculas IP Man 1 %d\n", cantIp1);
	printf("\tTotales %.2f\n", total);
	printf("\n\t*************************************\n\n");
 	system("pause");
 }
 
 int verificarCompra( const int cantidadPel, const int stock,const int volumen ) {
 	if(cantidadPel ) {
		if( hayStock(stock) ) {
			return 1;
		}else {
			system("cls");
			if(volumen == 1)
				mensajeFaltaStock("No hay stock de la pelicula Ip Man 1 \n");
			if(volumen == 2)
				mensajeFaltaStock("No hay stock de la pelicula Ip Man 2 \n");
			if(volumen == 3)
				mensajeFaltaStock("No hay stock de la pelicula Ip Man 3 \n");
			return 2;
		}	
	}
	return 0;
 }
 
 char condFin() {
 	char op;
 	system("cls");
 	printf("Desea realizar una venta: ");
 	fflush(stdin);
	scanf("%c", &op);
	return op;
 }
 
 int hayStock ( const int stock ) {
 	return stock >= 1;
 } 
 
 int solicitud(const char *mje) {
 	int solicitud;
 	int val = 0;
 	do {
 		if(val) {
 			printf("\n\n\tError los valores permitidos son 0 o 1 \n\n");
 			val = 0;
		}
 			
 		printf(mje);
		scanf("%d", &solicitud);
		val = 1;
	} while ( !CANT_POR_COMPRA(solicitud) );
 	
	return solicitud;
 }
 
 float calcularMonto(const int ip1, const int ip2, const int ip3) {
 	if( ip1 + ip2 + ip3 == COMPRAR_TRES )
 		return PRECIO_COMBO;
 	else if( ip1 + ip2 + ip3 == COMPRAR_DOS )
 		return PRECIO_PELICULA * 2;
 	else if( ip1 + ip2 + ip3 == COMPRAR_UNO )
 		return PRECIO_PELICULA;
 	else 
 		return 0;
 		
 }
 
 void mostrarMonto(float monto) {
 	system("cls");
 	printf("\n\t ** El monto a abonar es de %.2f ** \n\n", monto);
 	system("pause");
 }
 
 
 void mensajeFaltaStock( const char * mje) {
 	printf("%s \n", mje);
 	system("pause");
 }
 

