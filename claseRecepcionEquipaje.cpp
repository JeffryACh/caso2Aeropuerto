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
void RecepcionEquipaje::validarDueñosDeMaletas(const std::vector<Pasajero>& pasajeros) {
    std::stack<Maleta> tempPila = pilaEquipaje;
    bool seEncontroAlMenosUnaMaleta = false;

    while (!tempPila.empty()) {
        Maleta maleta = tempPila.top();
        tempPila.pop();
        std::string propietarioMaleta = maleta.getPropietario();
        seEncontroAlMenosUnaMaleta = false;

        for (Pasajero pasajero : pasajeros) {
            if (pasajero.getNombre() == propietarioMaleta) {
                seEncontroAlMenosUnaMaleta = true;

                std::cout << "La maleta pertenece al pasajero: " << pasajero.getNombre() << std::endl;
                break;
            }
        }

        if (!seEncontroAlMenosUnaMaleta) {
            std::cout << "No se encontró al dueño de la maleta." << std::endl;
            // Aquí puedes realizar alguna acción si no se encuentra el dueño.
        }
    }
}
void RecepcionEquipaje::iniciarRecepcionEquipaje() {
    while (true) {
        // Suponemos que hay una cola de maletas en algún lugar que se procesa
        // en la recepción de equipaje. Vamos a verificar si hay maletas en la cola.

        if (!colaMaletas.empty()) {
            // Si hay maletas en la cola, la sacamos para procesarla.
            Maleta maleta = colaMaletas.front();
            colaMaletas.pop();

            // Verificar el contenido de la maleta
            std::vector<std::string> contenidoMaleta = maleta.getContenidoVector();

            // Realizar verificaciones, notificaciones, almacenamiento, etc.
            bool contenidoValido = va(contenidoMaleta);

            if (contenidoValido) {
                // Si el contenido es válido, se almacena la maleta
                almacenarMaleta(maleta);
            } else {
                // Si el contenido no es válido, tomar acciones específicas.
                tomarAccionesPorContenidoInvalido(maleta);
            }

            // Continuar con el procesamiento de otras maletas, si las hay.
        }

        // Realiza más trabajo relacionado con la recepción de equipaje aquí.
    }
}
