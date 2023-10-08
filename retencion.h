//
// Created by aquir on 8/10/2023.
//

#ifndef CASO2_ED_RETENCION_H
#define CASO2_ED_RETENCION_H

#endif //CASO2_ED_RETENCION_H
#ifndef RETENCION_H
#define RETENCION_H

#include "claseZonas.h"
#include "claseMaletas.h"
#include "clasePasajeros.h"

class Retencion : public Zonas {
private:
    std::vector<Maleta> maletas;
    std::vector<Pasajero> pasajeros;

public:
    // Constructor
    Retencion(int capacidad, int cantidadPersonas, int cantidadMaletas, Maleta maleta, Pasajero pasajero);

    // Mandar a la carcel
    void mandarALaCarcel();
};

#endif // RETENCION_H