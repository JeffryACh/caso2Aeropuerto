/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 
*/

#include "claseRetencion.h"
#include "claseZonas.h"

// Constructor
Retencion::Retencion(int capacidad, int cantidadPersonas, int cantidadMaletas) : Zonas(capacidad, cantidadPersonas, cantidadMaletas) {
    this->capacidad = capacidad;
    this->cantidadPersonas = cantidadPersonas;
    this->cantidadMaletas = cantidadMaletas;
}

// Métodos de acceso
int Retencion::getCapacidad() const {
    return this->capacidad;
}

int Retencion::getCantidadPersonas() const {
    return this->cantidadPersonas;
}

int Retencion::getCantidadMaletas() const {
    return this->cantidadMaletas;
}

