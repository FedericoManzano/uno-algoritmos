#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./header.h"

typedef struct {
	char nombre[42];
	float salario;
}t_info;


int main(int argc, char *argv[]) {
	
	char cadena1[15]  = {"oerico"};
	char cadena2[20] = 	{"rico manzano"};	

	
	printf("%s\n\n",str_pbrk(cadena2, cadena1));
	printf("%s\n\n",str_rev(cadena2));
	system("pause");
	return 0;
}
