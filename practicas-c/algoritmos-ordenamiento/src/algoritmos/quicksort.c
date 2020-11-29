#include <ordenamiento.h>

void qs(int * arr, int inicio, int fin) {
	int i = inicio;
	int j = fin;
	int pivote = (i + j )/ 2, aux;
	
	
	do {
		while(i < fin && *(arr + i) < *(arr + pivote) ) 
			i ++;
		while(j > inicio && *(arr + j) > *(arr + pivote))
			j --;
		if(i <= j ) {
			aux = *(arr + j);
			*(arr + j) = *(arr + i);
			*(arr + i) = aux;
			i ++;
			j --;
		}
	} while(i < j);
	
	if(i <= fin)
		qs(arr,i,fin);
	if(j >= inicio)
		qs(arr,inicio,j);
	
}



/**
	Algoritmo de quicksort recibe solo un arreglo de enteros
	se utiliza en este caso solo para pruebas de estres 
	CC: O(n log(n)) MUY EFICIENTE
	prueba: 100000 valores enteros random. 
*/
void quicksort (int * arr, int ce) {
	qs(arr,0,ce-1);
}




void qs_gen(void * arr, int inicio, int fin, const size_t tam, t_cmp comp) {
	int i = inicio;
	int j = fin;
	int pivote = (i + j )/ 2;
	void * aux;
	
	do {
		while(i < fin && comp(arr + i*tam,  arr + (pivote*tam)) < 0 ) 
			i ++;
		while(j > inicio && comp(arr + j*tam,  arr + pivote*tam) > 0 )
			j --;
		if(i <= j ) {
			aux = malloc(tam);
			memcpy(aux,arr + j* tam, tam);
			memcpy(arr + j*tam,arr + i * tam, tam);
			memcpy(arr + i*tam,aux, tam);
			i ++;
			j --;
			free(aux);
		}
	} while(i < j);
	
	if(i <= fin)
		qs_gen(arr,i,fin,tam, comp );
	if(j >= inicio)
		qs_gen(arr,inicio,j,tam,comp);
	
}


/**
	Algoritmo de quicksort para ordenar cualquier tipo de dato
	a través de un puntero a una funcion de comparación que ingresa por 
	parametro. 
*/
void quicksort_gen (void * arr, int ce, const size_t tam, t_cmp comp) {
	qs_gen(arr,0,ce-1, tam, comp);
}


