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



void qs(void *arreglo, int ini,int fin, size_t tam, t_cmp comp) {
	int i = ini;
	int j = fin;
	void *aux = malloc(tam);
	int pivote = (i + j) / 2;
	
	while(i <= j) {
		while( comp((arreglo + (pivote * tam)), (arreglo + (i * tam))) > 0 && i <= fin)
			i ++;
		while( comp((arreglo + (pivote * tam)), (arreglo + (j * tam))) < 0 && j >= ini)
			j --;
		if(i <= j) {
			memcpy(aux, (arreglo + (i * tam)), tam);
			memcpy( (arreglo + (i * tam) ), (arreglo + (j * tam)), tam);
			memcpy( (arreglo + (j * tam) ), aux, tam);
			i ++;
			j --;
		}
	}
	free(aux);
	if(ini <= j)
		qs(arreglo,ini,j, tam,comp);
    if(fin >= i)
		qs(arreglo,i,fin, tam,comp );
}
void q_sort(void *a, int ce, size_t tam, t_cmp comp) {
	qs(a,0,ce-1,tam, comp);
}


int menor(void *a, int ce, size_t tam, int inicio ,t_cmp comp) {
	int menor = inicio;
	while(inicio < ce) {
		if(comp((a + (inicio * tam)), (a + (menor * tam))) < 0)
			menor = inicio;
		inicio ++;
	}
	return menor;
}

void seleccion (void *a, int ce, size_t tam, t_cmp comp) {
	int men;
	int i = 0;
	void * aux = malloc(tam);
	if(!aux)
		return;
	while(i < ce) {
		men = menor(a,ce,tam,i,comp);
		if(men != i) {
			memcpy(aux, (a + (i * tam)), tam);
			memcpy((a + (i * tam)), (a + (men * tam)), tam);
			memcpy((a + (men * tam)), aux, tam);
		}
		i ++;
	}
	free(aux);
}


void burbuja (void *a, int ce, size_t tam, t_cmp comp) {
	int i, j;
	void *aux = malloc(tam);
	for(i = 0; i < ce; i ++) {
		for(j = i + 1; j < ce; j ++) {
			if(comp((a + (i * tam)), (a + ( j * tam))) > 0) {
				memcpy(aux, (a + (j * tam)), tam);
				memcpy((a + (j * tam)), (a + (i * tam)), tam);
				memcpy((a + (i * tam)),aux, tam);
			}
		}
	}
	free(aux);
}




