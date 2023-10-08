/*

*/

#include "Retencion.h"
#include <iostream>

void Retencion::mandarALaCarcel() {
    for (int i = 0; i < this->pasajeros.size(); i++) {
        std::cout << "Mandando a la cárcel a " << this->pasajeros[i].getNombre() << std::endl;
        pasajeros.erase(pasajeros.begin() + i);
        maletas.erase(maletas.begin() + i);
    }
}