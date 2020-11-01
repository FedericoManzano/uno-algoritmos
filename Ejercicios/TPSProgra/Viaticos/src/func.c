#include "../include/include.h"


float calcularMonto( const float km, const float gastoComidas, const float gastoPeaje) {
	float monto;
	if( km > 2000 )
		monto = 2000 * 10 + ( km - 2000 ) * 5 + gastoComidas + gastoPeaje;
	else
		monto = km * 10 + gastoComidas + gastoPeaje;
	
	return monto;
}

int ingresarDatosEntrada( int * cEmp, char * cat, float * km, float * gc, float * gp, float * ant ) {
	printf("Ingresar el codigo del empleado: ");
	fflush(stdin);
	scanf("%d", cEmp);
	
	printf("Ingresar la categoria del empleado (V/J/G): ");
	fflush(stdin);
	scanf("%c", cat);
	
	
	printf("Ingresar los Km recorridos: ");
	fflush(stdin);
	scanf("%f", km);
	
	printf("Ingresar los gastos por comida: ");
	fflush(stdin);
	scanf("%f", gc);
	
	printf("Ingresar los gastos por peaje: ");
	fflush(stdin);
	scanf("%f", gp);
	
	if( *cat == 'v' || *cat == 'V' ) {
		printf("Ingresar el anticipo: ");
		fflush(stdin);
		scanf("%f", ant);
		return 1;
	}
	
	return 0;
	
}

void titulo( char * tit ) {
	system("cls");
	printf( "\n\t\t\t\t%s\n\n", tit );
}


char ingresarCondFin() {
	char op;
	printf("Desea realizar una venta (S/N): ");
	fflush(stdin);
	scanf("%c", &op);
	return op;
}


void mostrarGastoViatico( const float monto ) {
	if(monto < 0)
		printf("Importe a devolver $ %.2f \n\n", monto * -1);
	else
		printf("Importe a pagar $ %.2f \n\n", monto);
	system("pause");
}


void mostrarCantVendedores(const int cantVen) {
	printf("Vendedores que recorrieron mas de 2000 Km: %d\n\n", cantVen);
	system("pause");
}

