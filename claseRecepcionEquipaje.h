/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 13/10/2023 16:15
*/

#ifndef CASO2_ED_CLASERECEPCIONEQUIPAJE_H
#define CASO2_ED_CLASERECEPCIONEQUIPAJE_H


#include <iostream>
#include <stack>
#include "claseMaletas.h"

/**
    * @brief Clase que representa la recepción de equipaje en un aeropuerto.
    * 
    */
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
