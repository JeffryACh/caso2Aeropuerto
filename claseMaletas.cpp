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

// Clase Maleta
class Maleta {
    // Atributos
    private:
        int peso;
        string descripcion;
        string propietario;
        vector<string> contenido;

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
        Maleta(int peso, string descripcion, string propietario, vector<string> contenido){
            this->peso = peso;
            this->descripcion = descripcion;
            this->propietario = propietario;
            this->contenido = contenido;
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
        string getDescripcion(){
            return this->descripcion;
        }

        /*
        Funcion que retorna el propietario de la maleta
        Parametros: void
        Retorno: string
        */
        string getPropietario(){
            return this->propietario;
        }

        /*
        Funcion que saca el contenido de la maleta
        Parametros: void 
        Retorno: string
        */
        string getContenido(){
            string contenido_str;
            for (const auto& elem : this->contenido) {
                contenido_str += elem + ", ";
            }
            return contenido_str;
        }
};