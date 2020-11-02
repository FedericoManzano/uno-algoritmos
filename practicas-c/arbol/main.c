#include "./arbol.h"

int comp (const void *e1, const void *e2) {
	int *ele1 = (int *)e1;
	int *ele2 = (int *)e2;
	return *ele1 - *ele2;
}



int main(int argc, char *argv[]) {
	int v[8] = {10,11,15,3,12,2,4,5};
	int i, num = 3;
	t_arbol arbol;
	
	crearArbol(&arbol);
	
	for( i = 0; i< 8; i ++) 
		ponerEnArbol(&arbol, &v[i], comp);
	borrarNodo(&arbol,&v[0], comp );
	mostrarArbolDib(&arbol,comp);	
	vaciarArbol(&arbol);
	return 0;
}
