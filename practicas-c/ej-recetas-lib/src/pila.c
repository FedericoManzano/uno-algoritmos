#include <header.h>

void crearPila_res( t_pila *p ) {
	*p = NULL;
}

int pilaVacia_res( const t_pila *p ) {
	return *p == NULL;
}

int insertarPila_res( t_pila *p, t_info *info ) {
	t_nodo *n = (t_nodo *)malloc(sizeof(t_nodo));
	if(!n)
		return LLENA;
	n->info = *info;
	n->sig = *p;
	*p = n;
	return OK;
}

int sacarPila_res( t_pila *p, t_info *info ) {
	t_nodo *e = *p;
	if(!*p)
		return VACIA;
	*info = e->info;
	*p = e->sig;
	free(e);
	return OK;
}




