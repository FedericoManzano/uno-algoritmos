#include <header.h>


void crearLista_res(t_lista *l) {
	*l = NULL;
}

int listaVacia_res(const t_lista *l) {
	return *l == NULL;
}

int insertarFinal_res( t_lista *l, t_info *info ) {
	t_nodo *n = (t_nodo *)malloc(sizeof(t_nodo));
	if(!n)
		return LLENA;
	while(*l && (*l)->sig)
		l = &(*l)->sig;
	n->info = *info;
	n->sig = NULL;
	if(*l) {
		(*l)->sig = n;
	}
	else {
		*l = n;
	}
		
	
	return OK;
}

int sacarLista_res(t_lista *l, t_info *info) {
	t_nodo *e = *l;
	if(!*l)
		return VACIA;
	*info = e->info;
	*l = e->sig;
	free(e);
	return OK;
}




