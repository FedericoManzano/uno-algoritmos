
#include <stdio.h>
#include <stdlib.h>
#include <ordenamiento.h>
#include <time.h>


int comp_int(const void *e1, const void *e2);
int comp_float(const void *e1, const void *e2);
int comp_car(const void *e1, const void *e2);

void titulo(char * tit);

void pausar();
int cargarEnteros(int *vi);
int mostrarEnteros(int *vi, int ce);

int cargarReales(float *vi);
int mostrarReales(float *vi, int ce);

int cargarCaracteres(char *vi);
int mostrarCar(char *vi, int ce);


void ordenarGenerico(char *tit, int tipo ,t_ord_gen ordenar);
void pbaGenerarPrueba(char * tit, t_ord ordenar);

