#include <stdio.h>
#include <stdlib.h>



#define __ARBOL_VACIO   		 	1
#define __ARBOL_LLENO   		 	1
#define __ENCONTRADO_EN_ARBOL 	 	2
#define __NO_ENCONTRADO_EN_ARBOL 	-10
#define __DUPLICADO_EN_ARBOL	  	2
#define __SIN_ELEMENTOS_ARBOL	  	0	

#define __OK 					 	0


#define __ES_HOJA(X, Y)((X) == NULL && (Y) == NULL)


typedef int ( * t_cmp )( const void * , const void * );
typedef void (* t_mostrar_dib)(const void *, const int);
typedef void (* t_mostrar_ele)(const void  *);
typedef int (* t_procesar )(const void *, const void *);
typedef void (* t_lectura)(void *, void *, const int);

typedef struct {
	int nroReg;
	int valor;
}t_indice;



typedef t_indice t_info_arbol;


typedef struct s_nodo_arbol {
	struct s_nodo_arbol *der;
	struct s_nodo_arbol *izq;
	t_info_arbol info;
}t_nodo_arbol;

typedef t_nodo_arbol * t_arbol;

/** Funciones principales */
void crearArbol(t_arbol *a);
int ponerEnArbol(t_arbol *a, t_info_arbol *info,t_cmp comp );
int arbolVacio(const t_arbol *a);


/* Borrado de elementos */
int borrarNodo(t_arbol *, t_info_arbol *, t_cmp);
void borrarHojasArbol (t_arbol *);


/* Muestra de los elementos*/
void recorrerInOrden( t_arbol *a , t_mostrar_ele);
void recorrerPostOrden( t_arbol *a , t_mostrar_ele);
void recorrerPreOrden( t_arbol *a , t_mostrar_ele);
void mostrarArbol(t_arbol *,t_arbol *, t_mostrar_dib,  t_cmp comp);
void mostrarArbolDib(t_arbol *,t_mostrar_dib, t_cmp );
void mostrarHojas(t_arbol *,t_mostrar_ele);
void mostrarRaiz(t_arbol *, t_mostrar_ele);
void mostrarNivelArbol(t_arbol *, int, t_mostrar_ele);

/** Informacion del arbol */
int nivel(t_arbol *, t_info_arbol *, t_cmp, int);
int nivelInfo(t_arbol *a, t_info_arbol *, t_cmp);
int cna(t_arbol *);
int cantidadNodos(t_arbol *);
int contarHojas (t_arbol *);
int alturaArbol(t_arbol *);
int cantidadNiveles(t_arbol *);

/* Busqueda de elemento */
int buscarClave(t_arbol *, t_info_arbol *, t_cmp);
t_nodo_arbol ** buscarNodo(t_arbol *, t_info_arbol *, t_cmp);

// Vaciar el arbol de memoriab
void vaciarArbol(t_arbol *);


// Pasar a archivo binario
void pasarArchArbol(t_arbol *, FILE **,void *,const int , long, long, t_cmp, t_lectura lec);
void archivoBinarioArbol(t_arbol *, FILE **, void *,const int, t_cmp, t_lectura lec);





