/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 08/10/2021 17:20
*/

#include "claseRetencion.h"
#include "claseZonas.h"


/**
 * Constructor de la clase Retencion.
 * @param capacidad Capacidad de la zona de retención.
 * @param cantidadPersonas Cantidad de personas en la zona de retención.
 * @param cantidadMaletas Cantidad de maletas en la zona de retención.
 */
Retencion::Retencion(int capacidad, int cantidadPersonas, int cantidadMaletas) : Zonas(capacidad, cantidadPersonas, cantidadMaletas) {
    this->capacidad = capacidad;
    this->cantidadPersonas = cantidadPersonas;
    this->cantidadMaletas = cantidadMaletas;
}


/**
 * @brief Retorna la capacidad de la retención.
 * 
 * @return int Capacidad de la retención.
 */
int Retencion::getCapacidad() const {
    return this->capacidad;
}

/**
 * @brief Retorna la cantidad de personas en la retención.
 * 
 * @return int Cantidad de personas en la retención.
 */
int Retencion::getCantidadPersonas() const {
    return this->cantidadPersonas;
}

/**
 * @brief Retorna la cantidad de maletas en la retención.
 * 
 * @return int Cantidad de maletas en la retención.
 */
int Retencion::getCantidadMaletas() const {
    return this->cantidadMaletas;
}

