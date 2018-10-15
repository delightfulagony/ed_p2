/**
 * @file fechahistorica.h
 * @brief Fichero fuente del TDA fechaHistorica
 * @author Manuel Gachs Ballegeer
 * @author Gonzalo Moreno Soto
 * @license: GPLv3
 */

#include "fechahistorica.h"
#include <iostream>
#include <string>

void fechaHistorica::reservarMemoria(const unsigned int& _nEventos) {
	if (eventos!=NULL)
		liberarMemoria();
	anio = 1;
	nEventos = _nEventos;
	eventos = new std::string[nEventos];
}

fechaHistorica::fechaHistorica() {
	anio = 1;
	nEventos = 0;
	eventos = NULL;
}

fechaHistorica::fechaHistorica(const fechaHistorica& copia) {}
