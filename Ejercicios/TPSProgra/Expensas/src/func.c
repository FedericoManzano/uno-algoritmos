#include "../include/header.h"


void titulo(const char * t) {
	system("cls");
	printf("\n\t\t\t%s\n\n", t);
}

char condicionFin () {
	char op;
	printf("Desea calcular gastos de un depto (S/N): ");
	fflush(stdin);
	scanf("%c", &op);
	return op;
}

float montoExpensas(const char categoria, const int uso, const char cochera) {
	float monto = 0;
	if(	PISO(categoria)	)
		monto += MONTO_PISO;
	if(SEMI_PISO(categoria))
		monto += MONTO_SEMI_PISO;
	if( DOS_AMB(categoria) ) 
		monto += MONTO_DOS_AMB;
	if( MONO_AMB(categoria) ) 
		monto += MONTO_MONO_AMB;
	if( ES_PROFESIONAL(uso) )
		monto += MONTO_PROFESIONAL;
	if( cochera == 's' || cochera == 'S' )
		monto += MONTO_COCHERA;
	return monto;
}


void ingresarDatosEntrada (int *cod, char *cat, int *uso, char *coch, char *multas) {
	printf("Ingrese el codigo del depto: ");
	scanf("%d", cod);
	
	printf("Ingrese la categoria del depto (P/S/D/M): ");
	fflush(stdin);
	scanf("%c", cat);
	
	printf("Es para uso profesional (1:si/0:no): ");
	scanf("%d", uso);
	
	printf("Dispone de cochera (S/N): "); 
	fflush(stdin);
	scanf("%c", coch);
	
	printf("Acumulo multas (S/N): "); 
	fflush(stdin);
	scanf("%c", multas);
}

void mostrarGastosDepto(int cod, float monto) {
	titulo("Gastos del depto");
	printf("\tEl depto %d adeuda %.2f\n\n", cod, monto);
	system("pause");
}

void mostrarResultadoFinal(int cantidad) {
	titulo("Resultados Finales");
	printf("\tLa cantidad de deptos dos ambientes de uso prof. son %d\n\n", cantidad);
	system("pause");
}

float ingresarMontoMultas() {
	float multas;
	printf("Ingrese el monto de multas: ");
	scanf("%f", &multas);
	return multas;
}

