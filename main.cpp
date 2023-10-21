/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 08/10/2021 17:20
*/

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <fstream>
#include <queue>
#include "validaciones.h"
#include "claseAbordaje.h"
#include "json.hpp"


using json = nlohmann::json;
using namespace std;

const string PAISES[15] = {"CRC", "USA", "ESP", "COL", "PAN", "PER", "MEX", "BRA", "ARG", "CHI", "URU", "PAR", "ECU", "BOL", "VEN"};
const string NOMBRES[15] = {"Jeffry", "Andres", "Juan", "Pedro", "Maria", "Jose", "Luis", "Carlos", "Ana", "Sofia", "Luisa", "Fernanda", "Fernando", "Jorge", "Javier"};
const string SEXO[2] = {"M", "F"};
const string CONTENIDO[20] = {"Pistola", "Cuchillo", "Explosivos", "Quimicos peligrosos", "Drogas", "Ropa", "Zapatos", "Laptop", "Tablet", "Audifonos", "Cargador", "Billetera", "Dinero", "Pasaporte", "Maquillaje", "Cepillo de dientes", "Cepillo de cabello", "Cuaderno", "Libro", "Lapicero"};
const int MAXIMA_EDAD = 75;
const int MINIMA_EDAD = 16;
using json = nlohmann::json;
/**
 * @brief Función que genera un código de pasaporte erróneo para una persona con los parámetros dados.
 * 
 * @param pNacionalidad La nacionalidad de la persona.
 * @param pNombre El nombre de la persona.
 * @param pEdad La edad de la persona.
 * @return Un string con el código de pasaporte erróneo generado.
 */
string generadorDePasaportesErroneos(string pNacionalidad, string pNombre, int pEdad){;
    bool codigoValido = false;

    string codigoErroneo = "";

    while(!codigoValido){
        codigoErroneo = "";
        codigoErroneo += PAISES[rand() % 15];
        codigoErroneo += NOMBRES[rand() % 15];
        codigoErroneo += to_string(rand() % (MAXIMA_EDAD - MINIMA_EDAD + 1) + MINIMA_EDAD);
        for (int i = 0; i < 6; i++){
            codigoErroneo += to_string(rand() % 10);
        }
        codigoValido = !validarCodigoPasaporte(codigoErroneo, pNacionalidad, pNombre, pEdad);
    }
    return codigoErroneo;
}

/**
 * @brief Función que genera un código de pasaporte válido a partir de la nacionalidad, nombre y edad del pasajero.
 * 
 * @param pNacionalidad La nacionalidad del pasajero.
 * @param pNombre El nombre del pasajero.
 * @param pEdad La edad del pasajero.
 * @return string El código de pasaporte generado.
 */
string generadorDePasaportes(string pNacionalidad, string pNombre, int pEdad){
    string codigo = "";

    string codigoValido = "";
    codigoValido += pNacionalidad;
    codigoValido += pNombre.substr(0,3);
    codigoValido += to_string(pEdad);
    for (int i = 0; i < 6; i++){
        codigoValido += to_string(rand() % 10);
    }
    return codigoValido;
}

/**
 * Función que genera un objeto de tipo Pasajero con datos aleatorios.
 * @return Pasajero objeto generado con datos aleatorios.
 */
Pasajero generarUnPasajero(){
    string nombre = NOMBRES[rand() % 15];
    int edad = rand() % (MAXIMA_EDAD - MINIMA_EDAD + 1) + MINIMA_EDAD;
    string nacionalidad = PAISES[rand() % 15];
    string sexo = SEXO[rand() % 2];
    int ruletaCodigo = rand() % 2; // Si sale 1 el codigo sera erroneo y si sale 0 sera correcto
    string codigoPasaporte;
    if (ruletaCodigo == 1){
        codigoPasaporte = generadorDePasaportesErroneos(nacionalidad, nombre, edad);
    } else {  
        codigoPasaporte = generadorDePasaportes(nacionalidad, nombre, edad);
    };
    vector <string> contenidoMaleta;
    for (int i = 0; i < 5; i++){
        contenidoMaleta.push_back(CONTENIDO[rand() % 20]);
    };
    int peso = rand() % 20 + 1;
    string descripcion = "Maleta de " + nombre;
    string propietario = nombre;
    Maleta maleta(peso, descripcion, propietario, contenidoMaleta);
    Pasaporte pasaporte = {codigoPasaporte, nacionalidad, sexo};
    Pasajero pasajero(nombre, edad, pasaporte, nacionalidad, sexo, maleta);
    return pasajero;
}

// Función para generar pasajeros con maletas y mostrar sus datos
void generarYMostrarPasajeros(int cantidadPasajeros) {
    queue<Pasajero> colaPasajeros;

    // Genera la cantidad de pasajeros especificada y encola cada uno
    for (int i = 0; i < cantidadPasajeros; i++) {
        Pasajero pasajero = generarUnPasajero();
        colaPasajeros.push(pasajero);
    }

    // Muestra los datos de los pasajeros y el contenido de sus maletas al desencolarlos
    int numeroPasajero = 1;
    while (!colaPasajeros.empty()) {
        Pasajero pasajero = colaPasajeros.front();

        // Validar el código de pasaporte
        bool codigoValido = validarCodigoPasaporte(pasajero.getPasaporte().codigo, pasajero.getPasaporte().nacionalidad, pasajero.getNombre(), pasajero.getEdad());

        // Mostrar datos del pasajero
        cout << "Datos del Pasajero " << numeroPasajero << ":" << endl;
        pasajero.mostrarDatos();
        cout << "Contenido de la Maleta: " << pasajero.getMaleta().getContenido() << endl;
        cout << "-------------------------------------" << endl;

        if (!codigoValido) {
            cout << "El pasaporte de " << pasajero.getNombre() << " es erróneo." << endl;
            // Puedes agregar aquí una lógica adicional, como notificar al pasajero o a las autoridades.
        }

        colaPasajeros.pop();
        numeroPasajero++;
    }
}



int main(){

    int limitePasajeros = 10;
    generarYMostrarPasajeros(limitePasajeros);
   /* vector<Pasajero> pasajeros;
    
    for (int i = 0; i < 5; i++){
        pasajeros.push_back(generarUnPasajero());
    }

    for (int i = 0; i < 5; i++){
        pasajeros[i].mostrarDatos();
        cout << pasajeros[i].getMaleta().getContenido() << endl;
    }*/

    

    return 0;
}