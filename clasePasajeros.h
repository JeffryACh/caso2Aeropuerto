/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 08/10/2021 17:20
*/

#ifndef CASO2_ED_CLASEPASAJEROS_H
#define CASO2_ED_CLASEPASAJEROS_H

#endif //CASO2_ED_CLASEPASAJEROS_H
#ifndef PASAJERO_H
#define PASAJERO_H
#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include "claseMaletas.h"

/**
 * @brief Estructura Pasaporte
 * @param codigo
 * @param nacionalidad
 * @param sexo
*/
struct Pasaporte {
    std::string codigo;
    std::string nacionalidad;
    std::string sexo;
};

// Clase Pasajero
/**
 * @brief Clase que representa a un pasajero en un aeropuerto.
 * 
 */
class Pasajero {
private:
    std::string nombre; /**< Nombre del pasajero */
    int edad; /**< Edad del pasajero */
    Pasaporte pasaporte; /**< Pasaporte del pasajero */
    std::string nacionalidad; /**< Nacionalidad del pasajero */
    std::string sexo; /**< Sexo del pasajero */
    Maleta* maleta; /**< Puntero a la maleta del pasajero */

public:
    /**
     * @brief Constructor de la clase Pasajero.
     * 
     * @param nombre Nombre del pasajero.
     * @param edad Edad del pasajero.
     * @param pasaporte Pasaporte del pasajero.
     * @param nacionalidad Nacionalidad del pasajero.
     * @param sexo Sexo del pasajero.
     * @param maleta Maleta del pasajero.
     */
    Pasajero(std::string nombre, int edad, Pasaporte pasaporte, std::string nacionalidad, std::string sexo, Maleta maleta);

    /**
     * @brief Muestra los datos del pasajero.
     * 
     */
    void mostrarDatos();

    /**
     * @brief Obtiene el nombre del pasajero.
     * 
     * @return std::string Nombre del pasajero.
     */
    std::string getNombre();

    /**
     * @brief Obtiene la edad del pasajero.
     * 
     * @return int Edad del pasajero.
     */
    int getEdad();

    /**
     * @brief Obtiene el pasaporte del pasajero.
     * 
     * @return Pasaporte Pasaporte del pasajero.
     */
    Pasaporte getPasaporte();

    /**
     * @brief Obtiene la nacionalidad del pasajero.
     * 
     * @return std::string Nacionalidad del pasajero.
     */
    std::string getNacionalidad();

    /**
     * @brief Obtiene el sexo del pasajero.
     * 
     * @return std::string Sexo del pasajero.
     */
    std::string getSexo();

    /**
     * @brief Obtiene la maleta del pasajero.
     * 
     * @return Maleta* Puntero a la maleta del pasajero.
     */
    Maleta getMaleta();

    /**
     * @brief Obtiene el contenido de la maleta del pasajero.
     * 
     * @return std::string Contenido de la maleta del pasajero.
     */
    std::string getContenidoMaleta();
};

#endif // PASAJERO_H