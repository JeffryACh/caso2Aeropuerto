/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 10/09/2021 15:35
*/

#include "clasePasajeros.h"
#include "claseMaletas.cpp"

// Constructor
Pasajero::Pasajero(std::string nombre, int edad, Pasaporte pasaporte, std::string nacionalidad, std::string sexo, Maleta maleta)
        : nombre(nombre), edad(edad), pasaporte(pasaporte), nacionalidad(nacionalidad), sexo(sexo), maleta(new Maleta(maleta)) {
}

// Método para mostrar los datos del pasajero
void Pasajero::mostrarDatos() {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Edad: " << edad << std::endl;
    std::cout << "Pasaporte: " << pasaporte.codigo << std::endl;
    std::cout << "Nacionalidad: " << nacionalidad << std::endl;
    std::cout << "Sexo: " << sexo << std::endl;
    std::cout << "Maleta: " << maleta->getDescripcion() << std::endl;
}

// Métodos de acceso
std::string Pasajero::getNombre() {
    return nombre;
}

int Pasajero::getEdad() {
    return edad;
}

Pasaporte Pasajero::getPasaporte() {
    return pasaporte;
}

std::string Pasajero::getNacionalidad() {
    return nacionalidad;
}

std::string Pasajero::getSexo() {
    return sexo;
}

Maleta Pasajero::getMaleta() {
    return *maleta;
}

std::string Pasajero::getContenidoMaleta() {
    std::string contenido = "";
    for (auto it = maleta->getContenido().begin(); it != maleta->getContenido().end(); ++it) {
        contenido += *it;
        contenido += ", ";
    }
    return contenido;
}