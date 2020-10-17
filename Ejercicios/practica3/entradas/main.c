 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
 #include <string.h>
 
 
 
 #define CAP_CAM 	3500
 #define CAP_PLA 	1000
 #define CAP_PAL 	500
 
 #define PRE_CAM    60
 #define PRE_PLA    80
 #define PRE_PAL    120
 
 #define DIA_1 		0
 #define DIA_2		1
 #define DIA_3		2
 
 #define CAMPO 		0
 #define PLATEA		1
 #define PALCO		2
 
 
 #define MAX 		3
 
 
 #define DIA(X) ( (X) >= 1 && (X) <= 3 ) 
 

 
char condicionFin ();
int ingresarDia ();
float calcularPrecio(int );
void mostrarEntrada(const int , const float );
void mostrarFaltaEspacio();
int hayEspacio( int [][MAX], const int, const int );
void inicializarCapacidad(int capacidad[][3] );
void mostrarResultadosFinales (const int cantCampo1, const int totalEntradas, const float total);



 int main() {
 	// Entradas
 	unsigned short dia, ubicacion, ticket;
 	float precio;
	
	
	/**
		Arreglo dias/ubicacion
		   0|   1|   2| 	
		0| 3500 1000 500
		1| 3500 1000 500
		2| 3500 1000 500
	*/
 	int capacidad[MAX][MAX];
 	
 	
	// Variables resultados finales
 	int cantCampo1 		= 0;
 	int totalEntradas 	= 0;
 	float total 		= 0;
 	
 	char op;
 	
 	inicializarCapacidad(capacidad);
 	
 	op = condicionFin();
 	
 	// Mientras sea S o s sigue
 	while ( op == 'S' || op == 's' ) {
 		
 		
 		// Devuelve el dia 
 		// Para el arreglo 0, 1, 2
 		dia = ingresarDia();
 		
 		// Devuelve la hubicacion
 		// Para el arreglo 0,1,2
 		ubicacion = ingresarUbicacion();
 		
 		// Si hay stock en la ubicacion y dia seleccionado
 		if( hayEspacio(capacidad, dia, ubicacion) ) {
 			
 			// pide el numero de tiket
 			ticket = nroTicket ();
 			
 			// En función a la ubicacion calcula el precio
			precio = calcularPrecio( ubicacion );
			
			// Muestra los datos de la entrada
			mostrarEntrada(ticket,precio); 
			
			// Actualiza la capacidad
			capacidad[dia][ubicacion] --;
			
			// Determina si el si el dia es 1 
			// y la ubicacion es campo
			if( dia == DIA_1 && ubicacion == CAMPO )  
				cantCampo1 ++;
				
			// Resultados finales
			total += precio;
			totalEntradas ++;	
		} else 
			mostrarFaltaEspacio();
		
		op = condicionFin();
	}  
 	
 	mostrarResultadosFinales(cantCampo1,totalEntradas,total);
 	
 	
 	return 0;
 }
 
 int hayEspacio(int capacidad[][MAX], const int dia, const int ubicacion ) {
 	return capacidad[dia][ubicacion] > 0;
 }
 
 void mostrarResultadosFinales (const int cantCampo1, const int totalEntradas, const float total) {
 	system("cls");
 	printf("=================================================\n");
 	printf("La cantidad de entradas de campo del dia 1 es: %d\n", cantCampo1);
 	printf("La cantidad total de entradas de los 3 dias es: %d\n", totalEntradas);
 	printf("Recaudacion total: %.2f\n", total);
 	printf("=================================================\n\n");
 	system("pause");
 }
 
 void inicializarCapacidad( int capacidad[][MAX] ){
 	int i, j;
 	for( i = 0; i < MAX; i ++ )
 		for(j = 0; j < MAX; j ++) {
 			if(j == CAMPO)
			 	capacidad[i][j] = CAP_CAM; // 3500	
			else if(j == PLATEA)
				capacidad[i][j] = CAP_PLA; // 1000
			else if(j == PALCO)
				capacidad[i][j] = CAP_PAL; // 500	
		}
 }
 void mostrarFaltaEspacio() {
 	system("cls");
	printf("\nNo hay capacidad sificiente para esta ubicación en este dia.\n\n");
	system("pause");
 }
 
 
 void mostrarEntrada(const int ticket, const float precio) {
 	system("cls");
 	printf("\n\t=============\n");
 	printf("\n\tTicket: %d\n", ticket);
 	printf("\n\tPrecio: %.2f\n\n", precio);
 	system("pause");
 }
 
 
 int nroTicket () {
 	static int ticket = 0;
 	ticket ++;
 	return ticket;
 }
 
 int ingresarUbicacion() {
 	char ubicacion [4];
 	int val = 0;
 	int ubiEntero;
 	
 	do {
 		
 		if(val) {
 			printf("\n\nErr Ingrese nuevamiente la ubicacion\n\n");
 			val = 0;
		}
 		printf("Ingrese la ubicacion deseada ( cam / pla / pal ): ");
 		fflush(stdin);
 		gets(ubicacion);
 		val =  1;
	} while( strcmpi(ubicacion, "cam") && strcmpi(ubicacion, "pla") && strcmpi( ubicacion, "pal" ) );
	
	if( !strcmpi(ubicacion, "cam") )
		ubiEntero = CAMPO;
	if( !strcmpi(ubicacion, "pla") )
		ubiEntero = PLATEA;
	if( !strcmpi(ubicacion, "pal") )
		ubiEntero = PALCO;
	
 	return ubiEntero;
 }
 
 char condicionFin () {
 	char op;
 	system("cls");
 	printf("Desea vender una entrada: ");
 	fflush(stdin);
 	scanf("%c", &op);
 	return op;
 }
 
 
 int ingresarDia () {
 	int dia;
	do {
		printf("Ingrese el dia: ");
 		scanf("%d", &dia);
	} while( !DIA(dia) );
 	
 	return dia - 1;
 }
 
 float calcularPrecio(int ubi) {
 	if(ubi == CAMPO)
 		return PRE_CAM;
 	if(ubi == PLATEA)
 		return PRE_PLA;
 	return PRE_PAL;
 }
 
 
