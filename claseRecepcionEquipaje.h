//
// Created by aquir on 13/10/2023.
//

#ifndef CASO2_ED_CLASERECEPCIONEQUIPAJE_H
#define CASO2_ED_CLASERECEPCIONEQUIPAJE_H


#include <iostream>
#include <stack>
#include "claseMaletas.h"
#include "AlmMaleta.h"
#include "clasePasajeros.h"
#include "lobbyEspera.h"

class lobbyEspera;

class RecepcionEquipaje {
private:
    std::stack<Maleta> pilaEquipaje;

public:
    RecepcionEquipaje() {} // Constructor

    // Métodos

    void agregarEquipaje(const Maleta& equipaje);
    void retirarEquipaje();
    bool verificarDisponibilidad() const;
    int obtenerCantidadEquipaje() const;
    void vaciarRecepcion();
    void mostrarEquipaje() const;
    void validarDueñosDeMaletas(const std::vector<Pasajero>& pasajeros);

};



#endif //CASO2_ED_CLASERECEPCIONEQUIPAJE_H
