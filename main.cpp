/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 10/09/2021 15:35
*/

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include "validaciones.cpp"
#include "clasePasajeros.cpp"
#include <random>
#include <fstream>
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

int main(){
    vector<Pasajero> pasajeros;
    
    for (int i = 0; i < 5; i++){
        pasajeros.push_back(generarUnPasajero());
    }

    for (int i = 0; i < 5; i++){
        pasajeros[i].mostrarDatos();
        cout << pasajeros[i].getMaleta().getContenido() << endl;
    }

    

    return 0;
}