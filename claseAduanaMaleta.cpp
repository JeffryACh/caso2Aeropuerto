/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 08/10/2021 17:20
*/

#include "claseZonas.h"
#include "claseMaletas.h"
#include "AlmMaleta.h"
#include "claseAduanaMaleta.h"
#include "validaciones.h"

/**
 * Constructor de la clase AduanaMaleta.
 * @param almacenarMaletas Objeto de la clase AlmacenarMaletas.
 * @param capacidad Capacidad de la aduana.
 * @param cantidadPersonas Cantidad de personas en la aduana.
 * @param cantidadMaletas Cantidad de maletas en la aduana.
 * @param maletas Arreglo de objetos de la clase Maleta.
 * @param cantidadMaletasRevisadas Cantidad de maletas revisadas.
 * @param contenidoMaleta Arreglo de strings con el contenido de las maletas.
 * @param almacenarMaletas1 Objeto de la clase AlmacenarMaletas.
 */
AduanaMaleta::AduanaMaleta(AlmacenarMaletas &almacenarMaletas, int capacidad, int cantidadPersonas, int cantidadMaletas,
                           Maleta maletas[], int cantidadMaletasRevisadas, std::string contenidoMaleta[],
                           AlmacenarMaletas &almacenarMaletas1) : almacenarMaletas(almacenarMaletas1) {
    for (int i = 0; i < 5; i++) {
        this->contenidoMaletas[i] = contenidoMaleta[i];
    }
}

/**
 * @brief Retorna el contenido de la maleta.
 * 
 * @return std::string* Puntero al contenido de la maleta.
 */
std::string* AduanaMaleta::getContenidoMaleta() {
    return this->contenidoMaletas;
}

/**
 * @brief Asigna el contenido de la maleta a un arreglo de strings.
 * 
 * @param contenidoMaleta Arreglo de strings con el contenido de la maleta.
 */
void AduanaMaleta::setContenidoMaleta(std::string contenidoMaleta[]) {
    for (int i = 0; i < 5; i++) {
        this->contenidoMaletas[i] = contenidoMaleta[i];
    }
}

/**
 * @brief Revisa el contenido de una maleta para determinar si cumple con las regulaciones de la aduana.
 * 
 * @param contenidoMaleta Un arreglo de strings que representa el contenido de la maleta.
 * @return true si el contenido de la maleta cumple con las regulaciones de la aduana, false en caso contrario.
 */
bool AduanaMaleta::revisarMaleta(std::string contenidoMaleta[5]) {
    return validarContenidoMaleta(contenidoMaleta);
}

/**
 * @brief Función que actualiza la cantidad de maletas revisadas en la aduana.
 * 
 * @param nuevaCantidad Nueva cantidad de maletas revisadas.
 */
void AduanaMaleta::setCantidadMaletasRevisadas(int nuevaCantidad) {
    this->cantMaletasRevisadas = nuevaCantidad;
}

/**
 * @brief Retorna una cadena de caracteres con el contenido de las maletas de la aduana de manera legible.
 * 
 * @return std::string Cadena de caracteres con el contenido de las maletas de la aduana.
 */
std::string AduanaMaleta::getContenidoBonito() {
    std::string contenidoStr = "";
    for (int i = 0; i < 5; i++) {
        contenidoStr += this->contenidoMaletas[i];
        contenidoStr += ", ";
    }
    return contenidoStr;
}