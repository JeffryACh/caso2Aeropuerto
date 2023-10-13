//
// Created by aquir on 13/10/2023.
//

#ifndef CASO2_ED_CLASERECEPCIONEQUIPAJE_H
#define CASO2_ED_CLASERECEPCIONEQUIPAJE_H


#include <iostream>
#include <stack>
#include "claseMaletas.h"
#include  ""
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
};



#endif //CASO2_ED_CLASERECEPCIONEQUIPAJE_H
