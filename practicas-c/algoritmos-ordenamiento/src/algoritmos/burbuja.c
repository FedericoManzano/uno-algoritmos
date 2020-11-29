#include <ordenamiento.h>


/**
	Algoritmo de burbujeo recibe solo un arreglo de enteros
	se utiliza en este caso solo para pruebas de estres 
	CC: O(n^2) MUY INEFICIENTE
	prueba: 100000 valores enteros random. 
*/
void burbuja(int * arr, int ce) {
	int i, 
		j, 
		aux;
	
	for(i = 0; i < ce; i ++) {
		for(j = i; j < ce - 1; j ++) {
			if(*(arr + i) > *(arr + j + 1) ) {
				aux = *(arr + i);
				*(arr + i) = *(arr + j + 1);
				*(arr + j + 1) = aux;
			}
		}	
	}
}

/**
	Algoritmo de burbujeo para ordenar cualquier tipo de dato
	a través de un puntero a una funcion de comparación que ingresa por 
	parametro. 
*/
void burbuja_gen(void  * arr, int ce, const size_t tam, t_cmp comp) {
	int i, j, indice = 0;
	void * aux;
	for(i = 0; i < ce; i ++) {
		for(j = i; j < ce - 1; j ++) {
			if(comp(arr + i*tam, arr + (j + 1) * tam) > 0) {
				aux = malloc(sizeof(tam));
				memcpy(aux, arr + i*tam, tam);
				memcpy(arr + i*tam, arr + (j + 1)*tam, tam);
				memcpy(arr + (j + 1)*tam, aux, tam);
				free(aux);
			}
		}	
	}
}


