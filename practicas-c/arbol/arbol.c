#include "./arbol.h"


void crearArbol(t_arbol *a) {
	*a = NULL;
}


int arbolVacio(const t_arbol *a) {
	return *a == NULL;
}

int arbolLLeno(const t_arbol *a) {
	return *a == NULL;
}


void recorrerInOrden( t_arbol *a, t_mostrar_ele mos ) {
	if( !*a )
		return;
	recorrerInOrden(&( *a )->izq, mos);
	mos(&( *a )->info);
	recorrerInOrden(&( *a )->der, mos);
}


void recorrerPostOrden( t_arbol *a , t_mostrar_ele mos) {
	if( !*a )
		return;
	recorrerPostOrden(&( *a )->izq, mos);
	recorrerPostOrden(&( *a )->der, mos);
	mos(&( *a )->info);
}


void recorrerPreOrden( t_arbol *a , t_mostrar_ele mos){
	if( !*a )
		return;
	mos(&( *a )->info);
	recorrerPreOrden(&( *a )->izq, mos);
	recorrerPreOrden(&( *a )->der, mos);
}

t_nodo_arbol ** buscarNodo( t_arbol *a, t_info_arbol *info, t_cmp comp ) {
	while( *a ) {
		if( comp( &( *a )->info, info ) > 0 )
			a = &( *a )->izq;
		else if( comp( &( *a )->info, info ) < 0 ) 
			a = &( *a )->der;
		else 
			return a;
	}
	return NULL;
}


int ponerEnArbol(t_arbol *a, t_info_arbol *info,t_cmp comp ) {
	t_nodo_arbol *nuevo;
	
	while( *a ) {
		if( comp( &( *a )->info, info ) > 0 )
			a = &( *a )->izq;
		else if( comp( &( *a )->info, info ) < 0 )
			a = &( *a )->der;
		else 
			return __DUPLICADO_EN_ARBOL;
	}
	
	nuevo = ( t_nodo_arbol * ) malloc(sizeof( t_nodo_arbol ));
	if( !nuevo )
		return __ARBOL_LLENO;
	nuevo->info = *info;
	nuevo->der = NULL;
	nuevo->izq = NULL;
	*a = nuevo;
	return __OK;
}


int borrarNodo(t_arbol *a, t_info_arbol *info, t_cmp comp) {
	t_nodo_arbol ** aux = buscarNodo(a,info,comp);
	t_nodo_arbol ** elim = aux;
	if(!aux) 
		return __NO_ENCONTRADO_EN_ARBOL;
	if( alturaArbol(&(*a)->izq) >= alturaArbol(&(*a)->der) ) {
		if( (*aux)->izq ) {
			aux = &(*aux)->izq;
			while( aux && (*aux)->der ) 
				aux = &( *aux )->der;
		}
	} else {
		if( ( *aux )->der ) {
			aux = &( *aux )->der;
			while(aux && ( *aux )->izq) 
				aux = &( *aux )->izq;
		}
	}
	
	(*elim)->info = (*aux)->info;
	free(*aux);
	*aux = NULL;
	return __OK;
}

int nivel(t_arbol *a, t_info_arbol *info, t_cmp comp, int niv) {
	if(!*a) 
		return __SIN_ELEMENTOS_ARBOL;
	if(*a && comp(&(*a)->info, info) == 0) 
		return niv;
	return nivel( &(*a)->izq,info, comp, niv + 1 ) + nivel( &(*a)->der ,info, comp, niv + 1 );
}

void mostrarNivelArbol(t_arbol *a, int nivel, t_mostrar_ele mos) {
	if(!*a)
		return;
	if(nivel == -1)
		return;
	if(nivel == 0) 
		mos(&(*a)->info);
	mostrarNivelArbol(&(*a)->izq, nivel - 1, mos);
	mostrarNivelArbol(&(*a)->der, nivel - 1, mos);
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
	int cantidad = cna(a);
	return cantidad > 0 ?  cantidad + 1: 0;
}


void mostrarArbol(t_arbol *a, t_arbol *aux,t_mostrar_dib dib, t_cmp comp) {
	int niv;
	if(!*a) 
		return;
	mostrarArbol(&(*a)->izq, aux,dib, comp);
	dib( &(*a)->info, nivelInfo( aux,&(*a)->info,comp ) );
	mostrarArbol( &(*a)->der, aux,dib, comp );
}

void mostrarArbolDib(t_arbol *a,t_mostrar_dib dib, t_cmp comp ) {
	t_nodo_arbol **aux = a;
	mostrarArbol(a,aux,dib,comp);
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
		return __NO_ENCONTRADO_EN_ARBOL; 
	if(!comp(&(*a)->info, info) )
		return __ENCONTRADO_EN_ARBOL;
	else if(comp(&(*a)->info, info) > 0)
		buscarClave(&(*a)->izq, info, comp);
	else
		buscarClave(&(*a)->der, info, comp);
}

void borrarHojasArbol (t_arbol *a) {
	if(!*a) 
		return;
	if(!__ES_HOJA((*a)->izq, (*a)->der)) {
		borrarHojasArbol(&(*a)->izq);
		borrarHojasArbol(&(*a)->der);	
	}else {
		free(*a);
		*a = NULL;
	}
}


int contarHojas(t_arbol *a) {
	if(!*a) 
		return 0;
	if(__ES_HOJA((*a)->izq, (*a)->der))
		return 1 + contarHojas(&(*a)->izq) +  contarHojas(&(*a)->der);
	return contarHojas(&(*a)->izq) + contarHojas(&(*a)->der);
}


void mostrarHojas(t_arbol *a,t_mostrar_ele mos) {
	if(!*a) 
		return;
	mostrarHojas(&(*a)->izq, mos);
	if(__ES_HOJA((*a)->izq, (*a)->der))
		mos(&(*a)->info);
	mostrarHojas(&(*a)->der, mos);
}


int alturaArbol(t_arbol *a) {
	if(!*a)
		return 0;
	int izq = alturaArbol(&(*a)->izq) + 1;
	int der = alturaArbol(&(*a)->der) + 1;
	return izq > der ? izq : der;
}

int cantidadNiveles(t_arbol *a) {
	return alturaArbol(a)  - 1;
}

void mostrarRaiz(t_arbol *a, t_mostrar_ele mos) {
	mos(&(*a)->info);
} 


void  pasarArchArbol(t_arbol *a, FILE **arch, void *tipo_dato, const int tam, long inicio, long final, t_cmp comp,t_lectura lec) {
	t_info_arbol info;
	long med = ( inicio + final ) / 2;

	fseek(*arch, tam * med, SEEK_CUR);
	fread(tipo_dato, tam, 1, *arch);
	fseek(*arch, 0L, SEEK_SET);
	lec(&info, tipo_dato, med);
	ponerEnArbol(a, &info, comp );
	if(inicio < med)
		pasarArchArbol(a, arch, tipo_dato,tam , inicio , med - 1,comp, lec);
	if(final > med) 
		pasarArchArbol(a, arch, tipo_dato,tam , med + 1, final, comp, lec);

}

void  archivoBinarioArbol(t_arbol *a, FILE **arch, void *tipo_dato, const int tam, t_cmp comp, t_lectura lec) {
	fseek(*arch, 0L, SEEK_END);
	long cantByte = ftell(*arch) / tam;
	fseek(*arch, 0L, SEEK_SET);
	return pasarArchArbol(a,arch,tipo_dato,tam, 0,cantByte, comp, lec);
}


