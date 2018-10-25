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
	std::cout<<"	q	Termina el programa\n"
	std::cin>>aux;
	return aux.tolower();
}

bool comprobacionGuardado(bool& guardado) {
	char ans = 'y';
	if (!guardado) {
		ans = 'n';
		std::cout<<"Hay cambios sin guardar, ¿quiere guardarlos?(y/n) ";
		std::cin>>ans;
		bool aux = (ans.tolower()=='y')?true:false;
		guardado = aux?salvar(crono):true;
	}
	return guardado;
}

bool salvar(const cronologia& crono) {
	std::string fichero;
	std::cout<<"Introduce la ruta del fichero de salida:\n";
	std::cin>>fichero;
	
	std::ofstream fout(fichero);
	bool aux = false;
	if (fout.is_open()) {
		std::cout<<"Abriendo fichero\n";
		std::fout<<crono;
		aux = true;
	}
	if (!aux) {
		std::cout<<"Error en el guardado, no se han realizado cambios.\n";
		std::cout<<"Intentelo de nuevo\n";
	}

	fout.close();
	return aux;
}

void mostrarEventos(const cronologia& crono) {
	int anio;
	std::cout<<"Introduzca el anio:\n";
	std::cin>>anio;

	std::cout<<crono.getEventos(anio);
	return;
}

void mostrarCronologia(const cronologia& crono) {
	char ans = 'y';
	if (crono.getNFechas() > 15) {
		std::cout<<"Se mostraran "<<crono.getNFechas()<<" lineas.\n";
		std::cout<<"¿Esta seguro?(y/n) ";
		std::cin>>ans;
	}

	bool aux = (ans.tolower()=='y')?true:false;
	if (aux)
		std::cout<<crono;
	return;
}

void unirNueva(cronologia& crono, bool& guardado) {
	comprobacionGuardado(guardado);
	do {
		std::string fichero;
		std::cout<<"Introduzca la ruta de la cronologia a añadir\n";
		std::cin>>fichero;
		crono+=fichero;
		ans = 'n';
		std::cout<<"¿Desea añadir mas ficheros?(y/n) ";
		std::cin>>ans;
	} while(ans=='y');
	return;
}

void periodoCrono(cronologia& crono, bool& guardado) {
	comprobacionGuardado(guardado);
	int anioDesde, anioHasta;
	std::cout<<"Introduzca el periodo seleccionado(ex:1999 2018) ";
	std::cin<<anioDesde<<anioHasta;
	crono = crono.subCronologia(anioDesde,anioHasta);
	return;
}

void claveCrono(cronologia& crono, bool& guardado) {
	comprobacionGuardado(guardado);
	std::string clave;
	std::cout<<"Introduzca la clave de búsqueda: ";
	std::cin>>clave;
	crono = crono.cronologiaClave(clave);
}

void eliminaAnio(cronologia& crono, bool& guardado) {
	comprobacionGuardado(guardado);
	int anio;
	std::cout<<"Introduzca el año a eliminar: ";
	std::cin>>anio;
	if (!crono.eliminaFecha(anio))
		std::cout<<"Ha habido un error, por favor intentelo de nuevo\n";
	return;
}

bool quit(bool& exit, bool& guardado) {
	do {
		exit = comprobacionGuardado(guardado);
	} while(!guardado);
	return exit;
}

void defaultCrono(char& opt) {
	std::cout<<"Disculpe, no le he entendido, vuelva a introducir la opcion\n";
	std::cin>>opt;
	return;
}
