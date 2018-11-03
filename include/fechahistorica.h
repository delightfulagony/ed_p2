/**
 * @file fechahistorica.h
 * @brief Fichero cabecera del TDA fechahistorica
 * @author Manuel Gachs Ballegeer
 * @author Gonzalo Moreno Soto
 * @license: GPLv3
 */

#ifndef __FECHAHISTORICA
#define __FECHAHISTORICA

#include <string>

/**
 * @brief T.D.A. fechahistorica
 * Una instancia @e c del tipo de datos abstracto @c fechahistorica es un objeto
 * que representa a una fecha del calendario gregorianio junto con un conjunto de
 * eventos ocurridos durante ese año
 * @author Manuel Gachs Ballegeer
 * @author Gonzalo Moreno Soto
 * @date Octubre 2018
 */
class fechahistorica {
private:
	/**
	 * @page repConjunto Rep del TDA fechahistorica
	 * @section invConjunto Invariante de la representación
	 * @section faConjunto Función de abstracción
	 * Un objeto válido @e rep del TDA fechahistorica representa al valor
	 * (rep.anio,rep.nEventos,rep.*eventos)
	 */

	int anio;		  ///< Año del objeto
	unsigned int nEventos;	  ///< Número de eventos en el año del objeto
	std::string *eventos;	  ///< Array de eventos

	void reservarMemoria(const unsigned int& _nEventos);	///< Reserva memoria dinámica
	void copiar(const fechahistorica& copia);		///< Crea una copia del objeto
	void redimensionar(const unsigned int& t);		///< Redimensiona el array de eventos
public:
	/**
	 * @brief Constructor por defecto de fechahistorica. Crea la fecha imposible -1 con 0 eventos
	 */
	fechahistorica();
	/**
	 * @brief Constructor por copia del fechahistorica
	 * @param copia Objeto a copiar por el constructor
	 */
	fechahistorica(const fechahistorica& copia) {copiar(copia);}
	/**
	 * @brief Constructor primitivo de fechahistorica
	 * @param _anio Año del objeto
	 * @param _nEventos Número de eventos en el año del objeto
	 */
	fechahistorica(const int& _anio, const unsigned int& _nEventos=0);
	/**
	 * @brief Destructor de la clase fechahistorica
	 */
	~fechahistorica();	
	/**
	 * @brief Observador del parámetro anio
	 * @return Devuelve el año 
	 */
	int getAnio() const {return anio;}
	/**
	 * @brief Observador del número de eventos
	 * @return El número de eventos
	 */
	int getNumEventos() const {return nEventos;}
	/**
	 * @brief Observador de eventos
	 * @param indice Índice del array de eventos
	 * @return Evento en el lugar definido por índice
	 * @pre El índice debe ser válido
	 */
	std::string getEvento(const unsigned int& indice) const {return eventos[indice];}
	/**
	 * @brief Altera el evento al que se refiere el índice, si no se
	 * proporciona índice, se añade al final.
	 * @param nuevo Evento a introducir en el objeto
	 * @param indice Lugar en el que introducir el evento, si es -1 se
	 * añade el evento al final.
	 */
	void asignarEvento(const std::string& nuevo, const int indice=-1);
	/**
	 * @brief Suma al objeto otra fechahistorica dada
	 * @pre Que ambos objetos tengan el mismo año
	 * @param sumaFechaHistorica objeto fechahistorica a sumar
	 * @return La suma de los eventos de ambas fechas
	 */
	fechahistorica& suma(const fechahistorica& sumaFechaHistorica);
	/**
	 * @brief Crea una nueva instancia de fechahistorica con los eventos que contengan la
	 * palabra dada
	 * @param palabra Palabra que contienen los eventos que buscamos
	 * @return Devuelve una nueva fechahistorica con los eventos seleccionados, siendo una
	 * fecha vacia de no encontrar ninguna coincidencia
	 */
	fechahistorica fechaClave(const std::string& palabra) const;
	/**
	 * @brief Sobrecarga del operador de asignación
	 * @param fechaH fechahistorica que se asigna
	 * @return El objeto fechahistorica asignado
	 */
	fechahistorica& operator=(const fechahistorica& fechaH);
	/**
	 * @brief Sobrecarga del operador de suma
	 * @param fechaH Segundo sumando de la operación
	 * @return La suma de los dos objetos fechahistorica
	 */
	fechahistorica& operator+(const fechahistorica& fechaH) {return suma(fechaH);}
	/**
	 * @brief Sobrecarga del operador +=
	 * @param fechaH Objeto con el que se realiza la operación
	 * @return Resultado de la operación
	 */
	fechahistorica& operator+=(const fechahistorica& fechaH) {return suma(fechaH);}
	/**
	 * @brief Sobrecarga de el operador de entrada
	 */
	friend std::istream& operator>>(std::istream& is, fechahistorica& fechaH);
	/**
	 * @brief Sobrecarga del operador de salida. Imprime la fecha en el 
	 * formato "Año#Evento[1]#...#Evento[n]"
	 */
	friend std::ostream& operator<<(std::ostream& os, const fechahistorica& fechaH);
};

std::istream& operator>>(std::istream& is, fechahistorica& fechaH);
std::ostream& operator<<(std::ostream& os, const fechahistorica& fechaH);

#endif
