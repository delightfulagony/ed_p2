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

int main(int argc, char * argv[]) {
	//Comprobaciones iniciales
	bool opcion = false;
	bool opcion_add = false;
	bool opcion_exitfile = false;
	if (argc<2) {
		ayuda();
		return -1;
	}
	
	char opt = 'q';
	do {
		opt = menu();

	} while(opt!='q');
	
   /* Exhibir aquí la funcionalidad programada para el TDA Cronologia / TDA FechaHistorica */ 

   // Algunas sugerencias: 
   // - Obtener los eventos acaecidos en un año dado
   // - Obtener la (sub)cronología de eventos históricos acaecidos en [anioDesde, anioHasta], donde anioDesde y anioHasta son proporcionados por el usuario
   // - Obtener la (sub)cronología de eventos históricos asociados a una palabra clave. Ejemplo: la cronología de eventos asociados a "Einstein"
   // - Operadores sobre cronologías, ejemplo: Unión de dos cronologías (la cronología resultante debería estar ordenada)
   // - Cualquier otra funcionalidad que consideréis de interés
}
