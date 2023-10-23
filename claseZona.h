/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 08/10/2021 17:20
*/

#ifndef CASO2_ED_CLASEZONAS_H
#define CASO2_ED_CLASEZONAS_H

#endif //CASO2_ED_CLASEZONAS_H
#ifndef ZONAS_H
#define ZONAS_H

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Clase que representa una zona en un aeropuerto.
 * 
 */

class Zonas {
private:
    int capacidad; /**< Capacidad de la zona. */
    int cantidadPersonas; /**< Cantidad de personas en la zona. */
    int cantidadMaletas; /**< Cantidad de maletas en la zona. */

public:
    /**
     * @brief Constructor de la clase Zonas.
     * 
     * @param capacidad Capacidad de la zona.
     * @param cantidadPersonas Cantidad de personas en la zona.
     * @param cantidadMaletas Cantidad de maletas en la zona.
     */
    Zonas(int capacidad, int cantidadPersonas, int cantidadMaletas);

    /**
     * @brief Obtiene la capacidad de la zona.
     * 
     * @return int Capacidad de la zona.
     */
    int getCapacidad() const;

    /**
     * @brief Obtiene la cantidad de personas en la zona.
     * 
     * @return int Cantidad de personas en la zona.
     */
    int getCantidadPersonas() const;

    /**
     * @brief Obtiene la cantidad de maletas en la zona.
     * 
     * @return int Cantidad de maletas en la zona.
     */
    int getCantidadMaletas() const;

    /**
     * @brief Establece una nueva cantidad de personas en la zona.
     * 
     * @param nuevaCantidad Nueva cantidad de personas en la zona.
     */
    void setCantidadPersonas(int nuevaCantidad);
};

#endif // ZONAS_H