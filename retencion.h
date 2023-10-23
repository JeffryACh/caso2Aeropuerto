/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 08/10/2021 17:20
*/

#ifndef CASO2_ED_RETENCION_H
#define CASO2_ED_RETENCION_H

#endif //CASO2_ED_RETENCION_H
#ifndef RETENCION_H
#define RETENCION_H

#include "claseZona.h"
#include "claseMaletas.h"
#include "clasePasajero.h"

class Retencion : public Zonas {
private:
    std::vector<Maleta> maletas;
    std::vector<Pasajero> pasajeros;
public:
    /**
     * @brief Clase que representa la zona de retención de un aeropuerto.
     * 
     * Esta clase hereda de la clase Zonas y contiene vectores de maletas y pasajeros.
     * 
     * @param capacidad Capacidad de la zona de retención.
     * @param cantidadPersonas Cantidad de personas en la zona de retención.
     * @param cantidadMaletas Cantidad de maletas en la zona de retención.
     * @param maleta Objeto de la clase Maleta que se encuentra en la zona de retención.
     * @param pasajero Objeto de la clase Pasajero que se encuentra en la zona de retención.
     */
    Retencion(int capacidad, int cantidadPersonas, int cantidadMaletas, Maleta maleta, Pasajero pasajero);

    /**
     * @brief Método que manda a la cárcel a los pasajeros de la zona de retención.
     * 
     */
    void mandarALaCarcel();
};

#endif // RETENCION_H