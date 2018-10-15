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
		return 0;
	delete[] fechas;
	nFechas = 0;
}

void cronologia::copiar(const cronologia& copia) {
	nFechas = copia.nFechas;
	reservarMemoria(nFechas);
	for(size_t i=0;i<nFechas;i++)
		fechas[i] = copia.fechas[i];
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

fechaHistorica getEventos(const int& anio) const {
	for (size_t i=0;i<nFechas;i++) {
		if (fechas[i].getAnio() == anio)
			return fechas[i];
	}
}

