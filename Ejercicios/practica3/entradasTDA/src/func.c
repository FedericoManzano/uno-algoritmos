#include "../include/header.h"

void crearVentas(t_venta *ventas) {
	int i, j;
	for(i = 0; i < MAX; i ++) {
		for(j = 0; j < MAX; j ++) {
			if(j == CAMPO)
			 	ventas->estadio.capacidad[i][j] = CAP_CAM; // 3500	
			else if(j == PLATEA)
				ventas->estadio.capacidad[i][j] = CAP_PLA; // 1000
			else if(j == PALCO)
				ventas->estadio.capacidad[i][j] = CAP_PAL; // 500	
		}
	}
	
	ventas->resultados.cantCampo = 0;
	ventas->resultados.total = 0;
	ventas->resultados.totalEntradas = 0;
}

int hayEspacio( const t_venta *venta ) {
	return venta->estadio.capacidad[venta->festival.dia][venta->festival.ubicacion] > 0;
}

 void  ingresarUbicacion( t_venta *venta) {
 	char ubicacion [4];
 	int val = 0;
 	
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
		venta->festival.ubicacion = CAMPO;
	if( !strcmpi(ubicacion, "pla") )
		venta->festival.ubicacion = PLATEA;
	if( !strcmpi(ubicacion, "pal") )
		venta->festival.ubicacion = PALCO;
 }


 void ingresarDia (t_venta *venta) {
	do {
		printf("Ingrese el dia: ");
 		scanf("%d", &venta->festival.dia);
	} while( !DIA( venta->festival.dia ) );
	venta->festival.dia --;
 }
 
 
 int venderEntrada(t_venta *venta) {
 	if(hayEspacio(venta)) {
 		venta->entrada.nroTicket = nroTicket();
 		venta->entrada.precio = calcularPrecio(venta);
 		venta->estadio.capacidad[venta->festival.dia][venta->festival.ubicacion] --;
 		
 		if( venta->festival.dia == DIA_3 && venta->festival.ubicacion == CAMPO )  
			venta->resultados.cantCampo ++;
		venta->resultados.totalEntradas ++;
		venta->resultados.total += venta->entrada.precio;
		return 1;
	}
	return 0;
 }
 
 
  void mostrarResultadosFinales (const t_venta *venta) {
 	system("cls");
 	printf("=================================================\n");
 	printf("La cantidad de entradas de campo del dia 3 es: %d\n", venta->resultados.cantCampo);
 	printf("La cantidad total de entradas de los 3 dias es: %d\n", venta->resultados.totalEntradas);
 	printf("Recaudacion total: %.2f\n", venta->resultados.total);
 	printf("=================================================\n\n");
 	system("pause");
 }
 
 void mostrarTicket(t_venta *venta) {
 	system("cls");
 	printf("\n\t=============\n");
 	printf("\n\t* Ticket: %d\n", venta->entrada.nroTicket);
 	printf("\n\t* Precio: %.2f\n", venta->entrada.precio);
 	printf("\n\t=============\n");
 	system("pause");
 }
 
 
 float calcularPrecio(t_venta *venta) {
 	if(venta->festival.ubicacion == CAMPO)
 		return PRE_CAM;
 	if(venta->festival.ubicacion == PLATEA)
 		return PRE_PLA;
 	return PRE_PAL;
 }



 void mostrarFaltaEspacio(t_venta *venta) {
 	system("cls");
	printf("\nNo hay capacidad sificiente para esta ubicación en este dia.\n\n");
	system("pause");
 }
 
 
int nroTicket () {
 	static int ticket = 0;
 	ticket ++;
 	return ticket;
}

 char condicionFin () {
 	char op;
 	system("cls");
 	printf("Desea vender una entrada: ");
 	fflush(stdin);
 	scanf("%c", &op);
 	return op;
 }
 

