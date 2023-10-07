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
    Pasajero *pasajero;
    int capacidad;
    bool revisionPersona; // Indica si se ha realizado la revisión de la persona

public:
    // Constructor
    AduanaPersonas(int capacidad, bool revisionPersona, Pasajero pasajero, int cantidadPersonas, int cantidadMaletas) : Zonas(capacidad, cantidadPersonas, cantidadMaletas) {
        this->revisionPersona = revisionPersona;
        this->pasajero = new Pasajero(pasajero);
        this->revisionPersona = false;
    }

    // Métodos específicos de AduanaPersonas
    bool haSidoRevisada() {
        return revisionPersona;
    }

    bool realizarRevision(Pasajero pPasajero) {
        return validarCodigoPasaporte(pPasajero.getPasaporte().codigo, pPasajero.getNacionalidad(), pPasajero.getNombre(), pPasajero.getEdad());
    }
};

