/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 08/10/2021 17:20
*/

#include "claseMaletas.h"


/**
 * @brief Constructor de la clase Maleta
 * 
 * @param peso Peso de la maleta
 * @param descripcion Descripción de la maleta
 * @param propietario Propietario de la maleta
 * @param contenido Vector con el contenido de la maleta
 */
Maleta::Maleta(int peso, const std::string descripcion, const std::string propietario, const std::vector<std::string> contenido) {
    this->peso = peso;
    this->descripcion = descripcion;
    this->propietario = propietario;
    this->contenido = contenido;
}

/**
 * @brief Retorna el peso de la maleta.
 * 
 * @return int Peso de la maleta.
 */
int Maleta::getPeso() const {
    return this->peso;
}

/**
 * @brief Retorna la descripción de la maleta.
 * 
 * @return std::string Descripción de la maleta.
 */
std::string Maleta::getDescripcion() const {
    return this->descripcion;
}

/**
 * @brief Retorna el propietario de la maleta.
 * 
 * @return std::string Propietario de la maleta.
 */
std::string Maleta::getPropietario() const {
    return this->propietario;
}

/**
 * @brief Retorna el contenido de la maleta como una cadena de texto.
 * 
 * @return std::string Cadena de texto con el contenido de la maleta.
 */
std::string Maleta::getContenido() const {
    std::string contenido_str;
    for (const auto& elem : this->contenido) {
        contenido_str += elem + ", ";
    }
    return contenido_str;
}