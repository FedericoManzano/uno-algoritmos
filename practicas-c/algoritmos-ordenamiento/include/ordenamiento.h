#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipo del puntero a función para que 
// se utiliza para comparar
typedef int (* t_cmp)(const void *, const void *);




// Punteros funciones utilitarias para este programa
// no tienen que ver con los algoritmos de ordenamiento
typedef void (* t_ord)(int *, int);
typedef void (* t_ord_gen)(void *, int, const size_t, t_cmp);
typedef void (* t_prueba)();


/**
	Algoritmo de selección para pruebas de rendimiento
*/
void seleccion(int * arr, int ce);

/**
	Algoritmo de selección para ordenar cualquier tipo de arreglo
	recibe el tamaño del dato a ordenar y una funcion de comparación 
	para definir que valor es mayor o menor dentro del arreglo.
*/
void seleccion_gen(void * arr, int ce, size_t tam, t_cmp comp);


/**
	Algoritmo de burbujeo para pruebas de rendimiento
*/
void burbuja(int * arr, int ce);

/**
	Algoritmo de burbujeo para ordenar cualquier tipo de arreglo
	recibe el tamaño del dato a ordenar y una funcion de comparación 
	para definir que valor es mayor o menor dentro del arreglo.
*/
void burbuja_gen(void  * arr, int ce, const size_t tam, t_cmp comp);

/**
	Algoritmo de inserción para pruebas de rendimiento
*/
void insercion(int * arr, int ce);


/**
	Algoritmo de inserción para ordenar cualquier tipo de arreglo
	recibe el tamaño del dato a ordenar y una funcion de comparación 
	para definir que valor es mayor o menor dentro del arreglo.
*/
void insercion_gen(void * arr, int ce, const size_t tam, t_cmp comp);


/**
	Algoritmo de quicksort para pruebas de rendimiento
*/
void quicksort (int * arr, int ce);

/**
	Algoritmo de quicksort para ordenar cualquier tipo de arreglo
	recibe el tamaño del dato a ordenar y una funcion de comparación 
	para definir que valor es mayor o menor dentro del arreglo.
*/
void quicksort_gen (void * arr, int ce, const size_t tam, t_cmp comp);


/**
	Algoritmo de shellsort para pruebas de rendimiento
*/
void shell(int * arr, int ce);


/**
	Algoritmo de shellsort para ordenar cualquier tipo de arreglo
	recibe el tamaño del dato a ordenar y una funcion de comparación 
	para definir que valor es mayor o menor dentro del arreglo.
*/
void shell_gen(void * arr, int ce, const size_t tam, t_cmp comp);

