/**
 * @file auxiliares.cpp
 * @brief Fichero fuente de las funciones auxiliares de 'main.cpp'
 * @author Gonzalo Moreno Soto
 * @author Manuel Gachs Ballegeer
 * @license GPLv3
 */
#include "auxiliares.h"
#include "cronologia.h"
#include <iostream>
#include <fstream>
#include <string>

char menu() {
	char aux = 'q';
	std::cout<<"Menu del programa:\n";
	std::cout<<"	s	Salva la cronologia en el archivo seleccionado\n";
	std::cout<<"	a	Muestra todos los eventos acaecidos en el anio seleccionado\n";
	std::cout<<"	m	Muestra toda la cronologia en pantalla\n";
	std::cout<<"	u	Aniade la cronologia de un fichero\n";
	std::cout<<"	p	Crea una subcronologia en el periodo de los anios dados\n";
	std::cout<<"	c	Crea una subcronologia a partir de una palabra clave\n";
	std::cout<<"	e	Elimina un año de la cronologia\n";
	std::cout<<"	q	Termina el programa\n";
	std::cout<<"Su elección: ";
	std::cin>>aux;
	return tolower(aux);
}

bool comprobacionGuardado(cronologia& crono,bool& guardado) {
	char ans = 'y';
	bool aux = false;
	if (!guardado) {
		ans = 'n';
		std::cout<<"Hay cambios sin guardar, ¿quiere guardarlos?(y/n) ";
		std::cin>>ans;
		aux = (tolower(ans)=='y')?true:false;
	}
	if (aux) {
		guardado = salvar(crono);
		return guardado;
	}
	else
		return true;

}

bool salvar(const cronologia& crono) {
	std::string fichero;
	std::cout<<"Introduce la ruta del fichero de salida: \n";
	std::cin>>fichero;

	std::ofstream fout(fichero);
	bool aux = false;
	if (fout.is_open()) {
		std::cout<<"Abriendo fichero...\n";
		fout<<crono;
		aux = true;
	}
	if (!aux) {
		std::cout<<"Error en el guardado, no se han realizado cambios.\n";
		std::cout<<"Intentelo de nuevo\n";
	}
	else
		std::cout<<"Cronologia guardada con exito\n";
	
	fout.close();
	return aux;
}

void mostrarEventos(const cronologia& crono) {
	int anio;
	std::cout<<"Introduzca el anio: ";
	std::cin>>anio;
	if (crono.estaFecha(anio))
		std::cout<<crono.getEventos(anio);
	else
		std::cout<<"El año que ha introducido no se encuentra en la cronologia\n";
	return;
}

void mostrarCronologia(const cronologia& crono) {
	char ans = 'y';
	if (crono.getNFechas() > 15) {
		std::cout<<"Se mostraran "<<crono.getNFechas()<<" lineas. ";
		std::cout<<"¿Esta seguro?(y/n) ";
		std::cin>>ans;
	}

	bool aux = (tolower(ans)=='y')?true:false;
	if (aux)
		std::cout<<crono;
	return;
}

void unirNueva(cronologia& crono, bool& guardado) {
	char ans;
	comprobacionGuardado(crono,guardado);
	do {
		char fichero[100];
		std::cout<<"Introduzca la ruta de la cronologia a añadir: ";
		std::cin>>fichero;
		cronologia aux;
		aux.deArchivo(fichero);
		crono += aux;
		ans = 'n';
		std::cout<<"¿Desea añadir mas ficheros?(y/n) ";
		std::cin>>ans;
	} while(tolower(ans)=='y');
	guardado = false;
	return;
}

void periodoCrono(cronologia& crono, bool& guardado) {
	comprobacionGuardado(crono,guardado);
	int anioDesde, anioHasta;
	do {
	std::cout<<"Introduzca el periodo seleccionado(ex:1999 2018): ";
	std::cin>>anioDesde>>anioHasta;
	if (anioDesde>anioHasta)
		std::cout<<"Error, el periodo es imposible\n";
	} while(anioDesde>anioHasta);
	crono = crono.subCronologia(anioDesde,anioHasta);
	guardado = false;
	return;
}

void claveCrono(cronologia& crono, bool& guardado) {
	comprobacionGuardado(crono,guardado);
	std::string clave;
	std::cout<<"Introduzca la clave de búsqueda: ";
	std::cin>>clave;
	cronologia aux(crono);
	aux = aux.cronologiaClave(clave);
	if (aux.getNFechas()==0)
		std::cout<<"Error, no hay ningun evento con la palabra seleccionada.\n";
	else
		crono = aux;
	guardado = false;
	return;
}

void eliminaAnio(cronologia& crono, bool& guardado) {
	comprobacionGuardado(crono,guardado);
	int anio;
	std::cout<<"Introduzca el año a eliminar: ";
	std::cin>>anio;
	if (!crono.eliminaFecha(anio))
		std::cout<<"Ha habido un error, por favor intentelo de nuevo\n";
	else
		guardado = false;
	return;
}

bool quit(cronologia& crono,bool& guardado) {
	bool aux = true;
	do {
		aux = comprobacionGuardado(crono,guardado);
	} while(!aux);
	return aux;
}

void defaultCrono() {
	std::cout<<"Error, opcion desconocida, intruduzca una de las posibles opciones:\n";
	return;
}
