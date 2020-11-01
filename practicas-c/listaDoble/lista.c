#include "./lista.h"

void crearLista (t_lista *l) {
	*l = NULL;
}

int listaVacia(const t_lista *l) {
	return *l == NULL;
}

int insertarEnOrden(t_lista *l, const t_info_lista *info, t_cmp comp) {
	t_nodo_lista *anterior = *l;
	t_nodo_lista *siguiente = *l;
	t_nodo_lista *nuevo;
	
	
	while(anterior && comp(&anterior->info, info) > 0)
		anterior = anterior->ant;
	
	while(siguiente && comp(&siguiente->info, info) < 0)
		siguiente = siguiente->sig;
	
	nuevo = (t_nodo_lista *)malloc(sizeof(t_nodo_lista));
	if(!nuevo)
		return 0;
	
	nuevo->info = *info;
	nuevo->sig = NULL;
	nuevo->ant = NULL;
	
	if(anterior) {
		nuevo->ant = anterior;
		anterior->sig = nuevo;
	}
	
	if(siguiente) {
		nuevo->sig = siguiente;
		siguiente->ant = nuevo;
	}
		
	
	*l = nuevo;
	return 1;
}


int sacarLista(t_lista *l, t_info_lista *info) {
	t_nodo_lista *elim = *l;
	int asign = 0;
	if(!elim)
		return 0;
	*info = elim->info;
	
	if(elim->ant) {
		elim->ant->sig = elim->sig;
		*l = elim->ant;
		asign = 1;
	}
		
	if(elim->sig) {
		elim->sig->ant = elim->ant;	
		*l = elim->sig;
		asign = 1;
	}
		
	if(!asign) 
		*l = NULL;
	
	free(elim);
	return 1;
}

