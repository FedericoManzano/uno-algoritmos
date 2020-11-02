#include "./arbol.h"


void crearArbol(t_arbol *a) {
	*a = NULL;
}


int arbolVacio(const t_arbol *a) {
	return *a == NULL;
}


void recorrerInOrden( t_arbol *a ) {
	if( !*a )
		return;
	recorrerInOrden(&( *a )->izq);
	printf("%d ", ( *a )->info);
	recorrerInOrden(&( *a )->der);
}

t_nodo ** buscarNodo(t_arbol *a, t_info_arbol *info, t_cmp comp) {
	while(*a) {
		if(comp( &( *a )->info, info ) > 0)
			a = &( *a )->izq;
		else if(comp( &( *a )->info, info ) < 0) 
			a = &( *a )->der;
		else 
			return a;
	}
	return NULL;
}


int ponerEnArbol(t_arbol *a, t_info_arbol *info,t_cmp comp ) {
	t_nodo *nuevo;
	
	while( *a ) {
		if( comp( &( *a )->info, info ) > 0 )
			a = &( *a )->izq;
		else if( comp( &( *a )->info, info ) < 0 )
			a = &( *a )->der;
		else 
			return 2;
	}
	
	nuevo = ( t_nodo * ) malloc(sizeof( t_nodo ));
	if( !nuevo )
		return 0;
	nuevo->info = *info;
	nuevo->der = NULL;
	nuevo->izq = NULL;
	*a = nuevo;
	return 1;
}


int borrarNodo(t_arbol *a, t_info_arbol *info, t_cmp comp) {
	t_nodo ** aux = buscarNodo(a,info,comp);
	t_nodo ** elim = aux;
	if(!aux) 
		return 0;
	if((*aux)->izq) {
		aux = &(*aux)->izq;
		while(aux && (*aux)->der) 
			aux = &( *aux )->der;
	} else if((*aux)->der) {
		aux = &(*aux)->der;
		while(aux && (*aux)->izq) 
			aux = &( *aux )->izq;
	}
	
	(*elim)->info = (*aux)->info;
	free(*aux);
	*aux = NULL;
	return 1;
}

int nivel(t_arbol *a, t_info_arbol *info, t_cmp comp, int niv) {
	if(!*a) 
		return 0;
	if(*a && comp(&(*a)->info, info) == 0) 
		return niv;
	return nivel( &(*a)->izq,info, comp, niv + 1 ) + nivel( &(*a)->der ,info, comp, niv + 1 );
}


int nivelInfo(t_arbol *a, t_info_arbol *info, t_cmp comp) {
	return nivel(a,info,comp,0);
}

int cna(t_arbol *a) {
	if(!*a)
		return 0;
	return 1 + cna(&(*a)->izq) + cna(&(*a)->izq);
}


int cantidadNodos(t_arbol *a) {
	return cna(a) + 1;
}


void mostrarArbol(t_arbol *a, t_arbol *aux, t_cmp comp) {
	int niv, i;
	if(!*a) 
		return;
	mostrarArbol(&(*a)->izq, aux, comp);
	niv = nivelInfo( aux,&(*a)->info,comp );
	for(i = 0; i < niv; i ++)
		printf("\t");
	printf("\t");
	printf("[ %d %d ]\n ", (*a)->info, niv);
	mostrarArbol( &(*a)->der, aux, comp );
}

void mostrarArbolDib(t_arbol *a, t_cmp comp) {
	t_nodo **aux = a;
	mostrarArbol(a, aux, comp);
}

void vaciarArbol(t_arbol *a) {
	if(!*a) 
		return;
	vaciarArbol(&(*a)->izq);
	vaciarArbol(&(*a)->der);
	free(*a);
	*a = NULL;
}


int buscarClave(t_arbol *a, t_info_arbol *info, t_cmp comp) {
	if(!*a)
		return 0; 
	if(!comp(&(*a)->info, info) )
		return 2;
	else if(comp(&(*a)->info, info) > 0)
		buscarClave(&(*a)->izq, info, comp);
	else
		buscarClave(&(*a)->der, info, comp);
}
