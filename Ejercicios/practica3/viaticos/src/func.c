
#include "../include/header.h"

void inicializarViatico(t_viatico *viatico) {
	viatico->empleado.cantidad = 0;
}

void  calcularGasto(t_viatico *viatico) {
	if(viatico->empleado.km > 2000) 
		viatico->gasto.monto = 2000 * 10 + ( viatico->empleado.km - 2000 ) * 5;
	else 
		viatico->gasto.monto = 2000 * 10;
	viatico->gasto.monto += viatico->gasto.comida + viatico->gasto.peaje;
}

void incrementarVendedor2000(t_viatico * viatico) {
	viatico->empleado.cantidad ++;
}

char verCategoria(t_viatico * viatico) {
	return viatico->empleado.categoria;
}

int verKm(t_viatico * viatico) {
	return viatico->empleado.km;
}

void mostrarGastos(t_viatico *viatico) {
	system("cls");
	float monto = viatico->gasto.monto - viatico->empleado.anticipo;
	if( viatico->empleado.hayAnticipo == 's' ||  viatico->empleado.hayAnticipo == 'S' ) {
		monto = viatico->gasto.monto - viatico->empleado.anticipo;
		if(monto < 0)
			printf("\n\n\tImporte a devolver %.2f por empleado %d\n\n" , monto, viatico->empleado.legajo);
		else
			printf("\n\n\tImporte a pagar %.2f al empleado %d\n\n" , monto, viatico->empleado.legajo);
	} else 
		printf("\n\n\tImporte a pagar %.2f al empleado %d\n\n" , monto, viatico->empleado.legajo);
	
	system("pause");
	system("cls");	
}


void mostrarCantVendedoresA2000(t_viatico *viatico) {
	system("cls");
	printf("\n\n\tCantidad de vendedores que recorrieron mas de 2000 KM: %d\n\n" , viatico->empleado.cantidad);
	system("pause");
	system("cls");	
}


 void ingresarDatos(t_viatico *viatico) {
 	printf("Ingrese el nro de legajo: ");
 	scanf("%d", &viatico->empleado.legajo);
 	
 	printf("Ingrese su categoria: ");
 	fflush(stdin);
 	scanf("%c", &viatico->empleado.categoria);
 	
 	printf("Ingrese km recorridos: ");
 	scanf("%d", &viatico->empleado.km);
 	
 	printf("Ingrese gastos de comida: ");
 	scanf("%f", &viatico->gasto.comida);
 	
 	printf("Ingrese gastos de peaje: ");
 	scanf("%f", &viatico->gasto.peaje);
 	
 	printf("Hay anticipo ?: ");
 	fflush(stdin);
 	scanf("%c", &viatico->empleado.hayAnticipo);
 	
 	if(viatico->empleado.hayAnticipo == 's' || viatico->empleado.hayAnticipo == 'S') {
 		printf("Ingrese el monto de anticipo: ");
 		scanf("%f", &viatico->empleado.anticipo);
	}
 }
 
 
 char condicionFin () {
 	char op;
 	system("cls");
 	printf("Desea calcular viatico de un empleado (S/N): ");
 	fflush(stdin);
 	scanf("%c", &op);
 	return op;
 }
 
