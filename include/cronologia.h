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
	
	void reservarMemoria(const unsigned int& _nFechas);	///< Reserva memoria dinámica
	void liberarMemoria();					///< Libera memoria dinámica
	void copiar(const cronologia& copia);			///< Crea una copia del objeto
	void ordenaCronologia();				///< Ordena las fechas del objeto en orden cronológico
	void resize(const unsigned int& tamanio);		///< Altera el tamaño del objeto
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
	cronologia(const cronologia& copia) {copiar(copia);}
	/**
	 * @brief Constructor primitivo de cronologia.
	 * @param _nFechas Número de fechas que va a incluir la cronología
	 */
	cronologia(const unsigned int& _nFechas);
	/**
	 * @brief Destructor de la clase
	 */
	~cronologia() {liberarMemoria();}
	/**
	 * @brief Observador del número de fechas
	 * @return El número de fechas en la cronología
	 */
	unsigned int getNFechas() const {return nFechas;}
	/**
	 * @brief Buscador de eventos
	 * @param evento Evento que se quiere buscar en la cronología
	 * @return Año en el que se encuentra el evento
	 */
	int buscarEvento(const std::string& evento) const;
	/**
	 * @brief A partir de una fecha dada devuelve todos sus eventos
	 * @param anio Año del  que se quiere saber los eventos
	 * @return La fecha con todos sus eventos. Se devuelve una fecha
	 * vacía si no se encuentra dentro de la cronología
	 */
	fechaHistorica getEventos(const int& anio) const;
	/**
	 * @brief Comprueba si una determinada fecha se encuentra en la
	 * cronología
	 * @param anio Anio del que se quiere saber si se encuentra en 
	 * la cronología
	 * @return @retval true Si la fecha se encuentra en la cronología y
	 * @retval false Si no se encuentra dentro de la cronología
	 */
	bool estaFecha(const int& anio) const;
	/**
	 * @brief Añade una nueva fecha con sus eventos a la cronología
	 * @param fecha Fecha que se quiere añadir
	 * @return @retval true Si se ha realizado la operación exitosamente
	 * @retval false Si ha ocurrido un error durante la operación
	 */
	bool asignarFecha(const fechaHistorica& fecha);
	/**
	 * @brief Elimina una fecha con sus eventos a la cronología
	 * @param anio Año que se quiere eliminar de la cronología
	 * @return @retval true Si se ha realizado la operación exitosamente
	 * @retval false Si ha ocurrido un error durante la operación
	 */
	bool eliminaFecha(const int& anio);
	/**
	 * @brief Realiza la unión de dos cronologías
	 * @param sumaCronologia Cronología que se quiere añadir a la actual
	 * @return La unión de ambas cronologías
	 */
	cronologia& unionCronologias(const cronologia& sumaCronologia);
	/**
	 * @brief Obtiene la (sub)cronologia de eventos historicos acaecidos
	 * en un rango de años determinado
	 * @param anioDesde Año en el que se inicia la (sub)cronologia
	 * @param anioHasta Año en el que termina la (sub)cronologia
	 * @return (Sub)cronologia resultante
	 */
	cronologia& subCronologia(const int& anioDesde, const int& anioHasta) const;
	/**
	 * @brief Obtiene la (sub)cronologia de eventos historicos asociados
	 * a una palabra clave.
	 * @param clave Palabra a buscar
	 * @return Cronologia de eventos relacionados con la palabra
	 */
	cronologia& cronologiaClave(const std::string& clave) const;
	/**
	 * @brief Sobrecarga del operador de asignación
	 * @param crono Cronología que se asigna a la creada
	 * @return La cronología asignada
	 */
	cronologia& operator=(const cronologia& crono);
	/**
	 * @brief Sobrecarga del operador de suma
	 * @param crono Segundo sumando de la operación
	 * @return La suma de las dos cronologías
	 */
	cronologia& operator+(const cronologia& crono);
	/**
	 * @brief Sobrecarga del operador +=
	 * @param crono Objeto con el que se realiza la operación
	 * @return Resultado de la operación
	 */
	cronologia& operator+=(const cronologia& crono);
	/**
	 * @brief Sobrecarga de el operador de entrada
	 */
	friend std::istream& operator>>(std::istream& i, cronologia& crono);
	/**
	 * @brief Sobrecarga del operador de salida
	 */
	friend std::ostream& operator<<(std::ostream& o, const cronologia& crono);	 
};

std::ostream& operator<<(std::ostream& o, const cronologia& crono);
std::istream& operator>>(std::istream& i, cronologia& crono);

#endif
