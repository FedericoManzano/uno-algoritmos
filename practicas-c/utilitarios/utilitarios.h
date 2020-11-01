#include <stdio.h>
#include <stdlib.h>


typedef struct {
	char codigo[10],
		 modelo[45];
	float importe;
}t_automotor;


typedef struct {
	char codigo[10];
	int cuota;
	float monto;
}t_cuotas;

typedef void (*formato_binario)(const void *);
typedef char *(* ruta_modo)();


void mostrarArchivoBinario(FILE *,formato_binario, void *, int);
int aperturaDeArchivos(FILE **, ruta_modo, ruta_modo);


