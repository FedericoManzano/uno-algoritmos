#include <header.h>

void crearArchivos_res () {
	FILE * archPedido = fopen("./archivos/pedidos.dat", "wb");
	FILE * archReceta = fopen("./archivos/recetas.dat", "wb");
	
	t_pedido ped [7] = {
		{1, "B. Frione 4680", 3,-1,-1},
		{2, "Escalada 200", 3,5,0},
		{3, "Neuquen 3030", 1,9,3},
		{4, "Gaona 3311", 2,-1,5},
		{5, "Diaz Velez 700", 2,1,6},
		{6, "Saez Pena 2511", -1,5,4},
		{7, "Canal 145", 0,2,6},
	};
	
	t_receta rec[10] = {
		{"Azucar", 30},
		{"Pimienta", 40},
		{"Sal", 100},
		{"Azufre", 10},
		{"Aceite", 20},
		{"Mayonesa", 0},
		{"Sabora", 0},
		{"Leche", 100},
		{"Arina", 100},
		{"Levadura", 20},
	};
	
	fwrite(ped, sizeof(ped), 1, archPedido);
	fwrite(rec, sizeof(rec), 1, archReceta);
	
	fclose(archPedido);
	fclose(archReceta);
}

void mostrarArchPedidos_res (FILE *archPedidos) {
	t_pedido ped;
	rewind(archPedidos);
	printf(" \n\t***Archivo pedidos.dat *** \n\n");
	printf("\t%-7s%-25s%-5s%-5s%-5s\n", "NRO", "DIRECCION", "ING1", "ING2", "ING3");
	
	fread(&ped, sizeof(t_pedido), 1, archPedidos);
	while(!feof(archPedidos)) {
		printf("\t%-7d%-25s%-5d%-5d%-5d\n", ped.nroPedido, ped.direccion, ped.ing1, ped.ing2, ped.ing3);
		fread(&ped, sizeof(t_pedido), 1, archPedidos);
	}
	rewind(archPedidos);
}


void mostrarArchRecetas_res (FILE *archRecetas) {
	t_receta rec;
	rewind(archRecetas);
	
	printf(" \n\t***Archivo recetas.dat *** \n\n");
	printf("\t%-25s%-7s%\n", "NOMBRE", "STOCK");
	
	fread(&rec, sizeof(t_receta), 1, archRecetas);
	while(!feof(archRecetas)) {
		printf("\t%-25s%-7d\n", rec.nombre, rec.stock);
		fread(&rec, sizeof(t_receta), 1, archRecetas);
	}
	rewind(archRecetas);
}


int actualizarRecetas_res(int ing, t_receta *rec, FILE *archRecetas) {
	if(ing != -1) {
		fseek(archRecetas, sizeof(t_receta) * ing , SEEK_CUR);
		fseek(archRecetas, 0L , SEEK_CUR);
		fread( rec, sizeof( t_receta ), 1, archRecetas );
		fseek(archRecetas, 0L , SEEK_CUR);
		if( rec->stock > 0 ) {
			rec->stock --;
			fseek(archRecetas, -sizeof( t_receta ) , SEEK_CUR);
			fwrite( rec, sizeof( t_receta ), 1, archRecetas );
			fseek(archRecetas, 0L , SEEK_SET);
			return 1;
		}
		return 1;
	}
	return 0;
}

void actualizarPedidos_res(FILE * archPedidos, FILE *archRecetas, t_lista * listaPedidos, t_pila *pilaCancelados) {

	t_receta receta;
	t_pedido pedido;
	t_info info;
	
	fread(&pedido, sizeof(t_pedido), 1, archPedidos);
	
	while(!feof(archPedidos)) {
		
		
		info.nroPedido = pedido.nroPedido;
		strcpy(info.direccion, pedido.direccion);
		
		if( actualizarRecetas_res(pedido.ing1,&receta,archRecetas) && 
			actualizarRecetas_res(pedido.ing2,&receta,archRecetas) && 
			actualizarRecetas_res(pedido.ing3,&receta,archRecetas)) {
				info.estado = 1;
				insertarFinal_res(listaPedidos, &info);
		} else {
			info.estado = 0;
			insertarPila_res(pilaCancelados, &info);
		}
		
		fread(&pedido, sizeof(t_pedido), 1, archPedidos);
	}
}

void mostrarLista_res(t_lista *lista) {
	t_info info;
	
	printf(" \n\t*** Lista Pedidos *** \n\n");
	printf("\t%-8s%-30s%-8s\n", "NRO", "DIRECCION", "ESTADO");
	
	
	while(!listaVacia_res(lista)) {
		sacarLista_res(lista, &info);
		printf("\t%-8d%-30s%-8d\n", info.nroPedido, info.direccion, info.estado);
	}
}


void mostrarPila_res(t_pila *pila) {
	t_info info;
	
	printf(" \n\t*** Pila de cancelados *** \n\n");
	printf("\t%-8s%-30s%-8s\n", "NRO", "DIRECCION", "ESTADO");
	
	
	while(!pilaVacia_res(pila)) {
		sacarPila_res(pila, &info);
		printf("\t%-8d%-30s%-8d\n", info.nroPedido, info.direccion, info.estado);
	}
}
