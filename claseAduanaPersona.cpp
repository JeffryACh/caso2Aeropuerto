/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 08/10/2021 17:20
*/

#include "claseAduanaPersona.h"
#include "claseZona.h"
#include "claseMaleta.h"
#include "clasePasajero.h"
#include "validacion.h"

/**
 * Verifica si un pasajero ha sido revisado previamente y realiza una revisión si no ha sido revisado.
 * @param pasajero El pasajero a revisar.
 * @return Verdadero si el pasajero ha sido revisado previamente o si se realiza una revisión, falso en caso contrario.
 */
bool AduanaPersonas::haSidoRevisada(Pasajero pasajero) {

    for (int i = 0; i < this->pasajeros.size(); i++) {
        if (this->pasajeros[i].getPasaporte().codigo == pasajero.getPasaporte().codigo) {
            return realizarRevision(pasajero);
        }
    }
    
    return false;
}

/**
 * @brief Realiza la revisión de un pasajero en la aduana de personas.
 * 
 * @param pPasajero Pasajero a revisar.
 * @return true si el código de pasaporte es válido, false en caso contrario.
 */
bool AduanaPersonas::realizarRevision(Pasajero pPasajero) {
    return validarCodigoPasaporte(pPasajero.getPasaporte().codigo, pPasajero.getNacionalidad(), pPasajero.getNombre(), pPasajero.getEdad());
}