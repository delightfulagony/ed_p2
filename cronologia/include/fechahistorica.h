/**
 * @file fechahistorica.h
 * @brief Fichero cabecera del TDA fechaHistorica
 * @author Manuel Gachs Ballegeer
 * @author Gonzalo Moreno Soto
 * @license: GPLv3
 */

#ifndef __FECHAHISTORICA
#define __FECHAHISTORICA

/**
 * @brief T.D.A. fechaHistorica
 * Una instancia @e c del tipo de datos abstracto @c fechaHistorica es un objeto
 * que representa a una fecha del calendario gregoriano junto con un conjunto de
 * eventos ocurridos durante ese año
 * @author Manuel Gachs Ballegeer
 * @author Gonzalo Moreno Soto
 * @date Octubre 2018
 */
class fechaHistorica {
private:
	/**
	 * @page repConjunto Rep del TDA fechaHistorica
	 * @section invConjunto Invariante de la representación
	 * @section faConjunto Función de abstracción
	 * Un objeto válido @e rep del TDA fechaHistorica representa al valor
	 * (rep.ano,rep.nEventos,rep.*eventos)
	 */

	int ano;		  ///< Año del objeto
	unsigned int nEventos;	  ///< Número de eventos en el año del objeto
	std::string *eventos;	  ///< Array de eventos

	void reservarMemoria(const unsigned int& _nEventos);
	void liberarMemoria();
	void copiar(const fechaHistorica& copia);
public:
	/**
	 * @brief Constructor por defecto de fechaHistorica . Crea la fecha 
	 * 1 D.C con 0 eventos
	 */
	fechaHistorica();
	/**
	 * @brief Constructor por copia del fechaHistorica
	 * @param copia Objeto a copiar por el constructor
	 */
	fechaHistorica(const fechaHistorica& copia);
	/**
	 * @brief Constructor primitivo de fechaHistorica
	 * @param _ano Año del objeto
	 * @param _nEventos Número de eventos en el año del objeto
	 */
	fechaHistorica(const int& _ano, const unsigned int& _nEventos=0);
	/**
	 * @brief Destructor de la clase fechaHistorica
	 */
	~fechaHistorica();	
	/**
	 * @brief Observador del parámetro ano
	 * @return Devuelve el año 
	 */
	int getAno() const {return ano;}
	/**
	 * @brief Observador de eventos
	 * @param indice Indice del array de eventos
	 * @return Evento en el lugar definido por indice
	 */
	std::string getEvento(const unsigned int& indice) const;
	/**
	 * @brief Altera el evento al que se refiere el índice, si no se
	 * proporciona índice, se añade al final.
	 * @param nuevo Evento a introducir en el objeto
	 * @param indice Lugar en el que introducir el evento, si es -1 se añade
	 * el evento al final.
	 */
	void asignarEvento(const std::string& nuevo, const int indice=-1);
	/**
	 * @brief Imprime la fecha en el formato "Año#Evento[1]#...#Evento[n]"
	 */
	void escribirFecha() const;
	/**
	 * @brief Suma al objeto otra fechaHistorica dada
	 * @pre Que ambos objetos tengan el mismo año
	 * @param sumaFechaHistorica objeto fechaHistorica a sumar
	 * @return La suma de los eventos de ambas fechas
	 */
	fechaHistorica& suma(const fechaHistorica& sumaFechaHistorica);
	/**
	 * @brief Busca un evento en el conjunto de eventos de fechaHistorica
	 * @param evento Evento a buscar
	 * @return Devuelve la posición del evento en el conjunto de eventos y
	 * @retval -1 si el evento no se encuentra en la fecha
	 */
	int buscarEvento(const std::string& _evento) const;
};

#endif
