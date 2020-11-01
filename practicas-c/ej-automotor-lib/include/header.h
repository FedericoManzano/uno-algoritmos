#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ERR_ARCH 5


typedef int ( * t_cmp )( const void * , const void * );


typedef struct {
	int nroRegistro;
	char codigo[10];
}t_indice;

typedef struct {
	char codigo[10];
	char modelo[45];
	float importe;
}t_automotor;

typedef struct {
	char codigo[10];
	int cuota;
	float monto;
}t_cuotas;


typedef t_indice t_info_arbol;
typedef t_cuotas t_info_lista;

typedef struct s_nodo_arbol {
	struct s_nodo_arbol *der;
	struct s_nodo_arbol *izq;
	t_info_arbol info;
}t_nodo_arbol;


typedef struct s_nodo_lista {
	struct s_nodo_lista *sig;
	struct s_nodo_lista *ant;
	t_info_lista info;
} t_nodo_lista;

typedef t_nodo_arbol * t_arbol;
typedef t_nodo_lista * t_lista;


void crearArbol_res(t_arbol *a);
int arbolVacio_res(const t_arbol *a);
int ponerEnArbol_res(t_arbol *a, t_info_arbol *info,t_cmp comp );
t_nodo_arbol ** buscarNodo_res(t_arbol *a, t_info_arbol *info, t_cmp comp);
int borrarNodo_res(t_arbol *a, t_info_arbol *info, t_cmp comp);
int nivel_res(t_arbol *a, t_info_arbol *info, t_cmp comp, int niv);
int nivelInfo_res(t_arbol *a, t_info_arbol *info, t_cmp comp);
int cna_res(t_arbol *a);
int cantidadNodos_res(t_arbol *a);
void mostrarArbol_res(t_arbol *a,t_arbol * aux,  t_cmp comp);
void mostrarArbolDib_res(t_arbol *a, t_cmp comp);
void vaciarArbol_res(t_arbol *a);
int buscarClave_res(t_arbol *a, t_info_arbol *info, t_cmp comp);


void crearLista_res (t_lista *l);
int listaVacia_res(const t_lista *l);
int insertarEnOrden_res(t_lista *l, const t_info_lista *info, t_cmp comp);
int sacarLista_res(t_lista *l, t_info_lista *info);

void crearArchivos_res();
void cargarArbol_res(t_arbol *a);
int comp_codigo_res(const void *e1, const void *e2);
int aperturaArchivos_res(FILE **arch, const char *ruta, const char *modo);
void mostrarArchivoAutomotor_res(FILE *arch_autos);
void mostrarArchivoParche_res(FILE *arch_parche);
void actualizarAutomotor_res(FILE *arch_autos, FILE *arch_parche, t_arbol *indice_autos, t_lista *listado_bajas);
void mostrarListaBajas_res(t_lista * lista);



