 #include "./func.c"
  
  /***
  	TP obligatorio N�2 Codificaci�n de un problema en el lenguaje 
  	de programaci�n c.
  
  	Alumno: Federico Manzano
  	Comisi�n: C4
  	Turno: Noche
  	
  	Desarrollo de las Funciones utulizadas 
  	./func.c
  	
  */

 int main() {
 	
 	// Entradas 
 	int codEquipo, 
	 	cantVictorias, 
		cantDerrotas, 
		cantTriples, 
		cantInfracciones;
 	char nombre[25]; 
 	
 	char cond; // Variable que contiene la condici�n de fin
 	
 	// Valor de salida cantidad de equipos con mal rendimiento
 	int contadorMalDesempeno = 0;
 	
 	// Variables para encontrar el ganador
 	int bandera = 1;
 	int diferenciaMax;
 	int codMax;
 	

 	cond = pedirCondicionFin("Desea evaluar a un equipo (S/N)");
 	
 	
 	while( COND_FIN(cond) ) {
 		// Ingreso de los valores de entrada
 		ingresarDatosEntrada(&codEquipo, nombre, &cantVictorias, &cantDerrotas, &cantTriples, &cantInfracciones);
 		
		/// Definir desempe�o devuelve el contador incrementado si es 
		// que el equipo obtuvo un mal desempe�o
		if( !definirDesempeno( cantVictorias, cantDerrotas, cantTriples,cantInfracciones, nombre ))
			contadorMalDesempeno ++;
		
		// Codigo del equipo ganador
		codMax = calcularGanador(codMax, &diferenciaMax,cantVictorias - cantDerrotas, codEquipo, &bandera);
			
		// Pedir nuevamente la condici�n de fin (S/N) 
 		cond = pedirCondicionFin("Desea evaluar otro equipo (S/N)");
	} // Fin del while
	 
	if(bandera == 0)
		mostrarResultados(codMax, contadorMalDesempeno);
	else {
		system("cls");
		printf(" --- No se ingresaron equipos --- \n\n");
		system("pause");
	}
		

 	return 0;
 }

