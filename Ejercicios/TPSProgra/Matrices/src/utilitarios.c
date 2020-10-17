#include "../include/utilitarios.h"

void mostrarMatriz(int *m, const int fil, const int col) {
	int i, j;
	
	for(i = 0; i < fil; i ++) {
		printf("\t\t| ");
		for(j = 0; j < col; j ++) 
			printf("%3d ", *( m + ( i * TAM + j )));
		printf("| ");
		printf("\n");
	}
}

int pausar() {
	printf("\n\n");
	system("pause");
}

void titulo( const char *titulo ) {
	system("cls");
	printf("\n\t\t\t\t%s\n\n", titulo);
}

int ingresarTamanoMatriz(int * fila, int *columna) {
	int val = 0;
	do {
		if(val)
			printf("Err Ingresar cantidad de filas (1/100): ");
		else
			printf("Ingresar cantidad de filas (1/100): ");
		scanf("%d", fila);
		val = 1;
	} while(*fila < 1 || *fila > TAM);
	
	val = 0;
	do {
		if(val)
			printf("Err Ingresar cantidad de columnas (1/100): ");
		else
			printf("Ingresar cantidad de columnas (1/100): ");
		scanf("%d", columna);
		val = 1;
	} while(*columna < 1 || *columna > TAM);
	return 1;
}

void leerMatriz(int *mat, int fila, int col) {
	int i, j;
	
	for(i = 0; i < fila; i ++){
		for(j = 0; j < col; j ++) {
			printf("mat[%d][%d]: ", i + 1, j + 1);
			scanf("%d", (mat + (i * TAM) + j));
		}
	}
}
