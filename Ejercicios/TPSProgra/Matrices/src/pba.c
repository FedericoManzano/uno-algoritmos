#include "../include/pba.h"

void pbaMostrar() {
	int mat[TAM][TAM], fila, col;
	pbaIngresarMatriz(mat,&fila,&col);
	titulo("Resultado");
	mostrarMatriz((int *)mat, fila, col);
	pausar();
}

int pbaIngresarMatriz(int m[][TAM], int *fila, int *col) {
	titulo("Leer Matriz");
	if(ingresarTamanoMatriz(fila, col)) {
		leerMatriz((int *)m,*fila,*col);
		return 1;
	}
	
	return 0;
}

void pbaLeer() {
	int mat[TAM][TAM], fila, col;
	pbaIngresarMatriz(mat,&fila,&col);
	titulo("Resultado");
	mostrarMatriz((int *)mat, fila, col);
	pausar();
}


void pbaMultiplicar() {
	int mat1[TAM][TAM], mat2[TAM][TAM], fila1, col1, fila2, col2;
	int res[TAM][TAM];
	pbaIngresarMatriz( mat1,&fila1,&col1 );
	pbaIngresarMatriz( mat2,&fila2,&col2 );
	titulo("Resultado");
	if(multiplicarMatrices((int *)mat1, (int  *)mat2, fila1, col1, fila2, col2, (int *)res))
		mostrarMatriz((int *)res, fila1, col2);
	else 
		printf("Error no pudo realizarse la operacion");
	
	
	pausar();
}

void pbaSumar() {
	int mat1[TAM][TAM], mat2[TAM][TAM], fila1, col1, fila2, col2;
	int res[TAM][TAM];
	pbaIngresarMatriz( mat1,&fila1,&col1 );
	pbaIngresarMatriz( mat2,&fila2,&col2 );
	titulo("Resultado");
	if(sumaMatrices((int *)mat1, (int  *)mat2, fila1, col1, fila2, col2, (int *)res))
		mostrarMatriz((int *)res, fila1, col1);
	else 
		printf("Error no pudo realizarse la operacion");
	pausar();
}

void pbaReducirMatriz() {
	int mat1[TAM][TAM], mat2[TAM][TAM], fila1, col1, fila2, col2;
	int res[TAM][TAM];
	pbaIngresarMatriz( mat1,&fila1,&col1 );
	pbaIngresarMatriz( mat2,&fila1,&col1 );
	reducirMatriz((int *)mat1, (int *)mat2, fila1, col1);
	pausar();
}






