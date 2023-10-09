/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 08/10/2021 17:20
*/

#include "claseZonas.h"


/**
 * @brief Constructor de la clase Zonas
 * 
 * @param capacidad Capacidad máxima de personas en la zona
 * @param cantidadPersonas Cantidad actual de personas en la zona
 * @param cantidadMaletas Cantidad actual de maletas en la zona
 */
Zonas::Zonas(int capacidad, int cantidadPersonas, int cantidadMaletas) {
    this->capacidad = capacidad;
    this->cantidadPersonas = cantidadPersonas;
    this->cantidadMaletas = cantidadMaletas;
}

/**
 * @brief Retorna la capacidad de la zona.
 * 
 * @return int Capacidad de la zona.
 */
int Zonas::getCapacidad() const {
    return this->capacidad;
}

/**
 * @brief Retorna la cantidad de personas en la zona.
 * 
 * @return int Cantidad de personas en la zona.
 */
int Zonas::getCantidadPersonas() const {
    return this->cantidadPersonas;
}

/**
 * @brief Retorna la cantidad de maletas en la zona.
 * 
 * @return int Cantidad de maletas en la zona.
 */
int Zonas::getCantidadMaletas() const {
    return this->cantidadMaletas;
}

/**
 * @brief Cambia la cantidad de personas en la zona.
 * 
 * @param nuevaCantidad Nueva cantidad de personas en la zona.
 */
void Zonas::setCantidadPersonas(int nuevaCantidad) {
    this->cantidadPersonas = nuevaCantidad;
}