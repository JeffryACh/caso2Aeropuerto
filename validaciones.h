/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 08/10/2021 17:20
*/

#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <string>
#include "clasePasajeros.h"
#include "claseMaletas.h"

/**
 * @brief Valida el código de pasaporte de un pasajero.
 * 
 * @param pCodigo Código de pasaporte del pasajero.
 * @param pPais País de origen del pasajero.
 * @param pNombre Nombre completo del pasajero.
 * @param pEdad Edad del pasajero.
 * @return true si el código de pasaporte es válido, false en caso contrario.
 */
bool validarCodigoPasaporte(std::string pCodigo, std::string pPais, std::string pNombre, int pEdad);

/**
 * @brief Valida el contenido de una maleta para asegurarse de que no contenga elementos peligrosos.
 * 
 * @param pContenido Arreglo de strings que contiene el contenido de la maleta.
 * @return true si el contenido de la maleta es seguro, false si contiene elementos peligrosos.
 */
bool validarContenidoMaleta(std::string pContenido[]);

/**
 * @brief Valida el contenido de una maleta para asegurarse de que no contenga elementos peligrosos.
 * 
 * @param pMaleta Maleta a validar.
 * @param pPasajero Pasajero dueño de la maleta.
 * @return true si el contenido de la maleta es seguro, false si contiene elementos peligrosos.
 */
bool validarMaleta(Maleta pMaleta, Pasajero pPasajero);

#endif // VALIDACIONES_H
