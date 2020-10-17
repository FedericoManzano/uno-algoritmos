#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./heather.h"


double potencia(const double num, const int pot) {
    int i;
    double res = 1;
    if(pot == 0)
        return 1;
    if(pot == 1) 
        return num;
    for(i = 1; i <= abs(pot); i++)
        res *= num;
    return pot < 0 ? 1 / res : res;
}

double suma(const double num1, const double num2) {
	return num1 + num2;
}

double resta(const double num1, const double num2) {
	return num1 - num2;
}

double mul(const double num1, const double num2) {
	return num1 * num2;
}

double division(const double num1, const double num2) {
	return num2 != 0 ? num1 / num2: -1;
}

int esPar(const int num) {
	return ES_PAR(num);
}

int multiplo(const int num1, const int num2) {
	if(num2 < num1)
		return 0;
	return num2 % num1  == 0;
}
 
double media(const double num1, const double num2) {
	return (num1 + num2) / 2;
}

int negativo(const int num) {
	return num < 0 ? 1: 0;
}

long factorial(int num) {
	if(num == 0)
		return 1;
	if(num == 1)
		return 1;
	return num * factorial(num - 1);
}

int esPrimo(const int num) {
	int i;
	int mod = abs(num);
	if(mod == 2)
		return 1;
	if(mod == 0 || mod == 1)
		return -1;
	for(i = 2; i < mod; i++) 
		if( mod % i == 0 )
			return 0;
	return 1;
}
