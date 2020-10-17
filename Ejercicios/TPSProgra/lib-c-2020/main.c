
#include "./include/menu.h"
#include "./include/vectores.h"

int comp(const void *e1, const void *e2) {
	int *ele1 = (int *)e1;
	int *ele2 = (int *)e2;
	return *ele1 - *ele2;
}


int main(int argc, char *argv[]) {
	
	int v[TAM_MAX] = {1,2,3,4,5,6,7,8,9,10};
	int elemento = 1;
	int ce = 10;
	char op;
	int i;
	char opciones [][TAM] = {
		{"ACMLTS"},
		{"Arreglos"},
		{"Cadenas"},
		{"Matrices"},
		{"Listas"},
		{"Arboles"},
		{"Salir"}
	};
	
	seleccion(v,ce,sizeof(int),comp);
	insertarEnOrden_sdup(v,&ce,&elemento,sizeof(int), comp);
	for( i = 0; i < ce; i ++ ) 
		printf("%d\n", v[i]);
	system("pause");	
	do {
		op = seleccionarOpcion(opciones,"Libreria de C 2020");
		switch(op) {
			case 'A': 
				break;
			case 'B':
				break;
		}	
	}while(op != 'S');
	
	
	return 0;
}
