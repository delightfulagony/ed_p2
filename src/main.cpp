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
		std::cout<<"Error: Añada al menos un archivo de cronologia\n";
		return -1;
	}
	
	//Calculo de la cronologia total a partir de los parametros de entrada
	cronologia crono;
	for(size_t i=1;i<argc;i++)
		crono += argv[i];
	
	//Rutina habitual del programa
	char opt = 'q';
	bool guardado = true;
	bool exit = false;
	do {
		opt = menu();
		switch(opt) {
			case 's':
				guardado = salvar(crono);
				break;
			case 'a':
				mostrarEventos(crono);
				break;
			case 'm':
				mostrarCronologia(crono);
				break;
			case 'u':
				unirNueva(crono,guardado);
				break;
			case 'p':
				periodoCrono(crono,guardado);
				break;
			case 'c':
				claveCrono(crono,guardado);
				break;
			case 'e':
				eliminaAnio(crono);
				break;
			case 'q':
				exit = quit(guardado);
				break;
			default:
				defaultCrono(opt);
				break;
		}
	} while(!exit);
	
	return 0;
}
