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
	//Calculo de la cronologia total a partir de los parametros de entrada
	cronologia crono;
	std::cout<<"\nNumero de archivos de entrada: "<<argc-1<<std::endl;
	for(size_t i=1;i<argc;i++) {
		cronologia aux;
		std::cout<<"Incorporando: "<<argv[i]<<std::endl;
		aux.deArchivo(argv[i]);
		crono.unionCronologias(aux);
	}

	//Rutina habitual del programa
	char opt = 'q';
	bool guardado = false;
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
				eliminaAnio(crono,guardado);
				break;
			case 'q':
				exit = quit(crono,guardado);
				break;
			default:
				defaultCrono();
				break;
		}
	} while(!exit);

	return 0;
}
