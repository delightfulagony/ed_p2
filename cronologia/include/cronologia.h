/**
 * @file cronologia.h
 * @brief Fichero cabecera del TDA cronologia
 * @author Manuel Gachs Ballegeer
 * @author Gonzalo Moreno Soto
 * @license GPLv3
 */
 
#ifndef __CRONOLOGIA
#define __CRONOLOGIA
 
 /**
  * @brief T.D.A. cronologia
  * Una instancia @e c del tipo de dato abstracto @c cronologia es un objeto
  * que representa un conjunto de fechas ordenadas cronológicamente junto a 
  * los eventos ocurridos en tales fechas
  * @author Manuel Gachs Ballegeer
  * @author Gonzalo Moreno Soto
  * @date Octubre 2018
  */
class cronologia {
private:
	/**
  	 * @page repConjunto Rep del TDA cronologia
  	 * @section invConjunto Invariante de la representación
  	 * @section faConjunto Función de abstracción
  	 * Un objeto válido @e rep del TDA cronologia representa al valor
  	 * (rep.nFechas,rep.*fechas)
  	 */
  	 
	unsigned int nFechas;	    ///< Número de fechas en la cronologia
	fechaHistorica *fechas;	    ///< Conjunto de fechas con eventos
	
	void reservarMemoria(const unsigned int& _nFechas);
	void liberarMemoria();
	void copiar(const cronologia& copia);
public:
	/**
	 * @brief Constructor por defecto de cronologia. Crea una cronología
	 * con 0 fechas
	 */
	cronologia();
	/**
	 * @brief Constructor por copia de cronologia
	 * @param copia Objeto a copiar por el constructor
	 */
	cronologia(const cronologia& copia);
	/**
	 *
	cronologia(const unsigned int& _nFechas, const fechaHistorica _fechas[]);		
};
