/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 08/10/2021 17:20
*/

#ifndef CASO2_ED_CLASEADUANAPERSONAS_H
#define CASO2_ED_CLASEADUANAPERSONAS_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "claseZonas.h"
#include "claseMaletas.h"
#include "validaciones.h"
#include "clasePasajeros.h"

using namespace std;

/**
 * @file claseAduanaPersonas.h
 * @brief Definición de la clase AduanaPersonas, que hereda de la clase Zonas y representa una zona de aduana para personas en un aeropuerto.
 * 
 */
class AduanaPersonas : public Zonas{
    // Atributos específicos de AduanaPersonas
private:
    int cantidadPersonasRevisadas; /**< Cantidad de personas que han sido revisadas en la aduana de personas. */
    vector<Pasajero> pasajeros; /**< Vector de pasajeros que se encuentran en la aduana de personas. */
    int capacidad; /**< Capacidad máxima de la aduana de personas. */

public:
    /**
     * @brief Constructor de la clase AduanaPersonas.
     * 
     * @param capacidad Capacidad máxima de la aduana de personas.
     * @param revisionPersona Indica si se realiza revisión de personas en la aduana.
     * @param pasajero Primer pasajero que se encuentra en la aduana.
     * @param cantidadPersonas Cantidad de personas que se encuentran en la aduana.
     * @param cantidadMaletas Cantidad de maletas que se encuentran en la aduana.
     */
    AduanaPersonas(int capacidad, bool revisionPersona, Pasajero pasajero, int cantidadPersonas, int cantidadMaletas) : Zonas(capacidad, cantidadPersonas, cantidadMaletas) {
        this->pasajeros.push_back(pasajero);
    }

    /**
     * @brief Verifica si un pasajero ha sido revisado en la aduana de personas.
     * 
     * @param pasajero Pasajero a verificar.
     * @return true Si el pasajero ha sido revisado.
     * @return false Si el pasajero no ha sido revisado.
     */
    bool haSidoRevisada(Pasajero pasajero);

    /**
     * @brief Realiza la revisión de un pasajero en la aduana de personas.
     * 
     * @param pPasajero Pasajero a revisar.
     * @return true Si la revisión fue exitosa.
     * @return false Si la revisión no fue exitosa.
     */
    bool realizarRevision(Pasajero pPasajero);
};
#endif //CASO2_ED_CLASEADUANAPERSONAS_H
