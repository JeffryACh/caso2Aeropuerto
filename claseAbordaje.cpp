//
// Created by aquir on 15/10/2023.
//

#include "claseAbordaje.h"
#include "claseRecepcionEquipaje.h"


void AbordajeAvion::AgregarPasajero(std::string& nombre) {
    colaPasajeros.push_back(nombre);

}

void AbordajeAvion::RetirarPasajero() {
    if (!colaPasajeros.empty()) {
        colaPasajeros.erase(colaPasajeros.begin()); // Elimina el primer elemento (el pasajero más antiguo)
    }

}
bool AbordajeAvion::verificarSeguridad() {
    // Implementa la lógica para verificar la seguridad del avión
    bool sistemasEnFuncionamiento = true;  // Variable para verificar si los sistemas críticos están en funcionamiento
    bool tripulaciónPreparada = true;      // Variable para verificar si la tripulación está preparada
    bool procedimientosSeguridadCumplidos = true;  // Variable para verificar si se cumplieron los procedimientos de seguridad
    bool hayCombustible=true;


    // Si todos los aspectos de seguridad están en orden, el avión es seguro para despegar.
    if (sistemasEnFuncionamiento && tripulaciónPreparada && procedimientosSeguridadCumplidos && hayCombustible) {
        return true;
    } else {
        // Si no se cumplen todos los aspectos de seguridad, el avión no es seguro para despegar.
        return false;
    }

}
bool AbordajeAvion::Despegar() {
    // Verificar si se cumplen todas las condiciones de seguridad para despegar
    if (CantidadPasajeros() > 0) {
        // Si se cumplen todas las condiciones, el avión puede despegar
        std::cout << "El avión está despegando..." << std::endl;
        return true;
    } else {
        // Si no se cumplen todas las condiciones, el avión no puede despegar
        std::cout << "No se pueden cumplir las condiciones para despegar." << std::endl;
        return false;
    }
}


int AbordajeAvion::CantidadPasajeros() {
    return colaPasajeros.size();

}