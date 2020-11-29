#include <ordenamiento.h>

/**
	Algoritmo de inserción recibe solo un arreglo de enteros
	se utiliza en este caso solo para pruebas de estres 
	CC: O(n^2) INEFICIENTE
	prueba: 100000 valores enteros random. 
*/
void insercion(int * arr, int ce) {
	int indice 		= 1, 
		pasadas 	= 0, 
		aux, 
		atras 		= indice - 1, 
		elemento;

	while(ce - 1) {
		elemento = *(arr + indice);
		while(atras != -1 && elemento < *(arr + atras)) {
			aux = *(arr + atras);
			*(arr + atras) = elemento;
			*(arr + indice) = aux;
			indice = atras; 
			atras --;
		}
		pasadas ++;
		indice = pasadas + 1;
		atras = indice - 1;
		ce --;
	}
}


/**
	Algoritmo de inserción para ordenar cualquier tipo de dato
	a través de un puntero a una funcion de comparación que ingresa por 
	parametro. 
*/
void insercion_gen(void  * arr, int ce, const size_t tam, t_cmp comp) {
	int indice 		= 1, 
		pasadas 	= 0, 
		atras 		= indice - 1;
		
		
	void *elemento, *aux;
	while(ce - 1) {
		elemento = malloc(tam);
		memcpy(elemento,arr + indice*tam, tam );
		while(atras != -1 && comp(elemento, arr + atras*tam) < 0) {
			aux = malloc(tam);
			memcpy(aux,arr + atras*tam, tam );
			memcpy(arr + atras*tam,elemento, tam );
			memcpy(arr + indice *tam,aux, tam );
			indice = atras; 
			atras --;
			free(aux);
		}
		pasadas ++;
		indice = pasadas + 1;
		atras = indice - 1;
		ce --;
		free(elemento);
	}
}





