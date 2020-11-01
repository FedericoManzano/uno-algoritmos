
 /***
 	Evaluacion 2 
 	Algoritmos y estructuras de datos
 	Federico Manzano
 	Comision 4 TN
 */
 
 
 #include <stdio.h>
 #include <stdlib.h>
 
 /**
 *	Valida la condicion de fin del programa
 *	Si X == 'S' o X == 's'
 */
 #define COND_FIN(X)( (X) == 's' || (X) == 'S' )
 
 
 /**
 *	Verifica si el vuelo es Nacional
 */
 #define ES_VUELO_NACIONAL(X)( (X) == 'n' || (X) == 'N' )
 
 
 /**
 *	Verifica si el vuelo es Mercosur
 */
 #define ES_VUELO_MERCOSUR(X)( (X) == 'm' || (X) == 'M' )
 
 
 /**
 *	Verifica si el vuelo es Internacional
 */
 #define ES_VUELO_INTERNACIONAL(X)( (X) == 'i' || (X) == 'I' )
 
 /**
 *	Verifica si el vuelo tiene escalas
 */
 #define TIENE_ESCALAS(X)( (X) == 's' || (X) == 'S' )
 
 
 
 
 /***
 *	Esta función limpia la pantalla y muestra un titulo 
 *	centrado en pantalla.
 */
 void titulo(char *);
 
 /**
 *	Esta función retorna el tiempo de vuelo para los vuelos
 *	que poseen escalas.
 */
 int calcularTiempoVuelo( const int, const int, const int );
 
 
 /**
 * Esta función muestra los resultados finales 
 * cantidad de vuelos nacionales
 * cantidad de vuelos al mercosur
 * cantidad de vuelos internacionales (no mercosur)
 */
 void mostrarResultados(const int, const int, const int, const int, const int  );
 
 
 
 int main() {
 	
 	int nVuelo,
	 	tiempoEspera, 		// Tiempo de espera entre escalas
	 				  		// Valor unico igual para todos las escalas	
	    tiempoVuelo,  		// tiempo de vuelo valor entrada
	    cantEscalas, 		// Cantidad de escalas por vuelo
		nVueloMenor, 		// Numero del vuelo con menor tiempo de vuelo sin escalas
		tiempoMenor,  		// Menor tiempo de vuelo sin escalas
	    bandera 	= 1, 	// Bandera abierta para la inicialización	
	    cantNac 	= 0, 	// Cantidad de vuelos Nacionales 
	    cantM 		= 0, 	// Cantidad de vuelos Mercosur 
	    cantInt 	= 0; 	// Cantidad de vuelos Internacionales NO mercosur
	    
	    
 	char condFin, 
	 	 destino, 			// Destino 'n' 'm' 'i' 
		 marcaEscalas;		// Marca que permite decidir si un vuelo tiene escalas o no
 	
 	
 	
 	/**
 	* Se solicita el tiempo de espera por cada escala 
 	* Todas las escalas tienen el mismo tiempo de espera
 	*/
 	titulo("Agregar Tiempo de espera"); //Muestra el titulo y limpia la pantalla
 	printf("Agregar el tiempo de espera por escalas: ");
 	fflush(stdin);
 	scanf("%d", &tiempoEspera);
 	
 	
 	/**
 	* Se solicita al usuario que ingrese si desea 
 	* cargar datos de un vuelo (S / N) para realizar la carga.
 	*/
 	titulo("Datos de vuelo");
 	printf("Desea agregar datos de un vuelo: ");
 	fflush(stdin);
 	scanf("%c", &condFin);
 	
 	
 	// Macro si condFin == 's' || condFin == 'S' Verdadero
 	while( COND_FIN( condFin ) ) {
 		
 		
 		
 		/******************************************************
 			DATOS DE ENTRADA DE LOS VUELOS
		*/
 		printf("Ingrese el Numero de vuelo: ");
 		scanf("%d", &nVuelo);
 		
 		printf("Ingrese el destino (N/M/I): ");
 		fflush(stdin);
		scanf("%c", &destino);
		
		printf("Ingrese el tiempo de vuelo: ");
 		scanf("%d", &tiempoVuelo);
 		
 		printf("Tiene escalas (S/N): ");
 		fflush(stdin);
 		scanf("%c", &marcaEscalas);
 		
 		// Si el vuelo tiene escalas 
 		// la variable marcaEscalas == 's' || marcaEscalas == 'S'
 		if( TIENE_ESCALAS( marcaEscalas ) ) {
 			
 			
 			printf("Ingrese la cantidad de escalas: ");
 			scanf("%d", &cantEscalas);
 			
 			// Como el vuelo tiene escalas 
 			// Se calcula el tiempo de vuelo total con la función 
 			// tVuelo + ( tEspera * cantEscalas )
 			// tiempoDeVuelo + ( tiempoEspera * cantidadDeEscalas )
 			tiempoVuelo = calcularTiempoVuelo( tiempoVuelo, cantEscalas, tiempoEspera );
		} else {
			// Si la bandera es 1
			if(bandera == 1) {
				// Inicalizamos la variable tiempoMenor
				// Y la variable nVueloMenor que se mostrará 
				// En los resultados finales del ejercicio
				tiempoMenor = tiempoVuelo;
				nVueloMenor = nVuelo;
				bandera = 0;
				
				// Una vez inicializadas las variables realiza 
				// las comparaciones con respecto al tiempoVuelo y tiempoMenor
				// para actualizar el valor de la variable nVueloMenor
			} else if(tiempoMenor > tiempoVuelo) {
				tiempoMenor = tiempoVuelo;
				nVueloMenor = nVuelo;
			}
		}
		
		/*
			Macro verifica si el vuelo es 
			NACIONAL destino == 'n' || destino == 'N'
		*/
		if( ES_VUELO_NACIONAL( destino ) )
			cantNac ++;

		/*
			Macro verifica si el vuelo es 
			MERCOSUR destino == 'm' || destino == 'M'
		*/
		if( ES_VUELO_MERCOSUR( destino ) )
			cantM ++;
			
		/*
			Macro verifica si el vuelo es 
			INTERNACIONAL destino == 'i' || destino == 'I'
		*/
		if( ES_VUELO_INTERNACIONAL( destino ) )
			cantInt ++;
 		
 		// Muestro los resultados del vuelo
 		titulo("Datos Registrados");
 		printf("Numero de vuelo: %d\n", nVuelo);
 		printf("Tiempo total de vuelo: %d''\n\n", tiempoVuelo);
 		
 		system("pause");
 		
 		
 		
 		titulo("Datos de vuelo");
 		printf("Desea agregar datos de un vuelo: ");
 		fflush(stdin);
 		scanf("%c", &condFin);
	}
 	mostrarResultados(cantNac,cantM,cantInt,nVueloMenor, bandera);
 	
 	return 0;
 }
 
 
 void titulo(char * tit) {
 	system("cls");
 	printf("\n\t\t\t\t%s\n\n", tit);
 }
 
 int calcularTiempoVuelo( const int tVuelo, const int cantEscalas, const int tEspera ) {
 	return tVuelo + ( tEspera * cantEscalas );
 }
 
 void mostrarResultados(const int cantNac, const int cantMer, const int cantInt, const int nroMenor, const int bandera ) {
	titulo("Resultados Finales");
	printf("Cantidad de vuelos nacionales: %d\n", 		cantNac);
 	printf("Cantidad de vuelos mercosur: %d\n", 		cantMer);
 	printf("Cantidad de vuelos internacionales: %d\n", 	cantInt);
	 
	// Si bandera es 0
	// Significa que no hubo vuelos sin escalas	
	if( !bandera ) 
 		printf("Numero de vuelo de menor tiempo sin escalas: %d\n\n", nroMenor);
	 else 
		printf("No se cargaron datos de vuelos sin escalas \n\n");
	
	system("pause");
 }
