/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 08/10/2021 17:20
*/

#include "clasePasajeros.h"
#include "claseMaletas.h"

/**
 * @brief Constructor de la clase Pasajero
 * 
 * @param nombre Nombre del pasajero
 * @param edad Edad del pasajero
 * @param pasaporte Pasaporte del pasajero
 * @param nacionalidad Nacionalidad del pasajero
 * @param sexo Sexo del pasajero
 * @param maleta Maleta del pasajero
*/
Pasajero::Pasajero(std::string nombre, int edad, Pasaporte pasaporte, std::string nacionalidad, std::string sexo, Maleta maleta)
        : nombre(nombre), edad(edad), pasaporte(pasaporte), nacionalidad(nacionalidad), sexo(sexo), maleta(new Maleta(maleta)) {
}


/**
 * @brief Muestra los datos del pasajero por consola
 * 
 */
void Pasajero::mostrarDatos() {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Edad: " << edad << std::endl;
    std::cout << "Pasaporte: " << pasaporte.codigo << std::endl;
    std::cout << "Nacionalidad: " << nacionalidad << std::endl;
    std::cout << "Sexo: " << sexo << std::endl;
    std::cout << "Maleta: " << maleta->getDescripcion() << std::endl;
}


/**
 * @brief Retorna el nombre del pasajero.
 * 
 * @return std::string El nombre del pasajero.
 */

std::string Pasajero::getNombre() {
    return nombre;
}

/**
 * @brief Retorna la edad del pasajero.
 * 
 * @return int La edad del pasajero.
*/
int Pasajero::getEdad() {
    return edad;
}

/**
 * @brief Retorna el pasaporte del pasajero.
 * 
 * @return Pasaporte El pasaporte del pasajero.
*/
Pasaporte Pasajero::getPasaporte() {
    return pasaporte;
}

/**
 * @brief Retorna la nacionalidad del pasajero.
 * 
 * @return std::string La nacionalidad del pasajero.
*/
std::string Pasajero::getNacionalidad() {
    return nacionalidad;
}

/**
 * @brief Retorna el sexo del pasajero.
 * 
 * @return std::string El sexo del pasajero.
*/
std::string Pasajero::getSexo() {
    return sexo;
}

/**
 * @brief Retorna la maleta del pasajero.
 * 
 * @return Maleta La maleta del pasajero.
*/
Maleta Pasajero::getMaleta() {
    return *maleta;
}

/**
 * @brief Retorna el contenido de la maleta del pasajero.
 * 
 * @return std::string El contenido de la maleta del pasajero.
*/
std::string Pasajero::getContenidoMaleta() {
    std::string contenido = "";
    for (auto it = maleta->getContenido().begin(); it != maleta->getContenido().end(); ++it) {
        contenido += *it;
        contenido += ", ";
    }
    return contenido;
}