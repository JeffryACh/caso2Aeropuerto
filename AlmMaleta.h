/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 08/10/2021 17:20
*/

#ifndef CASO2_ED_ALMMALETA_H
#define CASO2_ED_ALMMALETA_H

#endif //CASO2_ED_ALMMALETA_H
#ifndef ALMACENARMALETAS_H
#define ALMACENARMALETAS_H

#include <iostream>
#include <stack>
#include <string>

/**
 * @brief Clase que representa una maleta en el aeropuerto.
 * 
 */
class Maletas {
public:
    /**
     * @brief Constructor de la clase Maletas.
     * 
     * @param identificacionMaleta Identificación de la maleta.
     */
    Maletas(std::string& identificacionMaleta);
    
    /**
     * @brief Método que retorna la identificación de la maleta.
     * 
     * @return std::string Identificación de la maleta.
     */
    std::string getIdent();
private:
    std::string idMaleta; /**< Identificación de la maleta. */
};

/**
 * Clase que representa un almacenamiento de maletas en un aeropuerto.
 */
class AlmacenarMaletas {
public:
    /**
     * Agrega una maleta al almacenamiento.
     * @param id La maleta a agregar.
     */
    void agregarMaleta(Maletas id);
    
    /**
     * Retira una maleta del almacenamiento.
     */
    void retirarMaleta();
    
    /**
     * Muestra la cantidad de maletas en el almacenamiento.
     */
    void mostrarCantidadMaletas() const;
private:
    std::stack<Maletas> pilaMaletas; /**< Pila de maletas que representa el almacenamiento. */
};

#endif // ALMACENARMALETAS_H