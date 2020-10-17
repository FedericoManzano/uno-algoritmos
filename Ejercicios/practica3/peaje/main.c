 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
 #include <string.h>
 
 #define HOR_PICO(X)( (X) == 'A' || (X) == 'a' )
 #define HOR_NOR(X)(  (X) == 'B' || (X) == 'b' )
 
 #define MOTO_BASE 			5
 #define AUTO_BASE 			10
 #define CAMIONETA_BASE 	15
 #define CAMION_BASE 		20
 
 #define LUNES 				1
 #define MARTES 			2
 #define MIERCOLES 			3
 #define JUEVES 			4
 #define VIERNES 			5
 #define SABADO 			6
 #define DOMINGO 			7
 
 char condicionFin();
 float calcularMonto( const float , const int , const char  );
 float calcularVuelto(const float, const float);
 void mostrarResultados(const float, const float);
  
 int main () {
 	char categoria [25];
 	unsigned int dia;
 	char horario;
 	float importe;
 	float monto;
 	float vuelto;
 	float base;
 	
 	
 	char cond = condicionFin();
 	
 	while ( cond == 'S' || cond == 's' ) {
 		printf("Ingrese la categoria del vehiculo: ");
 		fflush( stdin );
 		gets( categoria );
 			
 		if( !strcmpi(categoria, "moto") )
 			base = MOTO_BASE;
	 	else if( !strcmpi(categoria, "auto") )
	 		base = AUTO_BASE;
	 	else if( !strcmpi(categoria, "camioneta") )
	 		base = CAMIONETA_BASE;
	 	else if( !strcmpi(categoria, "camion") )
	 		base = CAMION_BASE;
		
 		printf("Ingrese el dia de la semana: ");
 		scanf( "%d", &dia );
		
 		printf("Ingrese el horario: ");
 		fflush(stdin);
 		scanf( "%c", &horario );
		
 		printf( "Ingrese el importe: " );
 		scanf( "%f", &importe );
 		
 		monto = calcularMonto( base,dia,horario );
 		vuelto = calcularVuelto( importe, monto );
 		
 		mostrarResultados( monto, vuelto );
 		
 		cond = condicionFin();
	}
 	
	return 0;
 } 
 
 
 
 char condicionFin() {
 	char cond;
 	printf("Desea procesar un ingreso (S/N): ");
 	fflush(stdin);
 	scanf("%c", &cond);
 	return cond;
 }
 
 float calcularMonto( const float base, const int dia, const char horario ) {
 	if( dia >= LUNES && dia <= VIERNES && HOR_PICO( horario ) ) 
 		return base + ( base * 0.2 );
	return base - ( base * 0.2 );
 }
 
 float calcularVuelto( const float importe, const float monto ) {
 	return importe - monto;
 }
 
 void mostrarResultados( const float monto, const float vuelto ) {
 	system("cls");
 	printf("*****************************************\n");
 	printf("Total a cobrar: %.2f\n", monto);
 	printf("Vuelto: %.2f\n", vuelto);
 	printf("*****************************************\n");
 	
 }
