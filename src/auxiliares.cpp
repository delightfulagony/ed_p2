/**
 * @file auxiliares.cpp
 * @brief Fichero fuente de las funciones auxiliares de 'main.cpp'
 * @author Gonzalo Moreno Soto
 * @author Manuel Gachs Ballegeer
 * @license GPLv3
 */
#include "auxiliares.h"
#include <iostream>

char menu() {
	char aux = 'q';
	std::cout<<"_______________________________________M E N U_______________________________________\n";
	std::cout<<"Menu del programa:\n";
	std::cout<<"	s	Guarda la cronologia en el archivo seleccionado\n";
	std::cout<<"	a	Muestra todos los eventos acaecidos en el anio seleccionado\n";
	std::cout<<"	p	Crea una subcronologia en el periodo de los anios dados\n";
	std::cout<<"	c	Crea una subcronologia a partir de una palabra clave\n";
	std::cout<<"	e	Elimina un año de la cronologia\n";
	std::cout<<"	q	Termina el programa\n"
	std::cout<<"_____________________________________________________________________________________\n";
	std::cin>>q;
}
