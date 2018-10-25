/**
 * @file auxiliares.h
 * @brief Fichero cabecera de las funciones auxiliares de 'main.cpp'
 * @author Gonzalo Moreno Soto
 * @author Manuel Gachs Ballegeer
 * @license GPLv3
 */

#ifndef __AUXILIARES
#define __AUXILIARES

#include "cronologia.h"

/**
 * @brief Menu de opciones de cronologia
 * @return Opción seleccionada
 */
char menu();

/**
 * @brief Avisa al usuario si ha guardado la cronologia con la que está trabajando
 * @param guardado Si la cronologia ha sido guardada
 * @return @retval true Si se ha guardado la cronologia o si no se quiere guardar y @retval false
 * si ha habido un fallo durante el guardado
 */
bool comprobacionGuardado(bool& guardado);

/**
 * @brief Guarda una cronologia en un archivo seleccionado
 * @param crono Cronologia que se quiere guardar
 * @return @retval true Si se ha realizado el guardado con exito y @retval false si ha habido un
 * fallo durante el guardado
 */
bool salvar(const cronologia& crono);

/**
 * @brief Muestra en pantalla los eventos acaecidos en un año
 * @param crono Cronologia que contiene los eventos
 */
void mostrarEventos(const cronologia& crono);

/**
 * @brief Muestra una cronologia completa en pantalla
 * @param crono Cronologia que se quiere mostrar
 */
void mostrarCronologia(const cronologia& crono);

/**
 * @brief Aniade una cronologia proveniente de un fichero a otra dada
 * @param crono Cronologia a la que se le va a aniadir la proveniente de un fichero
 * @param guardado Si la cronologia ha sido guardada previamente
 */
void unirNueva(cronologia& crono, bool& guardado);

/**
 * @brief Crea una nueva subcronologia a partir de un periodo de tiempo
 * @param crono Cronologia a la cual se le va a realizar una subcronologia
 * @param guardado Si la cronologia ha sido guardada previamente
 */
void periodoCrono(cronologia& crono, bool& guardado);

/**
 * @brief Crea una nueva subcronologia a partir de una palabra clave
 * @param crono Cronologia a la cual se le va a realizar una subcronologia
 * @param guardado Si la cronologia ha sido guardada previamente
 */
void claveCrono(cronologia& crono, bool& guardado);

/**
 * @brief Elimina un anio de una cronologia
 * @param crono Cronologia a la que se le va a eliminar un anio
 * @param guardado Si la cronologia ha sido guardada previamente
 */
void eliminaAnio(cronologia& crono, bool& guardado);

/**
 * @brief Decide si salir del menu del programa
 * @param guardado Si la cronologia ha sido guardada previamente
 * @return @retval true Si se va a salir del programa y @retval false Si ha habido
 * error en algún punto
 */
bool quit(bool& guardado);

/**
 * @brief Ayuda al usuario en caso de error en el menu
 * @param opt Opcion a elegir del menu
 */
void defaultCrono(char& opt);

#endif
