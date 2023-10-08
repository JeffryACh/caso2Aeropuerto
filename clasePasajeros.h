//
// Created by aquir on 8/10/2023.
//

#ifndef CASO2_ED_CLASEPASAJEROS_H
#define CASO2_ED_CLASEPASAJEROS_H

#endif //CASO2_ED_CLASEPASAJEROS_H
#ifndef PASAJERO_H
#define PASAJERO_H
#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include "claseMaletas.h"

// Struct pasaporte
struct Pasaporte {
    std::string codigo;
    std::string nacionalidad;
    std::string sexo;
};

// Clase Pasajero
class Pasajero {
private:
    std::string nombre;
    int edad;
    Pasaporte pasaporte;
    std::string nacionalidad;
    std::string sexo;
    Maleta* maleta;

public:
    Pasajero(std::string nombre, int edad, Pasaporte pasaporte, std::string nacionalidad, std::string sexo, Maleta maleta);

    void mostrarDatos();

    std::string getNombre();
    int getEdad();
    Pasaporte getPasaporte();
    std::string getNacionalidad();
    std::string getSexo();
    Maleta getMaleta();
    std::string getContenidoMaleta();
};

#endif // PASAJERO_H