//
// Created by aquir on 13/10/2023.
//

#include "claseRecepcionEquipaje.h"
#include <iostream>




void RecepcionEquipaje::agregarEquipaje(const Maleta& equipaje) {
    pilaEquipaje.push(equipaje);
}

void RecepcionEquipaje::retirarEquipaje() {
    if (!pilaEquipaje.empty()) {
        pilaEquipaje.pop();
        std::cout << "Equipaje retirado correctamente." << std::endl;
    } else {
        std::cout << "No hay equipaje disponible para retirar." << std::endl;
    }
}

bool RecepcionEquipaje::verificarDisponibilidad() const {
    return pilaEquipaje.empty();
}

int RecepcionEquipaje::obtenerCantidadEquipaje() const {
    return pilaEquipaje.size();
}

void RecepcionEquipaje::vaciarRecepcion() {
    while (!pilaEquipaje.empty()) {
        pilaEquipaje.pop();
    }
}

void RecepcionEquipaje::mostrarEquipaje() const {
    std::cout << "Equipaje en la recepción:" << std::endl;
    std::stack<Maleta> tempPila = pilaEquipaje; // Copia temporal de la pila

    while (!tempPila.empty()) {
        Maleta equipaje = tempPila.top();
        // Imprimir los detalles del equipaje, por ejemplo, utilizando los métodos de Maleta
        std::cout << "Peso: " << equipaje.getPeso() << " Descripción: " << equipaje.getDescripcion() << std::endl;
        tempPila.pop();
    }
}