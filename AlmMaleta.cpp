/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 08/10/2021 17:20
*/

#include "AlmMaleta.h"
#include <iostream>
Maletas::Maletas(char identificacionMaleta) {
    // Inicializa idMaleta con la identificación de la maleta proporcionada
    idMaleta = identificacionMaleta;  // Suponiendo que Maleta tiene un método para obtener su identificación
}

/**
 * @brief Constructor de la clase Maletas
 *
 * @param identificacionMaleta Identificación de la maleta
 */


/**
 * @brief Retorna la identificación de la maleta.
 *
 * @return Una cadena que representa la identificación de la maleta.
 */
std::string Maletas::getIdent() {
    return idMaleta;
}

/**
 * @brief Este método se encarga de agregar una maleta al almacenamiento.
 *
 * @param id Identificación de la maleta a agregar.
 */
void AlmacenarMaletas::agregarMaleta(Maletas id) {
    Maletas maletas(id); // Instancia de maletas
    pilaMaletas.push(maletas); // Se agrega la maleta a la pila
}

/**
 * @brief Este método se encarga de retirar una maleta del almacenamiento.
 *
 * Si no hay maletas en el almacenamiento, se muestra un mensaje indicando que no hay maletas.
 */
void AlmacenarMaletas::retirarMaleta() {
    if (!pilaMaletas.empty()) {
        std::cout << "Retirando maleta con ID: " << pilaMaletas.top().getIdent() << std::endl;
        pilaMaletas.pop(); // Se saca la maleta de la pila
    } else {
        std::cout << "No hay maletas en el almacenamiento." << std::endl;
    }
}

/**
 * @brief Este método se encarga de mostrar la cantidad de maletas en el almacenamiento.
 */
void AlmacenarMaletas::mostrarCantidadMaletas() const {
    std::cout << "Cantidad de maletas en el almacenamiento: " << pilaMaletas.size() << std::endl;
}
void almacenarMaletasThread(AlmacenarMaletas& almacenMaletas) {
    // Coloca aquí la lógica para almacenar maletas en el objeto almacenMaletas
    for (int i = 1; i <= 10; i++) {
        // Simular el almacenamiento de una maleta por segundo
        std::this_thread::sleep_for(std::chrono::seconds(1));
        Maletas maleta(i);  // Supongamos que el constructor de Maletas recibe un número de identificación
        almacenMaletas.agregarMaleta(maleta);
        std::cout << "Maleta " << i << " almacenada." << std::endl;


    }
}