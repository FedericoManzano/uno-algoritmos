#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int 	legajo,
			km,
			cantidad;
	char 	categoria;
	float 	anticipo;
	char 	hayAnticipo;
} t_empleado;

typedef struct {
	float 	peaje,
			comida,
			monto;
} t_gasto;

typedef struct {
	t_empleado 	empleado;
	t_gasto 	gasto;
} t_viatico;



void inicializarViatico(t_viatico *);
void  calcularGasto(t_viatico *);
void incrementarVendedor2000(t_viatico *);
char verCategoria(t_viatico *);
int verKm(t_viatico *); 
void mostrarGastos(t_viatico *);
char condicionFin ();
void ingresarDatos(t_viatico *);
void mostrarCantVendedoresA2000(t_viatico *);




