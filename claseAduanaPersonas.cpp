#include "claseAduanaPersonas.h"
#include "claseZonas.h"
#include "claseMaletas.h"
#include "clasePasajeros.h"
#include "validaciones.h"

// Métodos específicos de AduanaPersonas
bool AduanaPersonas::haSidoRevisada(Pasajero pasajero) {
    for (int i = 0; i < this->pasajeros.size(); i++) {
        if (this->pasajeros[i].getPasaporte().codigo == pasajero.getPasaporte().codigo) {
            return realizarRevision(pasajero);
        }
    }
    // Debes decidir qué hacer si el pasajero no se encuentra en la lista de pasajeros
    return false;
}

bool AduanaPersonas::realizarRevision(Pasajero pPasajero) {
    return validarCodigoPasaporte(pPasajero.getPasaporte().codigo, pPasajero.getNacionalidad(), pPasajero.getNombre(), pPasajero.getEdad());
}