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
	liberarMemoria();
	nEventos = _nEventos;
	eventos = new std::string[nEventos];
}

void fechaHistorica::copiar(const fechaHistorica& copia) {
	anio = copia.anio;
	reservarMemoria(copia.nEventos);
	for (size_t i=0;i<nEventos;i++)
		eventos[i] = copia.eventos[i];
}

void fechaHistorica::liberarMemoria() {
	if (eventos!=NULL)
		delete[] eventos;
	anio = 1;
	nEventos = 0;
}

fechaHistorica::fechaHistorica() {
	anio = 1;
	nEventos = 0;
}

fechaHistorica::fechaHistorica(const int& _anio, const unsigned int& _nEventos=0) {
	anio = _anio;
	if (_nEventos!=0)
		reservarMemoria(_nEventos);
}

void fechaHistorica::redimensionar(const unsigned int& t) {
	fechaHistorica aux(*this);
	liberarMemoria();
	reservarMemoria(t);
	size_t min = (t<aux.getNumEventos())?t:aux.getNumEventos();
	for (size_t i=0;i<min;i++)
}
