/**
 * @file fechahistorica.h
 * @brief Fichero fuente del TDA fechahistorica
 * @author Manuel Gachs Ballegeer
 * @author Gonzalo Moreno Soto
 * @license: GPLv3
 */

#include "fechahistorica.h"
#include <iostream>
#include <string>

void fechahistorica::reservarMemoria(const unsigned int& _nEventos) {
	nEventos = _nEventos;
	eventos = new std::string[nEventos];
}

void fechahistorica::copiar(const fechahistorica& copia) {
	anio = copia.anio;
	if (eventos!=nullptr) {
		delete[] eventos;
		eventos = nullptr;
	}
	reservarMemoria(copia.nEventos);
	for (size_t i=0;i<nEventos;i++)
		eventos[i] = copia.eventos[i];

}

void fechahistorica::redimensionar(const unsigned int& t) {
	if (t>0) {
		fechahistorica aux(*this);
		if (eventos!=nullptr) {
			delete[] eventos;
			eventos = nullptr;
		}
		reservarMemoria(t);
		size_t min = (t<aux.getNumEventos())?t:aux.getNumEventos();
		for (size_t i=0;i<min;i++)
			eventos[i] = aux.eventos[i];
	}
}

fechahistorica::fechahistorica() {
	anio = -1;
	nEventos = 0;
	eventos = nullptr;
}

fechahistorica::fechahistorica(const int& _anio, const unsigned int& _nEventos) {
	anio = _anio;
	if (_nEventos!=0)
		reservarMemoria(_nEventos);
	eventos = nullptr;
}

fechahistorica::~fechahistorica() {
	if (eventos!=nullptr) {
		delete[] eventos;
		eventos = nullptr;
	}	
	nEventos = 0;
}

void fechahistorica::asignarEvento(const std::string& nuevo, const int indice) {
	if (indice!=-1 && indice<nEventos)
		eventos[indice] = nuevo;
	else {
		nEventos += 1;
		redimensionar(nEventos);
		eventos[nEventos-1] = nuevo;
	}
}

fechahistorica& fechahistorica::suma(const fechahistorica& sumaFechaHistorica) {
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
	}
	return *this;
}

fechahistorica fechahistorica::fechaClave(const std::string& palabra) const {
	fechahistorica fpalabra;
	for (size_t i=0;i<nEventos;i++)
		if (eventos[i].find(palabra)!=std::string::npos)
			fpalabra.asignarEvento(eventos[i]);
	if (fpalabra.nEventos>0)
		fpalabra.anio = anio;
	
	return fpalabra;
}

fechahistorica& fechahistorica::operator=(const fechahistorica& fechaH) {
	copiar(fechaH);
	return *this;
}

std::istream& operator>>(std::istream& is,fechahistorica& fechaH) {
	int _anio;
	char aux;
	is >> _anio >> aux;
	fechahistorica faux(_anio);

	std::string cadenaEventos;
	std::getline(is,cadenaEventos);
	std::string _evento;

	for (size_t i=0;i<cadenaEventos.size();i++) {
		if (i==(cadenaEventos.size()-1)) {
			_evento+=cadenaEventos[i];
		}
		else if (cadenaEventos[i]!='#') {
			_evento+=cadenaEventos[i];
		}
		else if (cadenaEventos[i]=='#') {
			if (_evento.size()!=0)
				faux.asignarEvento(_evento);
			_evento.clear();
		}
	}

	fechaH = faux;
	return is;
}

std::ostream& operator<<(std::ostream& os, const fechahistorica& fechaH) {
	os << fechaH.getAnio();
	for (size_t i=0;i<fechaH.getNumEventos();i++)
		os << "#" << fechaH.getEvento(i);
	os << std::endl;
	return os;
}
