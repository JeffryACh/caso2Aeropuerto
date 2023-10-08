//
// Created by aquir on 8/10/2023.
//

#ifndef CASO2_ED_CLASEZONAS_H
#define CASO2_ED_CLASEZONAS_H

#endif //CASO2_ED_CLASEZONAS_H
#ifndef ZONAS_H
#define ZONAS_H



#include <iostream>
#include <string>
#include <vector>

class Zonas {
private:
    int capacidad;
    int cantidadPersonas;
    int cantidadMaletas;

public:
    // Constructor
    Zonas(int capacidad, int cantidadPersonas, int cantidadMaletas);

    // Métodos de acceso
    int getCapacidad() const;
    int getCantidadPersonas() const;
    int getCantidadMaletas() const;
    void setCantidadPersonas(int nuevaCantidad);
};

#endif // ZONAS_H