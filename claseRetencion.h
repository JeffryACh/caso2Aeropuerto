/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 08/10/2021 17:20
*/

#include "claseZonas.h"

/**
 * @file claseRetencion.h
 * @brief Definición de la clase Retencion, que hereda de la clase Zonas.
 * 
 * Esta clase representa una zona de retención en un aeropuerto, con una capacidad determinada
 * para personas y maletas.
 */
class Retencion : public Zonas {
private:
    int capacidad; ///< Capacidad de la zona de retención.
    int cantidadPersonas; ///< Cantidad de personas actualmente en la zona de retención.
    int cantidadMaletas; ///< Cantidad de maletas actualmente en la zona de retención.

public:
    /**
     * @brief Constructor de la clase Retencion.
     * 
     * @param capacidad Capacidad de la zona de retención.
     * @param cantidadPersonas Cantidad de personas actualmente en la zona de retención.
     * @param cantidadMaletas Cantidad de maletas actualmente en la zona de retención.
     */
    Retencion(int capacidad, int cantidadPersonas, int cantidadMaletas);

    /**
     * @brief Método para obtener la capacidad de la zona de retención.
     * 
     * @return Capacidad de la zona de retención.
     */

    int getCapacidad() const;

    /**
     * @brief Método para obtener la cantidad de personas actualmente en la zona de retención.
     * 
     * @return Cantidad de personas actualmente en la zona de retención.
     */
    int getCantidadPersonas() const;

    /**
     * @brief Método para obtener la cantidad de maletas actualmente en la zona de retención.
     * 
     * @return Cantidad de maletas actualmente en la zona de retención.
     */
    int getCantidadMaletas() const;
};