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
    // Este metodo se encarga de agregar un pasajero a la cola
    void AgregarPasajero(std::string& nombre);
    //  Este metodo se encarga de retirar un pasajero de la cola
    void RetirarPasajero();
    //  Este metodo se encarga de realizar el despegue del avión
    bool  Despegar();
    //  Este metodo se encarga de obtener la cantidad de pasajeros en la cola
    int  CantidadPasajeros();
    //  Este metodo se encarga de verificar la seguridad antes del despegue

    bool verificarSeguridad();

};


#endif //CASO2_ED_CLASEABORDAJE_H
