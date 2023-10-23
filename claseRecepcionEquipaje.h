//
// Created by aquir on 13/10/2023.
//

#ifndef CASO2_ED_CLASERECEPCIONEQUIPAJE_H
#define CASO2_ED_CLASERECEPCIONEQUIPAJE_H


#include <iostream>
#include <stack>
#include "claseMaleta.h"
#include "AlmMaleta.h"
#include "clasePasajero.h"
#include "lobbyEspera.h"

class lobbyEspera;

class RecepcionEquipaje {
private:
    std::stack<Maleta> pilaEquipaje;

public:
    RecepcionEquipaje() {} // Constructor

    // Métodos
     //Declaración de la función que agrega una maleta a la pila de equipaje.
    void agregarEquipaje(const Maleta& equipaje);
    // Declaración de la función que retira una maleta de la pila de equipaje.
    void retirarEquipaje();
    //Declaración de la función que verifica si hay equipaje disponible en la recepción.
    bool verificarDisponibilidad() const;
    //Declaración de la  función que obtiene la cantidad de maletas en la recepción.
    int obtenerCantidadEquipaje() const;
    //Declaración de la función que vacía la recepción de equipaje.
    void vaciarRecepcion();
    //Declaración de la función que muestra el equipaje en la recepción.
    void mostrarEquipaje() const;
    //Declaración de la función que valida a quiénes pertenecen las maletas en la recepción.
    void validarDueñosDeMaletas(const std::vector<Pasajero>& pasajeros);
    // Declaración de la función que inicia el proceso de recepción de equipaje (no se muestra su implementación en este archivo de encabezado).
    void iniciarRecepcionEquipaje();
};



#endif //CASO2_ED_CLASERECEPCIONEQUIPAJE_H
