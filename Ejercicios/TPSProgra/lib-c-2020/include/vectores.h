#include "./generales.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 40000


int eliminarElemento(void *, int *,void *, size_t, t_cmp);
int borrarDuplicados( void *, int *, size_t, t_cmp );
int menor(void *, int, int, size_t, t_cmp);
void q_sort(void *, int, size_t, t_cmp);
void seleccion(void *, int, size_t, t_cmp);
int insertarAlFinal(void *, int *,void *, size_t);
int insertarEnOrden(void *, int *,void *, size_t, t_cmp);
int insertarEnOrden_sdup(void *, int *,void *, size_t, t_cmp);
