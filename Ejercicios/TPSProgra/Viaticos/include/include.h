#include <stdio.h>
#include <stdlib.h>


float calcularMonto( const float km, const float gastoComidas, const float gastoPeaje);

int ingresarDatosEntrada( int * cEmp, char * cat, float * km, float * gc, float * gp, float * ant );
void titulo( char * tit );
char ingresarCondFin();
void mostrarGastoViatico( const float monto );
void mostrarCantVendedores( const int cantVen );
