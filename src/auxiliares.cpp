/**
 * @file auxiliares.cpp
 * @brief Fichero fuente de las funciones auxiliares de 'main.cpp'
 * @author Gonzalo Moreno Soto
 * @author Manuel Gachs Ballegeer
 * @license GPLv3
 */
#include "auxiliares.h"
#include <iostream>
#include <fstream>
#include <string>

char menu() {
	char aux = 'q';
	std::cout<<"_______________________________________M E N U_______________________________________\n";
	std::cout<<"Menu del programa:\n";
	std::cout<<"	s	Salva la cronologia en el archivo seleccionado\n";
	std::cout<<"	a	Muestra todos los eventos acaecidos en el anio seleccionado\n";
	std::cout<<"	m	Muestra toda la cronologia en pantalla\n";
	std::cout<<"	u	Aniade la cronologia de un fichero\n";
	std::cout<<"	p	Crea una subcronologia en el periodo de los anios dados\n";
	std::cout<<"	c	Crea una subcronologia a partir de una palabra clave\n";
	std::cout<<"	e	Elimina un año de la cronologia\n";
	std::cout<<"	q	Termina el programa\n"
	std::cout<<"_____________________________________________________________________________________\n";
	std::cin>>aux;
	return aux;
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
	if (!guardado) {
		char ans = 'y';
		std::cout<<"Hay cambios sin guardar, ¿quiere guardarlos?(y/n) ";
		std::cin>>ans;
		bool aux = (ans.tolower()=='y')?true:false;
		guardado = aux?salvar(crono):true;

