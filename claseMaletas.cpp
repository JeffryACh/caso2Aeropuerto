/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 10/09/2021 15:35
*/

#include "claseMaletas.h"

// Constructor
Maleta::Maleta(int peso, const std::string& descripcion, const std::string& propietario, const std::vector<std::string>& contenido) {
    this->peso = peso;
    this->descripcion = descripcion;
    this->propietario = propietario;
    this->contenido = contenido;
}

// Métodos de acceso
int Maleta::getPeso() const {
    return this->peso;
}

std::string Maleta::getDescripcion() const {
    return this->descripcion;
}

std::string Maleta::getPropietario() const {
    return this->propietario;
}

std::string Maleta::getContenido() const {
    std::string contenido_str;
    for (const auto& elem : this->contenido) {
        contenido_str += elem + ", ";
    }
    return contenido_str;
}