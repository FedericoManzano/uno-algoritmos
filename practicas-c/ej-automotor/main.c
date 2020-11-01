#include <header.h>


/***
	El ejercicio funciona al ejecutarse mostrando las entradas 
	y salidas correctas.
	No hace falta realizar la apertura ni el cierre de archivos 
	ni la creacion de listas y arboles solamente las funciones pedidas 
	en los archivos src/arbol.c src/lista.c src/utilitarios.c.
	Los prototipos estructuras y macros se encuentran en el arch 
	include/header.h.
*/

int main(int argc, char *argv[]) {
	
	FILE *arch_auto;
	FILE *arch_parche;
	
	t_arbol indiceAutomotor;
	t_lista listadoBajas;
	
	
	if( !aperturaArchivos_res(&arch_auto, "./archivos/autos.dat", "r+b") )
		return ERR_ARCH;
	if( !aperturaArchivos_res(&arch_parche, "./archivos/parche.dat", "rb"))
		return ERR_ARCH;
	
	
	crearArbol_res	(  &indiceAutomotor );
	cargarArbol_res	(  &indiceAutomotor );
	crearLista_res	(  &listadoBajas    );
	
	
	mostrarArchivoAutomotor_res(arch_auto);
	mostrarArbolDib_res(&indiceAutomotor,comp_codigo_res);
	mostrarArchivoParche_res(arch_parche);
	
	/**
		Para probar la resolucion propia descomentar la funcion
		actualizarAutomotor y comentar la funcion actualizarAutomotor_res
	*/
	///actualizarAutomotor(arch_auto, arch_parche, &indiceAutomotor, &listadoBajas);
	actualizarAutomotor_res(arch_auto, arch_parche, &indiceAutomotor, &listadoBajas);
	
	
	mostrarArchivoAutomotor_res(arch_auto);
	mostrarArbolDib_res(&indiceAutomotor,comp_codigo_res);
	mostrarListaBajas_res(&listadoBajas);
	
	
	vaciarArbol_res(&indiceAutomotor);
	
	fclose(arch_auto);
	fclose(arch_parche);
	
	
	crearArchivos_res();
	
	return 0;
}
