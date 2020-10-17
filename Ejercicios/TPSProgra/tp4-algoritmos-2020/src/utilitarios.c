#include "../include/utilitarios.h"

void titulo(char * titulo) {
	system("cls");
	printf("\n\t\t\t\t%s\n\n", titulo);
}

void pausar() {
	printf("\n\n");
	system("pause");
}


int indiceMenorVector(int * vector, int ce) {
	int menor = 0, i;
	for( i = 1; i < ce; i ++ )
		if(vector[menor] > vector[i])
			menor = i;
	return menor;
}

int indiceMayorVector(int * vector, int ce) {
	int mayor = 0, i;
	
	for( i = 1; i < ce; i ++ )
		if(vector[mayor] < vector[i])
			mayor = i;
	return mayor;
}

int cantPares(int * vector, int ce) {
	int i ;
	int cantidadPares = 0;
	for(i = 0; i < ce; i ++) 
		if(vector[i] % 2 == 0)
			cantidadPares ++;
	return cantidadPares;
}


void mostrarArregloEnteros(int *arreglo, int ce) {
	int i;
	printf("[ ");
	for(i = 0; i < ce; i ++) 
		printf("%d, ", arreglo[i]);
	printf(" ]\n\n");
}

void pedirVertorEnteros(int *arreglo, int ce) {
	int i;
	for(i= 0; i < ce; i ++) {
		printf("Ingrese arr[%d]: ", i);
		scanf( "%d", &arreglo[i] );
	}
}


int sumaVectorEnteros( int * vector, int ce) {
	int i;
	int acum = 0;
	for(i = 0; i < ce; i ++)
		acum += vector[i];
	return acum;
} 

int restaVectorEnteros( int * vector, int ce) {
	int i;
	int resta = vector[0];
	for( i = 1; i < ce; i ++ )
		resta -= vector[i];
	return resta;
}

long mulVectorEnteros( int * vector, int ce) {
	int i;
	long acum = 1;
	for(i = 0; i < ce; i ++)
		acum *= vector[i];
	return acum;
} 

float divVectorEnteros( int * vector, int ce) {
	int i;
	int division = vector[0];
	for(i = 0; i < ce; i ++) {
		if( vector[i] != 0 )
			division /= vector[i];
		else 
			return -1;
	}
	return division;
} 


void leerMatriz(int matriz[][3], int filas, int cols) {
	int i, j;
	for(i = 0; i < filas; i ++) {
		for(j = 0; j < cols; j ++) {
			printf("Ingrese el valor mat[%d][%d]: ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
}


void mostrarMatriz(int matriz[][3], int filas, int cols) {
	int i,j;
	printf("Matriz %d X %d\n\n", filas, cols);
	for ( i = 0; i < filas; i ++ ) {
		printf("| ");
		for( j = 0; j < cols; j ++) 
			printf("%3d", matriz[i][j]);
		printf(" |");
		printf("\n");
	}
}


int calcularMayorMatriz(int matriz[][3], int fila, int tam) {
	int i;
	int mayor = matriz[fila-1][0];
	for(i = 1; i < tam; i ++) {
		if(matriz[fila-1][i] > mayor) 
			mayor = matriz[fila-1][i];
	}
	
	return mayor;
}


int esVocal(char car) {
	return     car == 'a' || car == 'A' 
			|| car == 'e' || car == 'E' 
			|| car == 'i' || car == 'I' 
			|| car == 'o' || car == 'O'
			|| car == 'u' || car == 'U';
}


int str_cmp(const char *s1, const char *s2) {
	if(!s1 || !s2)
		return 0;
	while(*s1 && *s2 && *s1 == *s2){
		s1 ++;
		s2 ++;
	}
	return *s1 - *s2;
}


void multiplicarMatrices(int *matriz1, int *matriz2, int tam) {
	int i,j,k;
	int res[3][3] = {0};
	
	for(i = 0; i < tam; i ++) 
		for(k = 0; k < tam; k ++) 
			for(j = 0; j < tam; j ++) 
				res[i][k] += *(matriz1 + (i * tam) + j) * *(matriz2 + (j * tam) + k);		
	
	titulo("Resultado Multiplicacion");
	
	mostrarMatriz(res, tam, tam);
	pausar();
}

void sumarMatrices(int matriz1[][3], int matriz2[][3], int tam) {
	int i,j;
	int res[3][3] = {0};
	
	for(i = 0; i < tam; i ++) 
		for(j = 0; j < tam; j ++) 
				res[i][j] += matriz1[i][j] + matriz2[i][j];		
	
	titulo("Resultado Suma");
	
	mostrarMatriz(res, tam, tam);
	pausar();
}


int buscarCodigoVenddor(int *codigos, int c) {
	int i;	
	for(i = 0; i < 25; i ++) 
		if(codigos[i] == c)
			return i;
	return -1;
}





