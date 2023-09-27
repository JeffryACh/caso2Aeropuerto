/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 
*/

#include <iostream>
#include <string>
#include <vector>
#include "claseZonas.cpp"

using namespace std;

class Retencion : public Zonas{
    // Atributos
    private:
        int capacidad;
        int cantidadPersonas;
        int cantidadMaletas;


    // Constructor
    public:
        /*
        Constructor de la clase Zonas
        Parametros:
            - capacidad: int que representa la capacidad de la zona
            - cantidadPersonas: int que representa la cantidad de personas en la zona
        Retorno: void
        */

        Retencion(int capacidad, int cantidadPersonas, int cantidadMaletas) : Zonas(capacidad, cantidadPersonas, cantidadMaletas){
            this->capacidad = capacidad;
            this->cantidadPersonas = cantidadPersonas;
            this->cantidadMaletas = cantidadMaletas;
        }

        /*
        Funcion que retorna la capacidad de la zona
        Parametros: void
        Retorno: int
        */
        int getCapacidad(){
            return this->capacidad;
        }

        /*
        Funcion que retorna la cantidad de personas en la zona
        Parametros: void
        Retorno: int
        */
        int getCantidadPersonas(){
            return this->cantidadPersonas;
        }

        /*
        Funccion que retorna la cantidad de maletas en la zona
        Parametros: void
        Retorno: int
        */
        int getCantidadMaletas(){
            return this->cantidadMaletas;
        }

        // volid mandarALaCarcel()
};