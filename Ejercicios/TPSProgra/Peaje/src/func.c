#include "../include/header.h"

float calcularImporte (const float base, const int dia, const char horario) {
	float monto;
	if( ES_PICO( horario ) && LUN_A_VIE( dia ) ) 
		monto = base + (base * 0.2);
	else
		monto = base - (base * 0.2);
	return monto;
}

float calcularVuelto ( const float importeEnt, const float importeCob ) {
	return importeEnt - importeCob;
}

void mostarImporte (const float importe, const float vuelto) {
	titulo("Mostrar Importe Vuelto");
	printf("\tEl importe cobrado es $ %.2f\n", importe);
	printf("\tEl vuelto a entregar es $ %.2f\n\n", vuelto);
	system("pause");
}

void mostarResultados (const float total, const int cantidad) {
	titulo("Resultados Finales");
	printf("\tCantidad de autos en hora pico %d\n", cantidad);
	printf("\tTotal recaudado %.2f\n\n", total);
	system("pause");
}

void titulo(const char *tit) {
	system("cls");
	printf("\n\t\t\t\t%s\n\n", tit);
}

void cargarEntradas(char * categoria, int * dia, char * horario, float * importeEnt) {
	int val = 0;
	do {
		if(!val)
			printf("Ingrese la categoria del vehiculo (MOTO/AUTO/CAMIONETA/CAMION): ");
		else
			printf("Error ingrese nuevamente (MOTO/AUTO/CAMIONETA/CAMION): ");
		fflush(stdin);
		gets(categoria);
		val =  1;
	} while
	(
		strcmpi(categoria, "Auto") 		&& 
		strcmpi(categoria, "Moto") 		&& 
		strcmpi(categoria, "Camioneta") && 
		strcmpi(categoria, "Camion")
	);
	val = 0;
	do {
		if(!val)
			printf("Ingrese dia de la semana (1/2/3/4/5/6/7): ");
		else
			printf("Error ingrese nuevamente (1/2/3/4/5/6/7): ");
		scanf("%d", dia);
		val =  1;
	} while ( !DIA_SEMANA(*dia) );
	
	val = 0;
	do {
		if(!val)
			printf("Ingrese el horario (A/P): ");
		else
			printf("Error ingrese nuevamente (A/P): ");
		fflush(stdin);
		scanf("%c", horario);
		val =  1;
	} while( !HORARIO_VAL( *horario ) );
	
	val = 0;
	do {
		if(!val)
			printf("Ingrese el importe entregado ($): ");
		else
			printf("Error ingrese nuevamente ($): ");
		scanf("%f", importeEnt);
		val =  1;
	} while	( *importeEnt <= 0 );
}

float obtenerBase(char *categoria) {
	if(!strcmpi(categoria, "Moto"))
		return BASE_MOTO;
	if(!strcmpi(categoria, "Auto"))
		return BASE_AUTO;
	if(!strcmpi(categoria, "Camioneta"))
		return BASE_CAMIONETA;
	return BASE_CAMION;
}

char condicionFin() {
	char op;
	printf("Desea vender un pase (S/N): ");
	fflush(stdin);
	scanf("%c", &op);
	return op;
}


