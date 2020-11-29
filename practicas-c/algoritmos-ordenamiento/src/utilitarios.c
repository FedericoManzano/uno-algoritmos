
#include <utilitarios.h>

int comp_int(const void *e1, const void *e2) {
	int * ele1 = (int *) e1;
	int * ele2 = (int *) e2;
	return *ele1 - *ele2;
}

int comp_float(const void *e1, const void *e2) {
	float * ele1 = (float *) e1;
	float * ele2 = (float *) e2;
	return *ele1 == *ele2 ? 0: *ele1 > *ele2 ? 1: -1;
}

int comp_car(const void *e1, const void *e2) {
	char * ele1 = (char *) e1;
	char * ele2 = (char *) e2;
	return *ele1 - *ele2;
}


void titulo(char * tit) {
	system("cls");
	printf("\n\n\t\t\t%s\n\n", tit);
}

void pausar() {
	printf("\n\n");
	system("pause");
}



int cargarEnteros(int *vi) {
	int ce = 0;
	int i;
	
	printf("Ingrese la cantidad de elementos (1/50): ");
	scanf("%d", &ce);
	
	
	
	for(i = 0; i < ce; i ++) {
		printf("Ingrese v[%d]: ", i);
		scanf("%d", (vi + i));
	}
	
	return ce;
} 

int mostrarEnteros(int *vi, int ce) {
	int i;
	
	printf("[ ");
	for(i = 0; i < ce; i ++) 
		printf("%d, ", *(vi + i));
	printf(" ]\n\n");
	
	return ce;
} 


int cargarReales(float *vi) {
	int ce = 0;
	int i;
	
	printf("Ingrese la cantidad de elementos (1/50): ");
	scanf("%d", &ce);
	
	
	
	for(i = 0; i < ce; i ++) {
		printf("Ingrese v[%d]: ", i);
		scanf("%f", (vi + i));
	}
	
	return ce;
} 

int mostrarReales(float *vi, int ce) {
	int i;
	
	printf("[ ");
	for(i = 0; i < ce; i ++) 
		printf("%.2f, ", *(vi + i));
	printf(" ]\n\n");
	
	return ce;
} 


int cargarCaracteres(char *vi) {
	int ce = 0;
	int i;
	
	printf("Ingrese la cantidad de elementos (1/50): ");
	scanf("%d", &ce);
	
	for(i = 0; i < ce; i ++) {
		printf("Ingrese v[%d]: ", i);
		fflush(stdin);
		scanf("%c", (vi + i));
	}
	return ce;
} 

int mostrarCar(char *vi, int ce) {
	int i;
	printf("[ ");
	for(i = 0; i < ce; i ++) 
		printf("%c, ", *(vi + i));
	printf(" ]\n\n");
	return ce;
}


void ordenarGenerico(char *tit, int tipo ,t_ord_gen ordenar) {
	int vi[50];
	float vf[50];
	char vc[50];
	int ce;
	
	
	titulo(tit);
	switch(tipo) {
		case 1: 
			ce = cargarEnteros(vi);
			ordenar(vi, ce, sizeof(int), comp_int);
			mostrarEnteros(vi, ce);
		break;
		case 2: 
			ce = cargarReales(vf);
			ordenar(vf, ce, sizeof(float), comp_float);
			mostrarReales(vf, ce);
		break;
		case 3: 
			ce = cargarCaracteres(vc);
			ordenar(vc, ce, sizeof(char), comp_car);
			mostrarCar(vc, ce);
		break;
	}
}
 
void pbaGenerarPrueba(char * tit, t_ord ordenar) {
	int arr[100000];
	int i;
	long t0, t1;
	double secs;
	titulo(tit);
	
	printf("\nSe creara un arreglo de 100000 posiciones cargadas con valores enteros random\n\n");
	
	
	for(i = 0; i < 100000; i ++) 
		arr[i] = rand() % 100000;
	
	printf("Carga del arreglo copletada... \n");
	
	printf("\nOrdenando ....\n\n");
	t0 = clock();
	ordenar(arr, 100000);
	t1 = clock();
	
	secs = (double)(t1 - t0) / CLOCKS_PER_SEC;
	printf("\nDetalle\n");
	printf("Algoritmo: %s\n", tit);
	printf("Elementos: 100000 Elementos enteros\n");
	printf("Tiempo de ordenamiento: %.16g MS", secs * 1000.0);
}






