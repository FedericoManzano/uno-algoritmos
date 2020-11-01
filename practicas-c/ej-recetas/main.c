#include <header.h>

/**
 	Ejercicios de actualizacion de archivos 
 	y TDA lista y pila.
 	EL proyecto muestra las salidas correctas cuado se compila y 
	se ejecuta. 
	No hace falta cerrar archivos ni abrirlos
*/

int main(int argc, char *argv[]) {
	
	FILE * archPedido = fopen("./archivos/pedidos.dat", "rb");
	FILE * archReceta = fopen("./archivos/recetas.dat", "r+b");
	
	t_pila pilaCancelados;
	t_lista listaPedidos;
	
	if( !archPedido || !archReceta )
		return ARCH_ERR;
	
	
	
	crearLista_res(  &listaPedidos  );
	crearPila_res(  &pilaCancelados  );
	
	
	printf("\n\n\t === ENTRADAS === \n\n");
	mostrarArchPedidos_res(archPedido);
	mostrarArchRecetas_res(archReceta);
	
	
	/**
		Comentar la funcion actualizarPedidos_res y descomentar la 
		funcion actualizarPedidos para ver las salidas resueltas por 
		los alumnos.
	*/
	actualizarPedidos_res(archPedido, archReceta, &listaPedidos, &pilaCancelados);
	/// actualizarPedidos(archPedido, archReceta, &listaPedidos, &pilaCancelados);
	
	printf("\n\n\t === SALIDAS === \n\n");
	mostrarArchRecetas_res( archReceta );
	mostrarLista_res ( &listaPedidos );
	mostrarPila_res ( &pilaCancelados );
	
	
	
	fclose(archPedido);
	fclose(archReceta);
	
	crearArchivos_res();
	
	
	return 0;
}
