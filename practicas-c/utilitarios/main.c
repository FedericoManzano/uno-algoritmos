#include "./utilitarios.h"


void tituloCabecera(const void *e) {
	t_automotor *ele = (t_automotor *)e;
	printf("\t%-10s%-25s%-.2f\n", ele->codigo, ele->modelo, ele->importe);
}

void tituloCuotas(const void *e) {
	t_cuotas *ele = (t_cuotas *)e;
	printf("\t%-10s%-25d%-.2f\n", ele->codigo, ele->cuota, ele->monto);
}

char * ruta() {
	return "./autos.dat"; 
}

char *modo() {
	return "rb";
}

int main(int argc, char *argv[]) {
	
	FILE *arch;
	FILE *cuot = fopen("./parche.dat", "rb");
	t_automotor aut;
	t_cuotas cuo;
	if(!aperturaDeArchivos(&arch, ruta, modo))
		return 5;
	
	mostrarArchivoBinario(arch,tituloCabecera, &aut, sizeof(aut));
	mostrarArchivoBinario(cuot,tituloCuotas, &cuo, sizeof(cuo));
	fclose(arch);
	fclose(cuot);
	
	system("pause");
	return 0;
}
