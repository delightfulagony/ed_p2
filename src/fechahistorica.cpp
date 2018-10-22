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

void fechaHistorica::redimensionar(const unsigned int& t) {
	fechaHistorica aux(*this);
	liberarMemoria();
	reservarMemoria(t);
	size_t min = (t<aux.getNumEventos())?t:aux.getNumEventos();
	for (size_t i=0;i<min;i++)
		eventos[i] = aux.eventos[i];
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

void fechaHistorica::asignarEvento(const std::string& nuevo, const int indice=-1) {
	if (indice!=-1 && indice<nEventos)
		eventos[indice] = nuevo;
	else {
		nEventos += 1;
		redimensionar(nEventos);
		eventos[nEventos-1] = nuevo;
	}
}

fechaHistorica& fechaHistorica::suma(const fechaHistorica& sumaFechaHistorica) {
	if (anio==sumaFechaHistorica.anio) {
		unsigned int aux = nEventos;
		for (size_t i=0;i<sumaFechaHistorica.nEventos;i++) {
			bool repetido = false;
			for (size_t j=0;j<aux && !repetido;j++)
				if (eventos[j]==sumaFechaHistorica.eventos[i])
					repetido = true;
			if (!repetido)
				asignarEvento(sumaFechaHistorica.eventos[i]);
		}
	return *this;
}

int fechaHistorica::buscarEvento(const std::string& _evento) const {
	int aux = -1;
	for (size_t i=0;i<nEventos && aux==-1;i++)
		if (_evento==evento[i])
			aux = i;
	return aux;
}

fechaHistorica& fechaHistorica::operator=(const fechaHistorica& fechaH) {
	copiar(fechaH);
	return *this;
}

std::istream& operator>>(std::istream& i, fechaHistorica& fechaH) {
	int _anio;
	char aux;
	is >> _anio >> aux;
	fechaHistorica aux(_anio);
	
	std::string cadenaEventos;
	std::getline(is,cadenaEventos);
	unsigned int ultimaAlmohadilla = 0;
	unsigned int comienzoEvento = 0;
	
	while (ultimaAlmohadilla!=-1) {
		std::string _evento;
		ultimaAlmohadilla = cadenaEventosfind('#');
		if (ultimaAlmohadilla!=-1) {
			_evento = substr(comienzoEvento,ultimaAlmohadilla-comienzoEvento);
		}	
		else
			_evento = substr(comienzoEvento,-1);
		comienzoEvento = ultimaAlmohadilla + 1;
		aux.asignarEvento(_evento);
	}
	return is;
}

std::ostream& operator<<(std::ostream& o, const fechaHistorica& fechaH) {
	os << fechaH.getAnio();
	for (size_t i=0;i<fechaH.getNumEventos();i++)
		os << "#" << fechaH.getEvento(i);
	os << endl;
	return os;
}
