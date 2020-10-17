
#define TAM 100
#define ES_PAR(X)((X) % 2 == 0)

typedef double (*t_mat)();
typedef int (*t_cmp)(const void *, const void *);

/// Matemática
double potencia(const double num, const int pot);
double suma(const double num1, const double num2);
double resta(const double num1, const double num2);
double mul(const double num1, const double num2);
double division(const double num1, const double num2);
int esPar(const int num);
double media(const double num1, const double num2);
int negativo(const int num);
int multiplo(const int num1, const int num2);
long factorial(int num);
int esPrimo(const int num);


/// LLamadas
void pbaPotencia();
double sumarValores();
double restarValores();
double mulValores();
double divValores();
void pbaMostrarIntercambio(int num1, int num2);
void pbaPedirValores();
void pbaAreas();
void pbaEsPar();
void pbaMedia();
void pbaNegativo();
void pbaEdades();
void pbaEmpleado();
void pbaSalario();
void pbaMultiplos5();
void pbaPares200();
void pbaPrimo();
void pbaAntSig ();
/// Menu
char mostrarMenu(char opciones[][TAM], const char *mje);
int validarOpcion(char *opciones, char op);
char seleccionarOpcion(char opciones[][TAM], const char * titulo);



