/**
 * @file main.cpp
 * @brief Fichero fuente del programa
 * @author Manuel Gachs Ballegeer
 * @author Gonzalo Moreno Soto
 * @license GPLv3
 */
#include "cronologia.h"
#include "auxiliares.h"
#include <fstream>
#include <iostream>

/**
 * @brief Muestra un mensaje de ayuda en pantalla
 */
void ayuda();

int main(int argc, char * argv[]) {
	//Comprobaciones iniciales
	bool opcion = false;
	bool opcion_add = false;
	bool opcion_exitfile = false;
	if (argc<2) {
		ayuda();
		return -1;
	}
	
   /* Exhibir aquí la funcionalidad programada para el TDA Cronologia / TDA FechaHistorica */ 

   // Algunas sugerencias: 
   // - Obtener los eventos acaecidos en un año dado
   // - Obtener la (sub)cronología de eventos históricos acaecidos en [anioDesde, anioHasta], donde anioDesde y anioHasta son proporcionados por el usuario
   // - Obtener la (sub)cronología de eventos históricos asociados a una palabra clave. Ejemplo: la cronología de eventos asociados a "Einstein"
   // - Operadores sobre cronologías, ejemplo: Unión de dos cronologías (la cronología resultante debería estar ordenada)
   // - Cualquier otra funcionalidad que consideréis de interés
}

void ayuda {
	std::cout<<"_________________________________C R O N O L O G I A_________________________________\n";
	std::cout<<"Uso del programa:\n";
	std::cout<<"./cronologia [-h|-a ficheroCronologia|-f ficheroSalida] fichero1.txt fichero2.txt ...\n";
	std::cout<<"	-h			   Muestra este mensaje de ayuda\n";
	std::cout<<"	-a FicheroCronologia	   Añade las nuevas cronologías a la de FicheroCronologia\n";
	std::cout<<"	-f FicheroSalida	   Guarda las cronologías a FicheroSalida\n";
	std::cout<<"	fichero*.txt		   Ficheros con las cronologías con las que trabajar\n";
	std::cout<<"_____________________________________________________________________________________\n";
}
