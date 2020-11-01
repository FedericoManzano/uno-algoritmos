#include <stdio.h>
#include <stdlib.h>


typedef int (*t_cmp)(const void *, const void *);

typedef int t_info_lista;

typedef struct s_nodo {
	struct s_nodo *sig;
	struct s_nodo *ant;
	t_info_lista info;
} t_nodo_lista;


typedef t_nodo_lista * t_lista;



void crearLista (t_lista *l);
int listaVacia(const t_lista *l);
int insertarEnOrden(t_lista *l, const t_info_lista *info, t_cmp comp);
int sacarLista(t_lista *l, t_info_lista *info);


