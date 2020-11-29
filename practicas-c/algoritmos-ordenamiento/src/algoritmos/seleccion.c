#include <ordenamiento.h>


/**
	Funcion utilitaria para el algoritmo 
	ordenar por seleccion se encarga de buscar el 
	valor minimo dentro del arreglo a partir de un indice 
	pasado por parametro.
	@param int * arr (arreglo al cual se quiere encontrar el minimo)
	@param inicio primer elemento a partir del que se quiere buscar el menor elemento
	@param ce cantidad de elementos totales del arreglo
	@return menor indice donde se encuantra el menor elemento dentro del arreglo (int)
*/
int buscarMenor(int * arr, int inicio, int ce) {
	int menor = inicio;
	while(ce) {
		if(*(arr + inicio) < *(arr + menor) )
			menor = inicio;
		inicio ++;
		ce --;
	}
	return menor;
}

/**
	Algoritmo ordenar por seleccion 
	para tipos de datos enteros para realizar pruebas 
	y evaluar el rendimiento del algoritmo
	@param arr direccion del primer elemento del arreglo
	@param ce cantidad de elementos del arreglo
*/
void seleccion(int * arr, int ce) {
	int menor;
	int aux;
	int indice = 0;
	while(ce) {
		menor = buscarMenor(arr, indice, ce);
		if(*(arr + menor) != *(arr + indice) ) {
			aux = *(arr + indice);
			*(arr + indice) = *(arr + menor);
			*(arr + menor) = aux;
		}
		ce --;
		indice ++;
	}
}


int buscarMenor_gen(void * arr, int inicio, int ce, int tam, t_cmp comp) {
	int menor = inicio;
	while(ce) {
		if(comp(arr + inicio, arr + menor) < 0) 
			menor = inicio;
		inicio += tam;
		ce --;
	}
	return menor;
}

/**
	Algoritmo de seleccion para ordenar cualquier tipo de dato
	a través de un puntero a una funcion de comparación que ingresa por 
	parametro. 
*/
void seleccion_gen(void * arr, int ce, size_t tam, t_cmp comp) {
	void * aux;
	int menor;
	int indice = 0;
	while(ce) {
		menor = buscarMenor_gen(arr,indice, ce, tam, comp );
		
		if( comp(arr + indice,arr + menor ) ) {
			aux = malloc(sizeof(tam));
			memcpy(aux, arr + indice, tam);
			memcpy(arr + indice, arr + menor, tam);
			memcpy(arr + menor, aux, tam);
			free(aux);
		}
		
		ce --;
		indice += tam;
	}
}



