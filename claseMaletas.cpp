/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 10/09/2021 15:35
*/

#include <iostream>
#include <string>

using namespace std;

// Clase Maleta
class Maleta {
    // Atributos
    private:
        int peso;
        std::string descripcion;
        std::string propietario;
        string contenido[5];

    // Constructor
    public:
        /*
        Constructor de la clase Maleta
        Parametros:
            - peso: int que representa el peso de la maleta
            - descripcion: string que representa la descripcion de la maleta
            - propietario: string que representa el propietario de la maleta
            - contenido: vector de strings que representa el contenido de la maleta
        Retorno: void
        */
        Maleta(int peso, std::string descripcion, std::string propietario, string contenido){
            this->peso = peso;
            this->descripcion = descripcion;
            this->propietario = propietario;
            this->contenido[5] = contenido;

        }

        /*
        Funcion que retorna el peso de la maleta
        Parametros: void
        Retorno: int
        */
        int getPeso(){
            return this->peso;
        }

        /*
        Funcion que retorna la descripcion de la maleta
        Parametros: void
        Retorno: string
        */
        std::string getDescripcion(){
            return this->descripcion;
        }

        /*
        Funcion que retorna el propietario de la maleta
        Parametros: void
        Retorno: string
        */
        std::string getPropietario(){
            return this->propietario;
        }

        /*
        Funcion que retorna el contenido de la maleta
        Parametros: void
        Retorno: vector de strings
        */
        string getContenidoBonito(){
            string contenido = "";
            for (int i = 0; i < 5; i++){
                contenido += this->contenido[i];
                contenido += ", ";
            }
            return contenido;
        }

        /*
        Funcion que saca el contenido de la maleta
        Parametros: void 
        Retorno: array de strings
        */
        string getContenido(){
            return this->contenido[5];
        }
};