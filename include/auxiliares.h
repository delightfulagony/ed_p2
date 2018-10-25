/**
 * @file auxiliares.h
 * @brief Fichero cabecera de las funciones auxiliares de 'main.cpp'
 * @author Gonzalo Moreno Soto
 * @author Manuel Gachs Ballegeer
 * @license GPLv3
 */

#ifndef __AUXILIARES
#define __AUXILIARES

/**
 * @brief Menu de opciones de cronologia
 * @return Opción seleccionada
 */
char menu();

bool comprobacionGuardado(bool& guardado);

bool salvar(const cronologia& crono);

void mostrarEventos(const cronologia& crono);

void mostrarCronologia(const cronologia& crono);

void unirNueva(cronologia& crono, bool& guardado);

void periodoCrono(cronologia& crono, bool& guardado);

void claveCrono(cronologia& crono, bool& guardado);

void eliminaAnio(cronologia& crono, bool& guardado);

bool quit(bool& exit, bool& guardado);

void defaultCrono(char& opt);

#endif
