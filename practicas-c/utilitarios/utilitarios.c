#include "./utilitarios.h"


int aperturaDeArchivos(FILE **arch, ruta_modo ruta, ruta_modo modo) {
	*arch = fopen(ruta(), modo());
	if(!*arch) {
		printf("El archivo %s en el modo %s no pudo abrirse correctamente \n\n",ruta(), modo() );
		return 0;
	}	
	return 1;
}


void mostrarArchivoBinario(FILE *arch,formato_binario cabecera, void *est, int tam){
	rewind(arch);
	fread(est, tam, 1, arch);
	
	while(!feof(arch)) {
		cabecera(est);
		fread(est, tam, 1, arch);
	}
	
	rewind(arch);
}
