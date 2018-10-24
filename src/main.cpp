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
	//Comprobación inicial
	if (argc<2) {
		ayuda();
		return -1;
	}
	
	char opt = 'q';
	do {
		opt = menu();

	} while(opt!='q');
	
	return 0;
}
