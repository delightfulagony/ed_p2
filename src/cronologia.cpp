/**
 * @file cronologia.h
 * @brief Fichero fuente del TDA cronologia
 * @author Gonzalo Moreno Soto
 * @license GPLv3
 */

#include "cronologia.h"
#include "fechahistorica.h"
#include <iostream>

void cronologia::reservarMemoria(const unsigned int& _nFechas) {
	liberarMemoria();
	nFechas = _nFechas;
	fechas = new fechahistorica[_nFechas];
}

void cronologia::liberarMemoria() {
	if (fechas==NULL)
		return;
	delete[] fechas;
	nFechas = 0;
}

void cronologia::copiar(const cronologia& copia) {
	nFechas = copia.nFechas;
	reservarMemoria(nFechas);
	for(std::size_t i=0;i<nFechas;i++)
		fechas[i] = copia.fechas[i];
}

void cronologia::resize(const unsigned int& tamanio) {
	cronologia aux(*this);
	reservarMemoria(tamanio);
	std::size_t min = (aux.getNFechas()?tamanio:aux.getNFechas);
	for (std::size_t i=0;i<min;i++)
		fechas[i] = aux.getEventos(i);
	nFechas=tamanio;
}

void cronologia::ordenaCronologia() {
	fechahistorica aux;
	for (std::size_t i=0;i<nFechas;i++) {
		for (std::size_t j=nFechas-1;j>=0;j--) {
			if (fechas[i].getAnio() > fechas[j].getAnio()) {
				aux = fechas[i];
				fechas[i] = fechas[j];
				fechas[j] = aux;
			}
		}
	}
}

cronologia::cronologia() {
	nFechas = 0;
	fechas = NULL;
}

cronologia::cronologia(const unsigned int& _nFechas) {
	nFechas = _nFechas;
	reservarMemoria(nFechas);
}

int cronologia::buscarEvento(const std::string& evento) const {
	for (std::size_t i=0;i<nFechas;i++) {
		for(std::size_t j=0;j<fechas[i].getNumEventos();j++) {
			if (fechas[i][j]==evento)
				return fechas[i].getAnio();
		}
	}
}

fechahistorica cronologia::getEventos(const int& anio) const {
	for (std::size_t i=0;i<nFechas;i++) {
		if (fechas[i].getAnio() == anio)
			return fechas[i];
	}
}

bool cronologia::estaFecha(const int& anio) {
	for (std::size_t i=0;i<nFechas;i++) {
		if (fechas[i].getAnio()==anio)
			return true;
	}
	return false;
}

bool cronologia::asignarFecha(const fechahistorica& fecha) {
	resize(nFechas+1);
	fechas[nFechas-1]=fecha;
}

bool cronologia::eliminaFecha(const int& anio) {
	for (std::size_t i=0;i<nFechas;i++) {
		if (fechas[i].getAnio()==anio)
			fechas[i]=fechas[nFechas-1];
	}
	resize(nFechas-1);
	ordenaCronologia;
}

cronologia& cronologia::unionCronologias(const cronologia& sumaCronologia) {
	for (std::size_t i=0;i<nFechas;i++) {
		for (std::size_t j=0;j<sumaCronologia.nFechas;j++) {
			if (fechas[i].getAnio()==sumaCronologia[j].getAnio()) {
				fechas[i] += sumaCronologia.fechas[j];
			} else {
				asignarFecha(sumaCronologia.fechas[j];
			}
		}
	}
	ordenaCronologia();
	return *this;
}

cronologia& cronologia::subCronologia(const int& anioDesde, const int& anioHasta) const {
	cronologia subCrono;
	for (std::size_t i=0;i<nFechas;i++) {
		if (fechas[i].getAnio()>=anioDesde and fechas[i].getAnio()<=anioHasta)
			asignarFecha(fechas[i]);
	}
	ordenaCronologia();
	return *this;
}
cronologia& cronologia::cronologiaClave(const std::string& clave) const {
	cronologia subCrono;
	fechahistorica auxFecha;
	std::size_t encontrado;
	for (std::size_t i=0;i<nFechas;i++) {
		for (std::size_t j=0;j<fechas[i].getNumEventos();j++) {
			encontrado=fechas[i]getEvento(j).find(clave);
			if (encontrado!=std::string::npos)
				auxFecha.asignarEvento(fechas[i].getEvento(j));
		}
		subCrono.asignarFecha(auxFecha);
	}
	return subCrono;

}

cronologia& cronologia::operator=(const cronologia& crono) {
	copiar(crono);
	return *this;
}

cronologia& operator+(const cronologia& crono) {
	cronologia resultado;
	resultado.copiar(*this);
	resultado.unionCronologias(crono);
	return resultado;
}

cronologia& operator+=(const cronologia& crono) {
	unionCronologias(crono);
	return *this;
} 

std::ostream& operator<<(std::ostream& os, const cronologia& crono) {
	for (std::size_t i=0;i<crono.nFechas;i++)
		os << crono.fechas[i] << endl;
	return os;
}

std::istream& operator>>(std::istream& is, cronologia& crono) {
	is >> crono.nFechas;
	crono.reservarMemoria(crono.nFechas);
	for (std::size_t i=0;i<crono.nFechas;i++)
		is >> crono.fechas[i];
	return is;
}
