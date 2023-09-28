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

using namespace std;

const string PAISES[15] = {"CRC", "USA", "ESP", "COL", "PAN", "PER", "MEX", "BRA", "ARG", "CHI", "URU", "PAR", "ECU", "BOL", "VEN"};
const string NOMBRES[15] = {"Jeffry", "Andres", "Juan", "Pedro", "Maria", "Jose", "Luis", "Carlos", "Ana", "Sofia", "Luisa", "Fernanda", "Fernando", "Jorge", "Javier"};
const string SEXO[2] = {"M", "F"};
const string CONTENIDO[20] = {"Pistola", "Cuchillo", "Explosivos", "Quimicos peligrosos", "Drogas", "Ropa", "Zapatos", "Laptop", "Tablet", "Audifonos", "Cargador", "Billetera", "Dinero", "Pasaporte", "Maquillaje", "Cepillo de dientes", "Cepillo de cabello", "Cuaderno", "Libro", "Lapicero"};
const int MAXIMA_EDAD = 75;
const int MINIMA_EDAD = 16;

/*
    * Funcion que genera un codigo de pasaporte aleatorio
    * @return string codigo de pasaporte

    * Hay que generar pasageros aleatorios
    * Hay que generar maletas aleatorias
*/

/**
 * @brief Generates a random passport code for a given passenger, until a valid one is found.
 * 
 * @param pPasajero The passenger for whom the passport code is being generated.
 * @return A string representing the generated passport code.
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
    }
    std::vector<std::string> contenidoMaleta(5);
    for (int i = 0; i < 5; i++){
        contenidoMaleta[i] = CONTENIDO[rand() % 20];
    }
    Maleta maleta;
    maleta.peso = rand() % 50 + 1;
    maleta.descripcion = "Maleta de " + nombre;
    maleta.propietario = nombre;
    maleta.contenido = contenidoMaleta;
    Pasaporte pasaporte = {codigoPasaporte, nacionalidad, sexo};
    Pasajero pasajero = {nombre, edad, pasaporte, nacionalidad, sexo, maleta};
    return pasajero;
}

int main(){
    std::vector<Pasajero> pasajeros;
    
    for (int i = 0; i < 5; i++){
        pasajeros.push_back(generarUnPasajero());
    }

    for (int i = 0; i < 5; i++){
        pasajeros[i].mostrarDatos();
        cout << endl;
        cout << "Contenido de la maleta: " << pasajeros[i].getContenidoMaleta() << endl;
        cout << endl;
    }

    return 0;
}