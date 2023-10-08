/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 10/09/2021 15:35
*/

#include "claseZonas.h"

// Constructor
Zonas::Zonas(int capacidad, int cantidadPersonas, int cantidadMaletas) {
    this->capacidad = capacidad;
    this->cantidadPersonas = cantidadPersonas;
    this->cantidadMaletas = cantidadMaletas;
}

// Métodos de acceso
int Zonas::getCapacidad() const {
    return this->capacidad;
}

int Zonas::getCantidadPersonas() const {
    return this->cantidadPersonas;
}

int Zonas::getCantidadMaletas() const {
    return this->cantidadMaletas;
}

void Zonas::setCantidadPersonas(int nuevaCantidad) {
    this->cantidadPersonas = nuevaCantidad;
}


