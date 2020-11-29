 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>
 
 #define TAM_VEC 50
 
 #define COSTO_BARILOCHE 30000
 #define COSTO_CALAFATE  10000
 #define COSTO_USHUAIA	 20000	
 
 #define COSTO_MED_PENSION 5000
 
 
 
  // Funciones Utilitarias
 void titulo( const char * tit);
 void pausar();
 void inicializarVectores(char *, int *, int *);
 void mostrarOpciones();
 char seleccionarOpcion();
 void ingresarDatos(char *, int *, int *) ;
 void cargarDatosVectores(char *, int *, int *, char, int, int);
 void mostrarInforme( char *, int *, int * );
 
 int main () {
 	
 	// Entradas
 	char destino;
 	int cantPasajetos, mediaPension;
 	
 	// Vectores
 	char 	vDestino	[TAM_VEC]; 
 	int 	vCantPas 	[TAM_VEC],
	 		vMedPension	[TAM_VEC];
	char op;
	
	
	
	inicializarVectores(vDestino, vCantPas,vMedPension);
	
	
	do {
		op = seleccionarOpcion();
		
		switch(op) {
			case '1': 
				ingresarDatos(&destino, &cantPasajetos, &mediaPension);
				cargarDatosVectores(vDestino, vCantPas, vMedPension, destino, cantPasajetos, mediaPension);
			break;
			case '2': 
				mostrarInforme(vDestino, vCantPas, vMedPension);
				break;
			
		}
		
		
	} while(op != 'S');
	 	
 	
 	return 0;
 }
 
 
 // Funciones Utilitarias
 void titulo( const char * tit) {
 	system("cls");
 	printf("\n\n\t\t\t%s\n\n", tit);
 }
 
 void pausar() {
 	printf("\n\n");
 	system("pause");
 }
 
 void inicializarVectores(char *vDestino, int *vCantPas, int * vMedPension) {
 	int i;
 	
 	for( i = 0; i < TAM_VEC; i ++ ) {
 		*(vDestino) 	= '\0';
 		*(vCantPas) 	= 0;
 		*(vMedPension) 	= 0;
 		vDestino 	++;
 		vCantPas 	++;
 		vMedPension ++;
	}
 }
 
 void mostrarOpciones() {
	titulo("Menu Paquetes");
 	printf("\t[1] Ingresar datos de solicitudes de viaje \n");
 	printf("\t[2] Informacion de costos de paquete \n");
 	printf("\t[S] Salir\n\n");
 }
 
 
 char seleccionarOpcion() {
 	char op;
 	
 	mostrarOpciones();
 	
 	
 	printf("Seleccionar opcion del menu (1/2/S): ");
 	fflush(stdin);
 	scanf("%c", &op);
 	
 	// Si op es una letra S s o cualquier otra la devuelve en mayusculas 
 	return toupper( op );
 }
 
 void ingresarDatos(char * destino, int * cantPass, int * medPension) {
 	titulo("Ingreso de datos");
 	
 	printf("Ingrese el destino (b/c/u): ");
 	fflush(stdin);
 	scanf("%c", destino);
 	
 	printf("Ingrese la cantidad de pasajeros: ");
 	fflush(stdin);
 	scanf("%d", cantPass);
 	
 	printf("Desea una media pension (1/0): ");
 	scanf("%d", medPension);
 	
 }
 
 void cargarDatosVectores(char * vDestino, int * vCantPas, int * vMedPension, char destino, int cantPas, int medPension) {
 	static int ind = 0;
 	*(vDestino 		+ ind) = destino;
 	*(vCantPas 		+ ind) = cantPas;
 	*(vMedPension 	+ ind) = medPension;
 	ind ++;
 }
 
 void mostrarInforme( char * vDestino, int * vCantPas, int * vMedPension ) {
 	float costo;
 	int cantBar = 0, cantCal = 0, cantUsh = 0;
 	
 	titulo("Mostrar Informe");
 	
 	while( *vDestino ) {
 		switch(*vDestino) {
 			case 'b': 
			 	costo = COSTO_BARILOCHE * *vCantPas;
			 	cantBar ++;
 			break;
 			case 'c': 
			 	costo = COSTO_CALAFATE * *vCantPas;
			 	cantCal ++;
 			break;
 			case 'u': 
			 	costo = COSTO_USHUAIA * *vCantPas;
 				cantUsh ++;
			 break;
		}
		
		if( *vMedPension ) 
			costo += COSTO_MED_PENSION * *vCantPas;
		
		printf("\tDestino: %c\n", *vDestino);
		printf("\tCantidad de pasajeros: %d\n", *vCantPas);
		printf("\tMedia pension: %d\n", *vMedPension);
		printf("\tCosto del paquete: $ %.2f\n\n", costo);
		
		printf("\t--------------------------\n\n");
		
		vDestino ++;
		vCantPas ++;
		vMedPension ++;
	}
	
	printf("\tCANTIDADES TOTALES\n\n");
	
	
	printf("Cantidad de paquetes a Bariloche: %d\n", cantBar);
	printf("Cantidad de paquetes a Calafate: %d\n", cantCal);
	printf("Cantidad de paquetes a Ushuaia: %d\n", cantUsh);
	
	
	
	pausar();
 }
 
