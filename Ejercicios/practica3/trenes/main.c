 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
 #include <math.h>
 
 
/** 
	MACROS con los valores del menu
*/
 #define MORENO 		1
 #define PASO_DEL_REY 	2
 #define MERLO 			3
 #define PADUA			4
 #define ITUZAINGO		5
 #define CASTELAR 		6
 #define MORON			7
 #define HAEDO			8
 #define RAMOS_MEJIA	9
 #define CIUDADELA		10
 #define LINIERS		11
 #define VILLA_LURO		12
 #define FLORESTA		13
 #define FLORES 		14
 #define CABALLITO		15
 #define ONCE			16
 
 
 #define ESTACIONES(X) ( (X) >= 1 && (X) <= 16 )
 
 
 
 int seleccionarOpcion(char *);
 float calcularImporte(const int , const int );
 char condicionFin();
 void mostrarInfoVieje (const int , const float );
 void datosEntrada(int *, char *  );
 int ingresarEdad();
 
 void mostrarRes ( const int, const float, const float, int );
 
 
 int main () {
 	
 	char pass[25];
	int entrada, 
		salida, 
		id, 
		nroViaje 	= 1, 
		edad, 
		cantViajes 	= 0, 
		bandera 	= 1; // Viaje
		
		
	float monto, total = 0, importeMay;
 	
 	char op = condicionFin();
 	
 	while(op == 'S' || op == 's') {
 		
 		// Cargo los valores de entrada
 		datosEntrada(&id,pass);
 		edad = ingresarEdad();
 		
 		// Muestro el menu de estaciones
 		entrada = seleccionarOpcion("Entrada");
 		
 		// Simulo el viaje
 		system("cls");
 		printf("Viaje terminado\n");
 		
 		// Pido nuevamente los datos
 		datosEntrada(&id,pass);
 		salida = seleccionarOpcion("Salida");
 		
 		
 		if(edad <= 5) 
 			monto = 0;
		else 
			monto = calcularImporte(entrada, salida);
		
		if(bandera == 1) {
			importeMay = monto;
			bandera = 0;
		} else if(importeMay < monto) 
			importeMay = monto;
			
		mostrarInfoVieje(id,monto);
		total += monto;
		
		cantViajes ++;
 		op = condicionFin();
	}
 	
 	mostrarRes(cantViajes,importeMay,total, bandera);

 	
 	return 0;
 }
 
 void mostrarRes ( const int cantViajes, const float importeMay, const float total, int bandera ) {
 	system("cls");
 	printf("Cantidad de viajes totales: %d\n", cantViajes);
 	printf("Total: %.2f\n",total);
 	if(bandera == 0)
 		printf("Mayor importe: %.2f\n", importeMay);
 	else
 		printf("Mayor importe: 0.00\n");
 	system("pause");
 }
 
 
 int ingresarEdad() {
 	int edad;
 	printf("Ingrese su edad: ");
 	scanf("%d", &edad);
 	return edad;
 }
 
 int seleccionarOpcion(char * titulo) {
 	
 	
 	int opcion;
 	int val = 0;
 	
 	system("cls");
 	printf("\n\t\t\t\t%s\n\n", titulo);
 	printf("\t\t%2d - Moreno\n", 		MORENO);
 	printf("\t\t%2d - Paso del Rey\n", 	PASO_DEL_REY);
 	printf("\t\t%2d - Merlo\n", 		MERLO);
 	printf("\t\t%2d - Padua\n", 		PADUA);
 	printf("\t\t%2d - Ituzaingo\n", 	ITUZAINGO);
 	printf("\t\t%2d - Castelar\n", 		CASTELAR);
 	printf("\t\t%2d - Moron\n", 		MORON);
 	printf("\t\t%2d - Haedo\n", 		HAEDO);
 	printf("\t\t%2d - Ramos Mejia\n", 	RAMOS_MEJIA);
 	printf("\t\t%2d - Ciudadela\n", 	CIUDADELA);
 	printf("\t\t%2d - Liniers\n", 		LINIERS);
 	printf("\t\t%2d - Villa Luro\n", 	VILLA_LURO);
 	printf("\t\t%2d - Floresta\n", 		FLORESTA);
 	printf("\t\t%2d - Flores\n", 		FLORES);
 	printf("\t\t%2d - Caballito\n", 	CABALLITO);
 	printf("\t\t%2d - Once\n", 			ONCE);
 	
 	do {
 		if(val) {
 			printf("\n\n\tErr opcion errones\n\n");
 			val = 0;
		}
 		printf("\n\t\tSeleccionar una opcion: ");
 		scanf("%d", &opcion);
 		val = 1;
	} while( !ESTACIONES(opcion) );
	
	return opcion;
 }
 
 
 float calcularImporte(const int entrada, const int salida) {
 	return (float)(abs(salida - entrada) * 2);
 }
 
 char condicionFin() {
 	char op;
 	system("cls");
 	printf("Desea seguir agregando viajes (S / N): ");
 	fflush(stdin);
 	scanf("%c", &op);
 	return op;
 }
 
 void mostrarInfoVieje (const int idPasajero, const float monto) {
 	static int nroViaje = 1;
 	system("cls");
 	printf("\n\t\t===================================\n");
 	printf("\t\tID: %d MONTO: %.2f NRO: %d\n", idPasajero, monto, nroViaje);
 	printf("\n\t\t===================================\n");
 	nroViaje ++;
 	system("pause");
 }
 
 
 void datosEntrada(int *id, char * pass) {
 	printf("Ingrese el id del pasajero: ");
 	scanf("%d", id);
 	printf("Ingrese el password: ");
 	fflush(stdin);
 	gets(pass);
 }
