/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 13/10/2023 16:15
*/

#include "claseRecepcionEquipaje.h"
#include <iostream>




/**
 * @brief Agrega un equipaje a la pila de equipajes de la recepción.
 * 
 * @param equipaje Objeto de tipo Maleta que representa el equipaje a agregar.
 */
void RecepcionEquipaje::agregarEquipaje(const Maleta& equipaje) {
    pilaEquipaje.push(equipaje);
}

/**
 * @brief Método que permite retirar el equipaje de la pila de equipaje de la recepción.
 * 
 * Si la pila de equipaje no está vacía, se retira el equipaje de la cima de la pila y se muestra un mensaje de éxito.
 * En caso contrario, se muestra un mensaje indicando que no hay equipaje disponible para retirar.
 * 
 */
void RecepcionEquipaje::retirarEquipaje() {
    if (!pilaEquipaje.empty()) {
        pilaEquipaje.pop();
        std::cout << "Equipaje retirado correctamente." << std::endl;
    } else {
        std::cout << "No hay equipaje disponible para retirar." << std::endl;
    }
}

/**
 * @brief Verifica si la pila de equipaje está vacía.
 * 
 * @return true si la pila de equipaje está vacía, false de lo contrario.
 */
bool RecepcionEquipaje::verificarDisponibilidad() const {
    return pilaEquipaje.empty();
}

/**
 * @brief Obtiene la cantidad de equipaje en la pila de equipaje.
 * 
 * @return int Cantidad de equipaje en la pila de equipaje.
 */
int RecepcionEquipaje::obtenerCantidadEquipaje() const {
    return pilaEquipaje.size();
}

/**
 * @brief Vacía la recepción de equipaje.
 * 
 */
void RecepcionEquipaje::vaciarRecepcion() {
    while (!pilaEquipaje.empty()) {
        pilaEquipaje.pop();
    }
}

/**
 * Muestra los detalles de cada maleta en la pila de equipaje de la recepción.
 * Utiliza los métodos de la clase Maleta para obtener la descripción y peso de cada maleta.
 */
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