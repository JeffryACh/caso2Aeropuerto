/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 08/10/2021 17:20
*/

#include <iostream>
#include <string>
#include "validaciones.h"
using namespace std;


/**
 * @brief Valida el código de un pasaporte según ciertas reglas.
 * 
 * @param pCodigo Código del pasaporte a validar.
 * @param pPais Código del país del pasaporte.
 * @param pNombre Código del nombre del pasaporte.
 * @param pEdad Edad del titular del pasaporte.
 * @return true si el código del pasaporte es válido, false en caso contrario.
 */

bool validarCodigoPasaporte(std::string pCodigo, std::string pPais, std::string pNombre, int pEdad){
    if(pCodigo.length() != 11){
        return false;
    }

    if(pCodigo.substr(0,3) != pPais){
        return false;
    }

    if(pCodigo.substr(3,3) != pNombre){
        return false;
    }

    if(pCodigo.substr(6,2) != to_string(pEdad)){
        return false;
    }
    
    for (int i = 8; i < 14; i++){ //verifica que los ultimos 6 caracteres sean numeros
        if (!isdigit(pCodigo[i])){
            return false;
        }
    }

    return true;
}


/**
 * @brief Valida el contenido de una maleta para asegurarse de que no contenga elementos peligrosos.
 * 
 * @param pContenido Arreglo de strings que contiene el contenido de la maleta.
 * @return true si el contenido de la maleta es seguro, false si contiene elementos peligrosos.
 */
bool validarContenidoMaleta(std::string pContenido[]){
    for (int i = 0; i < 5; i++){
        if(pContenido[i] == "Pistola" || pContenido[i] == "Cuchillo" || pContenido[i] == "Explosivos" || pContenido[i] == "Quimicos peligrosos" || pContenido[i] == "Drogas"){
            return false;
        }
    }
    return true;
}

/**
 * @brief Valida si una maleta pertenece a un pasajero en específico.
 * 
 * @param pMaleta La maleta a validar.
 * @param pPasajero El pasajero a comparar con el propietario de la maleta.
 * @return true si la maleta pertenece al pasajero, false en caso contrario.
 */
bool validarMaleta(Maleta pMaleta, Pasajero pPasajero){
    return pMaleta.getPropietario() == pPasajero.getNombre();
}