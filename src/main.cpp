#include "cronologia.h"
#include <fstream>
#include <iostream>

/**
 * @brief Muestra un mensaje de ayuda en pantalla
 */
void ayuda();

int main(int argc, char * argv[]) {

	if (argc!=2) {
		cout<<"Error en el número de argumentos\n";
		ayuda();
		return -1;
	}

	ifstream f(argv[1]);
	if (!f) {
	cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
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
	std::cout<<"__________________________________CRONOLOGIA__________________________________\n";
	std::cout<<"Uso del programa:\n";
	std::cout<<"		./cronologia (opcion) [arg]\n";
	std::cout<<"Lista de opciones:\n";
	std::cout<<"	--help		Muestra este mensaje de ayuda\n";
	std::cout<<"	--add		Añade los argumentos a una cronología ya dada como argumento\n";
	std::cout<<"	--\n"
}
