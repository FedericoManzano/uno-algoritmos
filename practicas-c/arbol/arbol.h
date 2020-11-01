#include <stdio.h>
#include <stdlib.h>



typedef int ( * t_cmp )( const void * , const void * );

typedef int t_info_arbol;


typedef struct s_nodo {
	struct s_nodo *der;
	struct s_nodo *izq;
	t_info_arbol info;
}t_nodo;

typedef t_nodo * t_arbol;

void crearArbol(t_arbol *a);
int arbolVacio(const t_arbol *a);
int ponerEnArbol(t_arbol *a, t_info_arbol *info,t_cmp comp );
t_nodo ** buscarNodo(t_arbol *a, t_info_arbol *info, t_cmp comp);
int borrarNodo(t_arbol *a, t_info_arbol *info, t_cmp comp);
int nivel(t_arbol *a, t_info_arbol *info, t_cmp comp, int niv);
int nivelInfo(t_arbol *a, t_info_arbol *info, t_cmp comp);
int cna(t_arbol *a);
int cantidadNodos(t_arbol *a);
void mostrarArbol(t_arbol *a,t_arbol * aux,  t_cmp comp);
void mostrarArbolDib(t_arbol *a, t_cmp comp);
void vaciarArbol(t_arbol *a);
int buscarClave(t_arbol *a, t_info_arbol *info, t_cmp comp);

