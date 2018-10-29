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
	liberarMemoria();
	nEventos = _nEventos;
	eventos = new std::string[nEventos];
}

void fechahistorica::copiar(const fechahistorica& copia) {
	anio = copia.anio;
	reservarMemoria(copia.nEventos);
	for (size_t i=0;i<nEventos;i++)
		eventos[i] = copia.eventos[i];
}

void fechahistorica::liberarMemoria() {
	if (eventos!=NULL)
		delete[] eventos;
	anio = 1;
	nEventos = 0;
}

void fechahistorica::redimensionar(const unsigned int& t) {
	fechahistorica aux(*this);
	liberarMemoria();
	reservarMemoria(t);
	size_t min = (t<aux.getNumEventos())?t:aux.getNumEventos();
	for (size_t i=0;i<min;i++)
		eventos[i] = aux.eventos[i];
}

fechahistorica::fechahistorica() {
	anio = 1;
	nEventos = 0;
}

fechahistorica::fechahistorica(const int& _anio, const unsigned int& _nEventos) {
	anio = _anio;
	if (_nEventos!=0)
		reservarMemoria(_nEventos);
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

int fechahistorica::buscarEvento(const std::string& _evento) const {
	int aux = -1;
	for (size_t i=0;i<nEventos && aux==-1;i++)
		if (_evento==eventos[i])
			aux = i;
	return aux;
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
	unsigned int ultimaAlmohadilla = 0;
	unsigned int comienzoEvento = 0;
	
	while (ultimaAlmohadilla!=-1) {
		std::string _evento;
		ultimaAlmohadilla = cadenaEventos.find('#');
		if (ultimaAlmohadilla!=-1)
			_evento = cadenaEventos.substr(comienzoEvento,ultimaAlmohadilla-comienzoEvento);
		else
			_evento = cadenaEventos.substr(comienzoEvento,-1);
		comienzoEvento = ultimaAlmohadilla + 1;
		faux.asignarEvento(_evento);
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
