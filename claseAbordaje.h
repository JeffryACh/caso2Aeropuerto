//
// Created by aquir on 15/10/2023.
//

#ifndef CASO2_ED_CLASEABORDAJE_H
#define CASO2_ED_CLASEABORDAJE_H


#include <string>
#include <vector>
#include "claseRecepcionEquipaje.h"
using namespace  std;
class AbordajeAvion {
private:
    RecepcionEquipaje recepcionEquipaje;
    std::vector<std::string> colaPasajeros;
public:
    AbordajeAvion();

    void AgregarPasajero(std::string& nombre);
    void RetirarPasajero();
    bool  Despegar();
    int  CantidadPasajeros();
    bool verificarSeguridad();

};


#endif //CASO2_ED_CLASEABORDAJE_H
