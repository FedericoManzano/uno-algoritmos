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
 


typedef struct {
	int 	nroTicket;
	float 	precio;
}t_entrada;


typedef struct {
	int 	dia;
	int 	ubicacion;
	int 	campo;
}t_festival;

typedef struct {
	int capacidad[MAX][MAX];
}t_estadio;

typedef struct {
	float 		total;
	int 		cantCampo;
	int 		totalEntradas;
}t_resultados;

typedef struct {
	t_resultados 	resultados;
	t_estadio 		estadio;
	t_festival 		festival;
	t_entrada 		entrada;
}t_venta;

char condicionFin ( ) ;
void crearVentas( t_venta * );
void  ingresarUbicacion( t_venta *);
float calcularPrecio( t_venta * );
void mostrarFaltaEspacio( t_venta * );
void mostrarTicket( t_venta * );
void mostrarResultadosFinales (const t_venta *);
