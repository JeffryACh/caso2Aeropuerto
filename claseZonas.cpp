/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 10/09/2021 15:35
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Zonas{
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
        Zonas(int capacidad, int cantidadPersonas, int cantidadMaletas){
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

        /*
        Funcion que cambia la cantidad de personas en la zona
        Parametros: int nuevaCantidad
        Retorno: void
        */
        void setCantidadPersonas(int nuevaCantidad){
            this->cantidadPersonas = nuevaCantidad;
        }
};

