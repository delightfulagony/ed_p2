/**
 * @file cronologia.h
 * @brief Fichero fuente del TDA cronologia
 * @author Manuel Gachs Ballegeer
 * @author Gonzalo Moreno Soto
 * @license GPLv3
 */

#include "cronologia.h"

void cronologia::reservarMemoria(const unsigned int% _nFechas) {
	liberarMemoria();
	nFechas = _nFechas;
	fechas = new fechaHistorica[_nFechas];
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
	for(size_t i=0;i<nFechas;i++)
		fechas[i] = copia.fechas[i];
}

void cronologia::resize(const unsigned int& tamanio) {
	fechaHistorica aux(*this);
	reservarMemoria(tamanio);
	size_t min = (aux.getNFechas()?tamanio:aux.getNFechas);
	for (size_t i=0;i<min;i++)
		fechas[i] = aux.getEventos(i);
	nFechas=tamanio;
}

void cronologia::ordenaCronologia() {
	fechaHistorica aux;
	for (size_t i=0;i<nFechas;i++) {
		for (size_t j=nFechas-1;j>=0;j--) {
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
	for (size_t i=0;i<nFechas;i++) {
		for(size_t j=0;j<fechas[i].getNumEventos();j++) {
			if (fechas[i][j]==evento)
				return fechas[i].getAnio();
		}
	}
}

fechaHistorica cronologia::getEventos(const int& anio) const {
	for (size_t i=0;i<nFechas;i++) {
		if (fechas[i].getAnio() == anio)
			return fechas[i];
	}
}

bool cronologia::estaFecha(const int& anio) {
	for (size_t i=0;i<nFechas;i++) {
		if (fechas[i].getAnio()==anio)
			return true;
	}
	return false;
}

bool cronologia::añadirFecha(const fechaHistorica& fecha) {
	resize(nFechas+1);
	fechas[nFechas-1]=fecha;
}

bool cronologia::eliminaFecha(const int& anio) {
	for (size_t i=0;i<nFechas;i++) {
		if (fechas[i].getAnio()==anio)
			fechas[i]=fechas[nFechas-1];
	}
	resize(nFechas-1);
	ordenaCronologia;
}

cronologia& cronologia::unionCronologias(const cronologia& sumaCronologia) {
	for (size_t i=0;i<nFechas;i++) {
		for (size_t j=0;j<sumaCronologia.nFechas;j++) {
			if (fechas[i].getAnio()==sumaCronologia[j].getAnio()) {
				fechas[i] += sumaCronologia.fechas[j];
			} else {
				añadirFecha(sumaCronologia.fechas[j];
			}
		}
	}
	ordenaCronologia();
	return *this;
}

cronologia& cronologia::subCronologia(const int& anioDesde, const int& anioHasta) const {
	cronologia subCrono;
	for (size_t i=0;i<nFechas;i++) {
		if (fechas[i].getAnio()>=anioDesde and fechas[i].getAnio()<=anioHasta)
			añadirFecha(fechas[i]);
	}
	ordenaCronologia();
	return *this;
}
cronologia& cronologia::cronologiaClave(const std::string& clave) const {}

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
