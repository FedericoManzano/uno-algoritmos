#include <ordenamiento.h>

/**
	Algoritmo de shellsort recibe solo un arreglo de enteros
	se utiliza en este caso solo para pruebas de estres 
	CC: O(n^1.25) EFICIENTE
	prueba: 100000 valores enteros random. 
*/
void shell(int * arr, int ce) {
	int intervalo = ce / 2,i,j, temp;
	
	while(intervalo > 0) {
		for(i = intervalo; i < ce; i ++) {
			temp = *(arr + i);
			j = i;
			
			while(j >= intervalo && *(arr + (j - intervalo) ) > temp) {
				*(arr + j) = *(arr + (j - intervalo));
				j -= intervalo;
			}
			*(arr + j) = temp;
		}
		intervalo /= 2;
	}
}




/**
	Algoritmo de shellsort para ordenar cualquier tipo de dato
	a través de un puntero a una funcion de comparación que ingresa por 
	parametro. 
*/
void shell_gen(void * arr, int ce, const size_t tam, t_cmp comp) {
	int intervalo = ce / 2,i,j;
	void * temp;
	
	
	while(intervalo > 0) {
		for(i = intervalo; i < ce; i ++) {
			temp = malloc(tam);
			memcpy(temp, arr + (i * tam), tam);
			j = i;
			
			while(j >= intervalo && comp(temp, (arr + (j - intervalo)*tam )) < 0) {
				memcpy(arr + j*tam, arr + (j - intervalo)*tam, tam);
				j -= intervalo;
			}
			memcpy(arr + j*tam, temp, tam);
			free(temp);
		}
		intervalo /= 2;
	}
}
