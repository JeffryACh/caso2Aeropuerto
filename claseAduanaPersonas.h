//
// Created by aquir on 8/10/2023.
//

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

class AduanaPersonas : public Zonas{
    // Atributos específicos de AduanaPersonas
private:
    int cantidadPersonasRevisadas;
    vector<Pasajero> pasajeros;
    int capacidad;

public:
    // Constructor
    AduanaPersonas(int capacidad, bool revisionPersona, Pasajero pasajero, int cantidadPersonas, int cantidadMaletas) : Zonas(capacidad, cantidadPersonas, cantidadMaletas) {
        this->pasajeros.push_back(pasajero);
    }

    // Métodos específicos de AduanaPersonas
    bool haSidoRevisada(Pasajero pasajero);

    bool realizarRevision(Pasajero pPasajero);


};
#endif //CASO2_ED_CLASEADUANAPERSONAS_H
