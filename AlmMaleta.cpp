//
// Created by aquir on 30/9/2023.
//
#include "AlmMaleta.h"
#include <iostream>

// Constructor de la clase Maletas que recibe una identificación de maleta
Maletas::Maletas(std::string& identificacionMaleta) {
    this->idMaleta = identificacionMaleta;
}

// Función para obtener la identificación de la maleta
std::string Maletas::getIdent() {
    return idMaleta;
}

// Este método se encarga de agregar una maleta al almacenamiento.
void AlmacenarMaletas::agregarMaleta(Maletas id) {
    Maletas maletas(id); // Instancia de maletas
    pilaMaletas.push(maletas); // Se agrega la maleta a la pila
}

// Este método se encarga de retirar una maleta del almacenamiento
void AlmacenarMaletas::retirarMaleta() {
    if (!pilaMaletas.empty()) {
        std::cout << "Retirando maleta con ID: " << pilaMaletas.top().getIdent() << std::endl;
        pilaMaletas.pop(); // Se saca la maleta de la pila
    } else {
        std::cout << "No hay maletas en el almacenamiento." << std::endl;
    }
}

// Este método se encarga de mostrar la cantidad de maletas en el almacenamiento
void AlmacenarMaletas::mostrarCantidadMaletas() const {
    std::cout << "Cantidad de maletas en el almacenamiento: " << pilaMaletas.size() << std::endl;
}


