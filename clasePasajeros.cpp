/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 10/09/2021 15:35
*/

#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include "claseMaletas.cpp"

using namespace std;

// Struct pasaporte
struct Pasaporte{
    string codigo; //tiene que ser unico y iniciar con las primeras 3 letras del pais y luego 3 letras del nombre y luego la edad del pasajero y por ultimo 6 numeros aleatorios
    string nacionalidad; 
    string sexo;
};

// Clase Pasajero
class Pasajero{
    // Atributos
    private:
        string nombre; //nombre del pasajero solo el primer nombre
        int edad;
        Pasaporte pasaporte; //viene de la estructura pasaporte de arriba
        string nacionalidad;
        string sexo;
        Maleta *maleta;

    
    // Constructor
    public:
        /*
        Constructor de la clase Pasajero
        Parametros:
            - nombre: string que representa el nombre del pasajero
            - edad: int que representa la edad del pasajero
            - pasaporte: objeto de la estructura Pasaporte que representa el pasaporte del pasajero
            - nacionalidad: string que representa la nacionalidad del pasajero
            - sexo: string que representa el sexo del pasajero
            - maleta: objeto de la estructura Maleta que representa la maleta del pasajero
        Retorno: void
        */
        Pasajero(string nombre, int edad, Pasaporte pasaporte, string nacionalidad, string sexo, Maleta maleta){
            this->nombre = nombre;
            this->edad = edad;
            this->pasaporte = pasaporte;
            this->nacionalidad = nacionalidad;
            this->sexo = sexo;
            *this->maleta = maleta;
        }
    // Metodos
        /*
        Funcion que muestra los datos del pasajero
        Parametros: ninguno
        Retorno: void
        */
        void mostrarDatos(){
            cout << "Nombre: " << nombre << endl;
            cout << "Edad: " << edad << endl;
            cout << "Pasaporte: " << pasaporte.codigo << endl;
            cout << "Nacionalidad: " << nacionalidad << endl;
            cout << "Sexo: " << sexo << endl;
            cout << "Maleta: " << maleta->getDescripcion() << endl;
        }

        // Getters
        /*
        Funcion que retorna el nombre del pasajero
        Parametros: ninguno
        Retorno: string que representa el nombre del pasajero
        */
        string getNombre(){
            return nombre;
        }

        /*
        Funcion que retorna la edad del pasajero
        Parametros: ninguno
        Retorno: int que representa la edad del pasajero
        */
        int getEdad(){
            return edad;
        }

        /*
        Funcion que retorna el codigo del pasaporte del pasajero
        Parametros: ninguno
        Retorno: string que representa el codigo del pasaporte del pasajero
        */
        Pasaporte getPasaporte(){
            return pasaporte;
        }

        /*
        Funcion que retorna la nacionalidad del pasajero
        Parametros: ninguno
        Retorno: string que representa la nacionalidad del pasajero
        */
        string getNacionalidad(){
            return nacionalidad;
        }

        /*
        Funcion que retorna el sexo del pasajero
        Parametros: ninguno
        Retorno: string que representa el sexo del pasajero
        */
        string getSexo(){
            return sexo;
        }

        /*
        Funcion que retorna la descripcion de la maleta del pasajero
        Parametros: ninguno
        Retorno: string que representa la descripcion de la maleta del pasajero
        */
        Maleta getMaleta(){
            return *maleta;
        }

        /*
        Funcion que retorna el contenido de la maleta del pasajero
        Parametros: ninguno
        Retorno: string que representa el contenido de la maleta del pasajero
        */
        string getContenidoMaleta(){
            string contenido = "";
            for (auto it = maleta->getContenido().begin(); it != maleta->getContenido().end(); ++it)
            {
                contenido += *it;
                contenido += ", ";
            }
            return contenido;
        }
};