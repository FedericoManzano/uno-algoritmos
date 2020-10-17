
#include "../include/vectores.h"


void pisarElemento(void *arreglo, int *ce,int pos, size_t tam) {
	int j;
	for( j = pos; j < *ce - 1; j ++ ) 
		memcpy( (arreglo + (j * tam)), (arreglo + ((j + 1)* tam)), tam );
	( *ce )--;
}

int eliminarElemento(void * arreglo, int *ce,void *elemento, size_t tam, t_cmp comp) {
	int i = 0;
	if( !*ce )
		return 0;
	
	while( i < *ce && comp(elemento, (arreglo + (i * tam))) )
		i ++;
	
	if(i < *ce) {
		pisarElemento(arreglo, ce, i, tam);
		return 1;
	}
	return 0;
	
}

int borrarDuplicados( void * arreglo, int *ce, size_t tam, t_cmp comp ) {
	int i, j, borrados = 0;
	if( !*ce )
		return 0;
	for( i = 0; i < *ce; i ++ ) {
		for( j = i + 1; j < *ce; j ++ ){
			if(!comp(arreglo + (i * tam), arreglo + (j * tam) )) {
				pisarElemento(arreglo, ce, j, tam);
				borrados ++;
			}	
		}	
	}
	return borrados;
}

int eliminarPosicion(void * arreglo, int *ce,int pos, size_t tam, t_cmp comp) {
	if( !*ce )
		return 0;
	pisarElemento(arreglo, ce, pos, tam);
}

void qs(void *arreglo, int ini,int fin, size_t tam, t_cmp comp) {
	int i = ini;
	int j = fin;
	void *aux = malloc(sizeof(tam));
	int pivote = (i + j) / 2;
	do   {
		while( comp((arreglo + (pivote * tam)), (arreglo + (i * tam))) > 0 && i < fin)
			i ++;
		while( comp((arreglo + (pivote * tam)), (arreglo + (j * tam))) <= 0 && j > ini)
			j --;
		if(i <= j) {
			memcpy(aux, (arreglo + (i * tam)), tam);
			memcpy((arreglo + (i * tam)), (arreglo + (j * tam)), tam);
			memcpy((arreglo + (j * tam)), aux, tam);
			i ++;
			j --;
		}
	}while(i <= j);
	free(aux);
	if(ini<j)
		qs(arreglo,ini,j, tam,comp);
    if(fin > i)
		qs(arreglo,i,fin, tam,comp );
}

void q_sort(void *arreglo, int ce, size_t tam, t_cmp comp) {
	qs(arreglo, 0, ce -1, tam, comp);
}


int menor(void *arreglo, int ce, int inicio, size_t tam, t_cmp comp) {
	int menor = inicio;
	void *aux = malloc(sizeof(tam));
	while(inicio < ce) {
		if(comp((arreglo + (inicio * tam)), (arreglo + (menor * tam))) < 0)
			menor = inicio;
		inicio ++;
	}
	free(aux);
	return menor;
}

void seleccion(void *arreglo, int ce, size_t tam, t_cmp comp) {
	void *aux = malloc(sizeof(tam));
	int inicio = 0;
	int menorValor;
	while(inicio < ce) {
		menorValor = menor(arreglo,ce,inicio,tam,comp);
		if(menorValor != inicio) {
			memcpy(aux, (arreglo + (inicio * tam)), tam);
			memcpy((arreglo + (inicio * tam)), (arreglo + (menorValor * tam)), tam);
			memcpy((arreglo + (menorValor * tam)), aux, tam);
		}
		inicio ++;
	}
	free(aux);
}

int insertarAlFinal(void * arreglo, int *ce,void *elemento, size_t tam) {
	if(*ce >= TAM_MAX) 
		return 0;
	memcpy(arreglo + (*ce * tam), elemento, tam);
	( *ce ) ++;
	return 1;
}

int insertarEnOrden(void * arreglo, int *ce,void *elemento, size_t tam, t_cmp comp) {
	int i = 0;
	int j;
	if(*ce >= TAM_MAX) 
		return 0;
	while(i < *ce && comp(arreglo + (i * tam), elemento) < 0)
		i ++;
	for(j = *ce -1; j >= i; j -- ) 
		memcpy(arreglo + ((j + 1)* tam), arreglo + (j * tam), tam);
	j ++;
	memcpy(arreglo + (j * tam), elemento, tam);
	( *ce ) ++;
	return 1;
}

int insertarEnOrden_sdup(void * arreglo, int *ce,void *elemento, size_t tam, t_cmp comp) {
	int i = 0, j;
	if(*ce >= TAM_MAX) 
		return 0;
	while(i < *ce && comp(arreglo + (i * tam), elemento) < 0)
		i ++;
	if( i < *ce && comp(arreglo + ( i * tam ), elemento ) == 0)
		return 2;
	for(j = *ce -1; j >= i; j -- ) 
		memcpy(arreglo + (( j + 1 ) * tam), arreglo + (j * tam), tam);
	j ++;
	memcpy(arreglo + (j * tam), elemento, tam);
	( *ce ) ++;
	return 1;
}
