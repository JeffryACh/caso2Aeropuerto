/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 08/10/2021 17:20
*/

#include "Retencion.h"
#include <iostream>


/**
 * @brief Función que manda a la cárcel a todos los pasajeros retenidos.
 * 
 * @details Recorre el vector de pasajeros retenidos y los elimina del vector de pasajeros y maletas.
 * 
 */

void Retencion::mandarALaCarcel() {
    for (int i = 0; i < this->pasajeros.size(); i++) {
        std::cout << "Mandando a la cárcel a " << this->pasajeros[i].getNombre() << std::endl;
        pasajeros.erase(pasajeros.begin() + i);
        maletas.erase(maletas.begin() + i);
    }
}