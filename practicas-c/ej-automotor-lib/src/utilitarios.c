#include <header.h>

int comp_codigo_res(const void *e1, const void *e2){
	t_info_arbol *ele1 = (t_info_arbol *)e1;
	t_info_arbol *ele2 = (t_info_arbol *)e2;
	return strcmp(ele1->codigo, ele2->codigo);
}


int comp_codigo_lista_res(const void *e1, const void *e2){
	t_info_lista *ele1 = (t_info_lista *)e1;
	t_info_lista *ele2 = (t_info_lista *)e2;
	return strcmp(ele1->codigo, ele2->codigo);
}


int aperturaArchivos_res(FILE **arch, const char *ruta, const char *modo) {
	*arch = fopen(ruta, modo);
	if(!*arch) {
		printf("Err en abrir el archivo %s en modo %s\n", ruta, modo);
		return 0;
	}
	return 1;
}


void crearArchivos_res() {
	FILE *arch_autos = fopen("./archivos/autos.dat", "wb");
	FILE *arch_movs = fopen("./archivos/parche.dat", "wb");

	t_automotor aut[15] = {
		{"HHH 777",	"Peugeot",	0},
		{"KSL 447",	"Toyota",	0},
		{"GDS 448", "Chevrolet",0},
		{"DFS 545", "Ford",		0},
		{"SAS 788", "Nisan",	0},
		{"MNB 789", "Renaut",	0},
		{"HAS 444", "Toyota",	0},
		{"EDE 458", "Fiat",		0},
		{"LJK 777", "Chevrolet",0},
		{"ASW 417", "Chevrolet",0},
		{"ZXC 789", "Renaut",	0},
		{"AZS 444", "Toyota",	0},
		{"XCZ 458", "Fiat",		0},
		{"QWE 777", "Chevrolet",0},
		{"ASS 417", "Chevrolet",0},
	};
	
	fwrite(aut,sizeof(aut), 1, arch_autos);
	
	t_cuotas cuotas[20] = {
		{"EDE 458", 2, 1000},
		{"MNB 789", 5, 2000},
		{"SAS 788", 1, 2100},
		{"QWE 777", 1, 3500},
		{"HHH 777", 8, 1552},
		{"SAS 788", 5, 7822},
		{"MNB 789", 3, 4847},
		{"HHH 777", 2, 7854},
		{"MNB 789", 2, 2412},
		{"EDE 458", 2, 1521},
		{"MNB 789", 1, 1514},
		{"DFS 545", 6, 1012},
		{"LJK 777", 5, 1151},
		{"ZXC 789", 5, 4521},
		{"MNB 789", 5, 5465},
		{"LJK 777", 4, 4568},
		{"GDS 448", 1, 7892},
		{"ASS 417", 5, 4587},
		{"ASW 417", 3, 4565},
		{"XCZ 458", 2, 1253},
	};

	
	fwrite(cuotas, sizeof(cuotas),1,arch_movs);
	
	fclose(arch_autos);
	fclose(arch_movs);	
}


void cargarArbol_res(t_arbol *a) {
	int i;
	t_indice ind[15] = {
		{6, "HAS 444"},
		{2, "GDS 448"},
		{1, "KSL 447"},
		{0, "HHH 777"},
		{4, "SAS 788"},
		{3, "DFS 545"},
		{11, "AZS 444"},
		{-1, "LJK 777"},
		{7, "EDE 458"},
		{5, "MNB 789"},
		{-1, "ASW 417"},
		{10, "ZXC 789"},
		{12, "LJK 777"},
		{-1, "ASS 417"},
		{13, "QWE 777"},
		
	};
	
	for(i = 0; i < 15; i ++) {
		ponerEnArbol_res(a, &ind[i], comp_codigo_res);
	}
}

void mostrarArchivoAutomotor_res(FILE *arch_autos) {
	t_automotor aut;
	rewind(arch_autos);
	printf("\n\n\t**** ARCHIVO AUTOMOTOR ***\n\n");
	printf("\t%-10s%-25s%s\n", "CODIGO", "MODELO", "IMPORTE");
	
	fread(&aut, sizeof(aut),1,arch_autos);
	
	while(!feof(arch_autos)) {
		printf("\t%-10s%-25s%.2f\n", aut.codigo, aut.modelo, aut.importe);
		fread(&aut, sizeof(aut),1,arch_autos);
	}
	rewind(arch_autos);
}

void mostrarArchivoParche_res(FILE *arch_parche) {
	t_cuotas cuo;
	rewind(arch_parche);
	printf("\n\n\t**** ARCHIVO PARCHE ****\n\n");
	printf("\t%-10s%-25s%s\n", "CODIGO", "CUOTA", "MONTO");
	
	fread(&cuo, sizeof(cuo),1,arch_parche);
	
	while(!feof(arch_parche)) {
		
		printf("\t%-10s%-25d%.2f\n", cuo.codigo, cuo.cuota, cuo.monto);
		fread(&cuo, sizeof(cuo),1,arch_parche);
	}
	rewind(arch_parche);
}

void mostrarListaBajas_res(t_lista * lista) {
	t_cuotas cuo;
	
	printf("\n\n\t**** LISTA CUOTAS PERDIDAS ****\n\n");
	printf("\t%-10s%-25s%s\n", "CODIGO", "CUOTA", "MONTO");
	
	while(!listaVacia_res(lista)) {
		sacarLista_res(lista, &cuo);
		printf("\t%-10s%-25d%.2f\n", cuo.codigo, cuo.cuota, cuo.monto);
	}
}



void actualizarAutomotor_res(FILE *arch_autos, FILE *arch_parche, t_arbol *indice_autos, t_lista *listado_bajas) {
	t_automotor aut;
	t_cuotas cuo;
	t_indice ind;
	int busqueda;
	fread(&cuo, sizeof(cuo), 1, arch_parche);
	
	while(!feof(arch_parche)) {
		
		strcpy(ind.codigo, cuo.codigo);
		busqueda = buscarClave_res(indice_autos, &ind, comp_codigo_res);
	
		if(ind.nroRegistro == -1) {
			borrarNodo_res(indice_autos, &ind, comp_codigo_res);
			insertarEnOrden_res(listado_bajas, &cuo, comp_codigo_lista_res);
		}
		else if( busqueda == 2 ) {
			
			fseek(arch_autos, sizeof(aut) * ind.nroRegistro, SEEK_CUR);
			fread(&aut, sizeof(aut), 1, arch_autos);
			aut.importe += cuo.monto;
			fseek(arch_autos, -sizeof(aut), SEEK_CUR);
			fwrite(&aut, sizeof(aut), 1, arch_autos);
			fseek(arch_autos, 0L, SEEK_SET);
		} 
		
		fread(&cuo, sizeof(cuo), 1, arch_parche);
	}
}







