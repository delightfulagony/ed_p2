/**
 * @file cronologia.h
 * @brief Fichero fuente del TDA cronologia
 * @author Gonzalo Moreno Soto
 * @author Manuel Gachs Ballegeer
 * @license GPLv3
 */

#include "cronologia.h"
#include "fechahistorica.h"
#include <iostream>
#include <fstream>

void cronologia::reservarMemoria(const unsigned int& _nFechas) {
	liberarMemoria();
	nFechas = _nFechas;
	fechas = new fechahistorica[_nFechas];
}

void cronologia::liberarMemoria() {
	if (fechas!=nullptr)
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
	std::cout<<aux.nFechas<<std::endl;
	std::size_t min = (aux.nFechas>tamanio?tamanio:aux.nFechas);
	std::cout<<min<<std::endl;
	for (std::size_t i=0;i<min;i++) {
		std::cout<<"fechasdei: "<<aux.fechas[i]<<std::endl;
		fechas[i] = aux.fechas[i];
	}
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
	fechas = nullptr;
}

cronologia::cronologia(const unsigned int& _nFechas) {
	nFechas = _nFechas;
	reservarMemoria(nFechas);
}

fechahistorica cronologia::getEventos(const int& anio) const {
	fechahistorica aux;
	for (std::size_t i=0;i<nFechas;i++) {
		if (fechas[i].getAnio() == anio)
			aux = fechas[i];
	}
	return aux;
}

bool cronologia::estaFecha(const int& anio) const {
	for (std::size_t i=0;i<nFechas;i++) {
		if (fechas[i].getAnio()==anio)
			return true;
	}
	return false;
}

void cronologia::asignarFecha(const fechahistorica& fecha) {
	resize(nFechas+1);
	std::cout<<"Fecha[0]: "<<fechas[0]<<std::endl;
	fechas[nFechas-1]=fecha;
	return;
}

bool cronologia::eliminaFecha(const int& anio) {
	bool ans = false;
	for (std::size_t i=0;i<nFechas;i++) {
		if (fechas[i].getAnio()==anio) {
			fechas[i]=fechas[nFechas-1];
			ans = true;
		}
	}
	resize(nFechas-1);
	ordenaCronologia();
	return ans;
}

cronologia& cronologia::unionCronologias(const cronologia& sumaCronologia) {
	for (std::size_t i=0;i<nFechas;i++) {
		for (std::size_t j=0;j<sumaCronologia.nFechas;j++) {
			if (fechas[i].getAnio()==sumaCronologia.fechas[j].getAnio()) {
				fechas[i] += sumaCronologia.fechas[j];
			} else {
				asignarFecha(sumaCronologia.fechas[j]);
			}
		}
	}
	ordenaCronologia();
	return *this;
}

cronologia cronologia::subCronologia(const int& anioDesde, const int& anioHasta) const {
	cronologia subCrono;
	for (std::size_t i=0;i<nFechas;i++) {
		if (fechas[i].getAnio()>=anioDesde and fechas[i].getAnio()<=anioHasta)
			subCrono.asignarFecha(fechas[i]);
	}
	subCrono.ordenaCronologia();
	return subCrono;
}

cronologia cronologia::cronologiaClave(const std::string& clave) const {
	cronologia subCrono;
	fechahistorica auxFecha;
	for (std::size_t i=0;i<nFechas;i++) {
		auxFecha = fechas[i].fechaClave(clave);
		if (auxFecha.getAnio()!=-1)
			subCrono.asignarFecha(auxFecha);
	}
	return subCrono;
}

void cronologia::deArchivo(const char fichero[]) {
	std::ifstream fin(fichero);
	if (fin) {
		std::cout<<std::endl<<fichero<<std::endl;
		fin >> *this;
		std::cout<<"This: "<<*this<<" end this"<<std::endl;
	} else
		std::cout<<"Error en la apertura del fichero\n";
	fin.close();
	//return;
}

cronologia& cronologia::operator=(const cronologia& crono) {
	copiar(crono);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const cronologia& crono) {
	for (std::size_t i=0;i<crono.nFechas;i++)
		os << crono.fechas[i] << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, cronologia& crono) {
	fechahistorica aux;
	do {
		is >> aux;
		crono.asignarFecha(aux);
	} while(is);
	return is;
}
