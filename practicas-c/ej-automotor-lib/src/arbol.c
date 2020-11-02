#include <header.h>


void crearArbol_res(t_arbol *a) {
	*a = NULL;
}


int arbolVacio_res(const t_arbol *a) {
	return *a == NULL;
}


void recorrerInOrden_res( t_arbol *a ) {
	if( !*a )
		return;
	recorrerInOrden_res(&( *a )->izq);
	printf("%d ", ( *a )->info);
	recorrerInOrden_res(&( *a )->der);
}

t_nodo_arbol ** buscarNodo_res(t_arbol *a, t_info_arbol *info, t_cmp comp) {
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


int ponerEnArbol_res(t_arbol *a, t_info_arbol *info,t_cmp comp ) {
	t_nodo_arbol *nuevo;
	
	while( *a ) {
		if( comp( &( *a )->info, info ) > 0 )
			a = &( *a )->izq;
		else if( comp( &( *a )->info, info ) < 0 )
			a = &( *a )->der;
		else 
			return 2;
	}
	
	nuevo = ( t_nodo_arbol * ) malloc(sizeof( t_nodo_arbol ));
	if( !nuevo )
		return 0;
	nuevo->info = *info;
	nuevo->der = NULL;
	nuevo->izq = NULL;
	*a = nuevo;
	return 1;
}


int borrarNodo_res(t_arbol *a, t_info_arbol *info, t_cmp comp) {
	t_nodo_arbol ** aux = buscarNodo_res(a,info,comp);
	t_nodo_arbol ** elim = aux;
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

int nivel_res(t_arbol *a, t_info_arbol *info, t_cmp comp, int niv) {
	if(!*a) 
		return 0;
	if( *a && comp(&(*a)->info, info ) == 0) 
		return niv;
	return nivel_res( &(*a)->izq,info, comp, niv + 1 ) + nivel_res( &(*a)->der ,info, comp, niv + 1 );
}


int nivelInfo_res(t_arbol *a, t_info_arbol *info, t_cmp comp) {
	return nivel_res(a,info,comp,0);
}

int cna_res(t_arbol *a) {
	if(!*a)
		return 0;
	return 1 + cna_res(&(*a)->izq) + cna_res(&(*a)->izq);
}


int cantidadNodos_res(t_arbol *a) {
	return cna_res(a) + 1;
}


char *dameEspacios_res(char *esp, int cant) {
	int i;
	int strVeces = 0;
	for(i = 0; i < cant; i ++) {
		strVeces = i;
		while(strVeces) {
			strcat(esp, " ");
			strVeces --;
		}
	}
	return esp;
}

void impInfo_res(t_info_arbol *i, int niv) {
	char esp[50] = {""};
	
	printf("%s[%s|%d]\n",dameEspacios_res(esp, niv), i->codigo, i->nroRegistro);	
}
void mostrarArbol(t_arbol *a, t_arbol *aux, t_cmp comp) {
	int niv, i;
	if(!*a) 
		return;
	
	mostrarArbol(&(*a)->izq, aux, comp);
	niv = nivelInfo_res( aux,&(*a)->info,comp );
	for(i = 0; i < niv; i ++)
		printf("       \t");
	printf(" "); 	
	impInfo_res(&(*a)->info, niv);
	mostrarArbol( &(*a)->der, aux, comp );
}

void mostrarArbolDib_res(t_arbol *a, t_cmp comp) {
	t_nodo_arbol **aux = a;
	printf("\n\n\t**** INDICE ARCHIVO AUTOMOTOR ***\n\n");
	mostrarArbol(a, aux, comp);
}

void vaciarArbol_res(t_arbol *a) {
	if(!*a) 
		return;
	vaciarArbol_res(&(*a)->izq);
	vaciarArbol_res(&(*a)->der);
	free(*a);
	*a = NULL;
}


int buscarClave_res(t_arbol *a, t_info_arbol *info, t_cmp comp) {
	if(!*a)
		return 0; 
	if(!comp(&(*a)->info, info) ) {
		*info = (*a)->info;
		return 2;
	}
		
	else if(comp(&(*a)->info, info) > 0)
		buscarClave_res(&(*a)->izq, info, comp);
	else
		buscarClave_res(&(*a)->der, info, comp);
}

