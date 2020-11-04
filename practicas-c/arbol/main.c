#include "./arbol.h"

int comp (const void *e1, const void *e2) {
	t_info_arbol *ele1 = (t_info_arbol *)e1;
	t_info_arbol *ele2 = (t_info_arbol *)e2;
	return ele1->valor - ele2->valor;
}


void dibujar(const void  *info, const int niv) {
	t_info_arbol * in = (t_info_arbol *)info;
	int i;
	for(i = 0; i < niv; i ++)
		printf("          ");
	printf("[ %02d | %02d ]\n ", in->valor, in->nroReg);
}


void lectura(void *info_arbol, void * info_est, int nroRegistro) {
	t_info_arbol *ia = (t_info_arbol *)info_arbol;
	int *est = (int *)info_est;
	ia->nroReg = nroRegistro;
	ia->valor = *est;
}


void crearArchPrueba() {
	FILE * arch = fopen("prueba.dat", "wb");
	int valor = 1;
	
	while(valor <= 20) {
		fwrite(&valor, sizeof(int), 1, arch);
		valor ++;
	}
	fclose(arch);
}



void mostrarElemento(const void  *ele) {
	t_info_arbol * in = (t_info_arbol *)ele;
	printf("%d  ", in->valor);
}

int main(int argc, char *argv[]) {
	int v[20] = {20,30,10,5,8,7,4,12,16,25,33,21,2,14,49,35,36,70,23,22};
	int i, num = 3;
	t_arbol arbol;
	
	
	crearArchPrueba();
	
	FILE *arch = fopen("prueba.dat", "rb");
	
	if(!arch)
		return 0;
	crearArbol(&arbol);
	
	archivoBinarioArbol(&arbol, &arch, &i, sizeof(int),comp, lectura);
	printf("\n\n");
	mostrarArbolDib(&arbol, dibujar, comp);
	mostrarNivelArbol(&arbol,2,mostrarElemento);
	fclose(arch);
	return 0;
}
