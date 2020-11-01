
#include "./lista.h"

int comp (const void *e1, const void *e2) {
	int *ele1 = (int *)e1;
	int *ele2 = (int *)e2;
	return *ele1 - *ele2;
}



int main(int argc, char *argv[]) {
	int v[10] = {10,9,8,7,6,5,4,3,2,1};
	t_lista lista;
	int i;
	crearLista(&lista);
	
	for(i = 0; i < 10; i++) {
		insertarEnOrden(&lista,&v[i], comp);
	}
	
	
	while(!listaVacia(&lista)) {
		sacarLista(&lista, &i);
		printf("%d ", i);
	}
	
	return 0;
}
