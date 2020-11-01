 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
 #include <string.h>
 
 
 #define CAP_CAM 3500
 #define CAP_PLA 1000
 #define CAP_PAC 500
 
 #define PRE_CAM 60
 #define PRE_PLA 80
 #define PRE_PAC 120
 
 
int nroTicket ();
float calcularPrecio(const char *);
void mostrarFaltante(const int, const char *);
void mostrarEntrada(const float, const int);
 
int obtenerUbicacionInt(const char *);
 
 int main () {
 	
 	char ubicacion [4], cond;
 	float precio, total;
 	int ubiXcap[3][3] = { 
	 	{ 3500 , 1000, 500 },
	 	{ 3500 , 1000, 500 },
	 	{ 3500 , 1000, 500 }
	}, dia, cantDiaTres = 0, cantTotal = 0;				 
	
	
	printf("Desea vender una entrada (S/N): ");
	fflush ( stdin );
	scanf( "%c", &cond );
	
 	while( cond == 's' || cond == 'S' ) {
 		
 		
 		printf("Ingrese el dia que desea asistir ( 1 / 2 /3 ): ");
 		fflush(stdin);
 		scanf("%d", &dia);
 		
 		printf("Ingrese la ubicacion deseada ( cam / pla / pac ): ");
 		fflush(stdin);
 		scanf("%s", &ubicacion);
 		
 		if( ubiXcap[ dia - 1 ][ obtenerUbicacionInt(ubicacion) ] > 0 ) {
 			precio = calcularPrecio( ubicacion );
 			mostrarEntrada( precio, nroTicket() );
 			ubiXcap[dia - 1][obtenerUbicacionInt(ubicacion)] --;
 			if(dia == 3)
			 	cantDiaTres ++;
			total += precio;
			cantTotal ++; 
		} else 
			mostrarFaltante(dia, ubicacion);
 		printf("Desea vender una entrada (S/N): ");
		fflush ( stdin );
		scanf( "%c", &cond );
	}
	
	
	system("cls");
	printf("\n\t\t\t\tResultados Finales \n\n");
	printf("Total de entradas vendidas dia 3: %d\n", cantDiaTres);
	printf("Total de entradas vendidas totales: %d\n", cantTotal);
	printf("Total recaudado: %.2f\n\n", total);
	system("Pause");

 	
 	return 0;
 }
 
 
 int nroTicket () {
 	static ticket = 0;
	ticket ++;
	return ticket;
 }
 
 float calcularPrecio(const char *ubi) {
 	if(!strcmpi(ubi, "cam"))
 		return 60;
 	if(!strcmpi(ubi, "pla"))
 		return 80;
 	return 120;
 }
 
 int obtenerUbicacionInt(const char * ubicacion) {
 	if(!strcmpi(ubicacion, "cam"))
 		return 0;
 	if(!strcmpi(ubicacion, "pla"))
 		return 1;
 	return 2;
 }
 
 void mostrarEntrada(const float precio, const int nroTicket) {
 	system("cls");
	printf("\n\t\t\t\tEntrada\n\n");
	printf("Precio: %.2f\n", precio);
	printf("NroTicket: %d\n\n", nroTicket);
	system("Pause");
	system("cls");
 }
 
 
 void mostrarFaltante(const int dia, const char * ubi) {
 	system("cls");
	printf("\n\t\t\t\tNo hay entradas disponibles \n\n");
	printf("Dia: %d\n", dia);
	printf("Ubicacion: %s\n\n", ubi);
	system("Pause");
	system("cls");
 }
 
 
