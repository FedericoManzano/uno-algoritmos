#include "../include/header.h"

void inicializarMatriz (int *m, int f, int c) {
	int i,j;
	for(i = 0; i < f; i ++) 
		for(j = 0; j < c; j ++)
			 *(m + (i * TAM) + j) = 0;
}

int multiplicarMatrices(int *mat1, int *mat2, int f1, int c1, int f2, int c2, int * res) {
	int i,j,k;
	if(c1 != f2)
		return 0;
	inicializarMatriz(res, f1, c2);
	for(i = 0; i < f1; i ++) 
		for(k = 0; k < c2; k ++) 
			for(j = 0; j < f1; j ++) 
				*(res + (i * TAM) + k) += *(mat1 + (i * TAM) + j) * *(mat2 + (j * TAM) + k); 
	return 1;	
}

int sumaMatrices(int *mat1, int *mat2, int f1, int c1, int f2, int c2, int * res) {
	int i,j;
	if(f1 != f2 || c1 != c2)
		return 0;
	inicializarMatriz(res, f1, c1);
	for(i = 0; i < f1; i ++) 
		for(j = 0; j < c1; j ++) 
			*(res + (i * TAM) + j) += *(mat1 + (i * TAM) + j)  + *(mat2 + (i * TAM) + j); 
	return 1;	
}



int cambiarFila () {
	
}

int encontrarPivote(int *m, int f, int c, int sf,int sc, int *fp, int *cp ) {
	int i;
	for(i = sf; i < f; i ++) {
		if(*(m + (i*TAM) + sc) != 0) {
			*fp = i;
			*cp = sc;
			return 1;
		}		
	}
	return 0;
}




int reducirMatriz(int *m, int *mr, int f, int c) {
	int fp, cp, sf = 0, sc = 0, i, j;
	
	for(i = 0; i < f; i ++) {
		if(!encontrarPivote(m,f,c,sf,sc,&fp, &cp)) {
			fp ++;
			cp ++;
		}else {
			for(j = fp; j < f; j ++ ) {
				if(j == fp)
					*(mr + (j * TAM)) = *(m + (fp * TAM) + cp);
				else
					*(mr + (j * TAM)) = 0;
			}
		}
	}
	
	mostrarMatriz(mr, f,c);
	
}
