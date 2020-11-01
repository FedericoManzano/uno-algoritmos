#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define LLENA 		0
#define VACIA 		0
#define OK 			1
#define ARCH_ERR 	5



typedef struct {
	int nroPedido;
	char direccion[100];
	int ing1;
	int ing2;
	int ing3;
}t_pedido;

typedef struct {
	char nombre[45];
	int stock;
}t_receta;

typedef struct {
	int nroPedido;
	char direccion[100];
	int estado;
} t_info;


typedef struct s_nodo {
	t_info info;
	struct s_nodo *sig;
} t_nodo;

typedef t_nodo * t_lista;
typedef t_nodo * t_pila;


// Funciones de lista
void crearLista_res ( t_lista * );
int listaVacia_res ( const t_lista * );
int insertarFinal_res ( t_lista *, t_info * );
int sacarLista_res ( t_lista *, t_info * );

// Funciones de pila
void crearPila_res( t_pila * );
int pilaVacia_res( const t_pila * );
int insertarPila_res( t_pila *, t_info * );
int sacarPila_res( t_pila *, t_info * );


// Funciones
void crearArchivos_res () ;
void mostrarArchPedidos_res (FILE *);
void mostrarArchRecetas_res (FILE *);
void actualizarPedidos_res(FILE *, FILE *, t_lista *, t_pila *);
void mostrarLista_res(t_lista *);
void mostrarPila_res(t_pila *);

// Funciones a realizar
int insertarPila( t_pila *, t_info * );
int insertarFinal ( t_lista *, t_info * );
void actualizarPedidos(FILE *, FILE *, t_lista *, t_pila *);

