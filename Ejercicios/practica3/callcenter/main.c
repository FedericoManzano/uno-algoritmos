#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define SABADO	 	6



void condicionFin(char * cond);
float calcularImporte( const int,const int, const int );
int kgPedidos (const int, const int);
void mostrarPedido(const int, const float);



int main () {
	
	char codigoCliente[9], op[3];
	int codigoProd, 
		cantProd, 
		baseHielo = 50, 
		baseService = 500, 
		stock = 2000, 
		nroPedido = 0,
		pedido = 0,
		dia,
		cantSabados = 0;
	float importe, total = 0;
	
	
	condicionFin(op);
	
	while( !strcmpi(op, "Si") ) {
		
		
		printf("Ingrese el codigo de cliente: ");
		fflush(stdin);
		gets(codigoCliente);
		printf("Ingrese el codigo de producto: ");
		scanf("%d", &codigoProd);
		printf("Ingrese el dia de entrega: ");
		scanf("%d", &dia);
		
		
		if(codigoProd != 3) {
			printf("Ingrese la cantidad: ");
			scanf("%d", &cantProd);
			
			if(	stock >= kgPedidos( codigoProd,cantProd ) ) {
				importe = calcularImporte(codigoProd,baseHielo,cantProd);
				stock -= kgPedidos(codigoProd,cantProd);
				pedido = 1;
				nroPedido ++;
			} else {
				system("cls");
				printf("No se registro pedido\n\n");
				system("pause");
			}
		} else {
			cantProd = 1;
			importe = calcularImporte(codigoProd,baseService,cantProd);
			pedido = 1;
			nroPedido ++;
			if(dia == SABADO)
				cantSabados ++;
		}
		
		if(pedido) {
			mostrarPedido(nroPedido, importe);
			pedido = 0;
			total += importe;
		}
			
		condicionFin(op);
	}
	
	
	system("cls");
	printf("\n\tTotal: %.2f\n", total);
	printf("\tCantidad de service dia sabado: %d\n", cantSabados);
	system("pause");
	
	
	return 0;
}

float calcularImporte( const int codigoProducto,const int base , const int cantProd ) {
	float importe;
	int kg;
	if(codigoProducto == 3)
		return (float)base;
	kg = kgPedidos(codigoProducto, cantProd);
	if(kg <= 100) 
		importe = ( base * kg ) - ( base * kg ) * 0.1;
	else 
		importe = ( base * kg ) - ( base * kg ) * 0.25;
	return importe;
}

int kgPedidos (const int codigoProducto, const int cantProd)  {
	if( codigoProducto == 1 ) 
		return cantProd * 2;
	return cantProd * 10;
}

 void condicionFin(char * cond) {
 	printf("Desea realizar una venta (S/N): ");
 	fflush(stdin);
 	gets(cond);
 }
 
 void mostrarPedido(const int codigoPedido, const float importe) {
 	system("cls");
 	printf("El pedido: %d y su importe %.2f \n\n", codigoPedido, importe);
 	system("pause");
 	system("cls");
 }
