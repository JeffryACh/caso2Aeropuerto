#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "claseZonas.cpp"
#include "claseMaletas.cpp"
#include "validaciones.cpp"
#include "clasePasajeros.cpp"

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
    bool haSidoRevisada(Pasajero pasajero) {
        for (int i = 0; i < this->pasajeros.size(); i++) {
            if (this->pasajeros[i].getPasaporte().codigo == pasajero.getPasaporte().codigo) {
                return realizarRevision(pasajero);
            }
        }
    }

    bool realizarRevision(Pasajero pPasajero) {
        return validarCodigoPasaporte(pPasajero.getPasaporte().codigo, pPasajero.getNacionalidad(), pPasajero.getNombre(), pPasajero.getEdad());
    }


};

