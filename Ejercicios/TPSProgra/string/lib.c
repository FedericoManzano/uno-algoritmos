#include <stdio.h>
#include <stdlib.h>
#include "./header.h"



char * str_cpy( char *s1, const char *s2 ) {
	char *a = s1;
	if( !s1 || !s2 )
		return NULL;
	while( *s2 )  {
		*a = *s2;
		s2 ++;
		a ++;
	}
	*a = '\0'; 
	return s1;
}

int str_cmp( const char * s1, const char * s2 ) {
	if( !s1 || !s2 )
		return 0;
	while( *s1 && *s2 && *s1 == *s2 ) {
		s1 ++;
		s2 ++;
	}
	return *s1 - *s2;
}


int str_cmpi( const char * s1, const char * s2 ) {
	if( !s1 || !s2 )
		return 0;
	while( *s1 && *s2 && A_MAY( *s1 ) == A_MAY( *s2 ) ) {
		s1 ++;
		s2 ++;
	}
	return A_MAY( *s1 ) - A_MAY( *s2 );
}

int str_ncmp(const char * s1, const char * s2, int n) {
	if(!s1 || !s2)
		return 0;
	while( *s1 && *s2 && *s1 == *s2 && --n ) {
		s1 ++;
		s2 ++;
	}
	return *s1 - *s2;
}

int str_ncmpi(const char * s1, const char * s2, int n) {
	if( !s1 || !s2 )
		return 0;
	while( *s1 && *s2 && A_MAY( *s1 ) == A_MAY( *s2 ) && --n ) {
		s1 ++;
		s2 ++;
	}
	return A_MAY( *s1 ) - A_MAY( *s2 );
}

char *str_str( const char *s1, const char *s2 ) {
	int cmp = 0;
	if( !s1 || !s2 )
		return NULL;
	while( *s1 && ( cmp = str_ncmp(s1,s2, str_len(s2)) ))
		s1 ++;
	return 	!cmp ? (char *)s1 : NULL;
}

int str_len(const char *s) {
	int cant = 0;
	while(s && *s++)
		cant ++;
	return cant;
}


char * str_chr(const char *s, const char c) {
	char *aux = (char *)s;
	if(!aux)
		return NULL;
	while(*aux && *aux != c) 
		aux ++;
	return *aux == c ? aux : NULL;
}

char * str_rchr(const char *s, const char c) {
	char *aux = (char *)s;
	if(!aux)
		return NULL;
	while(*aux)
		aux ++;
	aux --;
	while(aux != s && *aux != c) 
		aux --;
	return *aux == c ? aux: NULL;
}

void * mem_cpy(void *e1, const void *e2, size_t tam) {
	char *ele1 = (char *)e1;
	char *ele2 = (char *)e2;
	if(!ele1 || !ele2)
		return NULL;
	while(tam) {
		*ele1 = *ele2;
		ele1 ++;
		ele2 ++;
		tam --;
	}
	
	return e1;
}

char * str_cat(char *s1, const char * s2) {
	char *a = s1;
	char *b = (char *)s2;
	if(!a || !b)
		return NULL;
	while(*a)
		a ++;
	while(*b) {
		*a = *b;
		a ++;
		b ++;
	}
	*a = '\0';
	return a && b ? s1:NULL;
}

char * str_ncat(char *s1, const char * s2, int n) {
	char *a = s1;
	char *b = (char *)s2;
	if(!a || !b)
		return NULL;
	while(*a)
		a ++;
	while(*b && n--) {
		*a = *b;
		a ++;
		b ++;
	}
	*a = '\0';
	return s1;
}

char *str_lower(char *s) {
	char *a = s;
	if(!a)
		return NULL;
	while(*a) {
		LOWER(*a);
		a ++;
	}
	return s;
}

char *str_upper(char *s) {
	char *a = s;
	if(!a)
		return NULL;
	while(*a) {
		UPPER(*a);
		a ++;
	}
	return s;
}

size_t str_spn( const char * s1, const char *s2 ) {
	size_t cantidad = 0;
	if( !s1 || !s2 )
		return 0;
	while( str_chr( s2, *s1 ) ) {
		cantidad ++;
		s1 ++;
	}
	return cantidad;
}

size_t str_cspn(const char *s1, const char *s2) {
	size_t cantidad = 0;
	if( !s1 || !s2 )
		return -1;
	while( !str_chr( s1, *s2 ) ) {
		cantidad ++;
		s1 ++;
	}
	return cantidad;
}

char *str_rev(char * s) {
	char *a = s;
	char *b = (char *)malloc(sizeof(char)*str_len(s) + 1);
	char *res = b;
	if(!s || !b)
		return NULL;
	while(*a) 
		a ++;
	a --;
	while(a != s) {
		*b = *a;
		b ++;
		a --;
	}
	*b = *a;
	*( ++ b) = '\0';
	str_cpy(s, res);
	free(res);
	return s;
}

char * str_pbrk(const char *s1, const char *s2) {
	char *res = NULL;
	if( !s1 || !s2 )
		return NULL;
	while( *s2 &&  !( res = str_chr( s1, *s2 ) ))
		s2 ++;
	return res ? res:NULL;
}


