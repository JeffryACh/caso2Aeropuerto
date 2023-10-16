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
#include <set>
#include "validaciones.cpp"
#include "clasePasajeros.cpp"
#include "json.hpp"


using json = nlohmann::json;
using namespace std;

const string SEXO[2] = {"M", "F"};

string sacarUnPaisAleatorio(const json& datos) {
    // Accede a la lista de nacionalidades desde el archivo JSON
    json nacionalidades = datos["pasaporte"]["nacionalidad"];

    // Genera un número aleatorio para seleccionar una nacionalidad
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, nacionalidades.size() - 1);
    int indiceAleatorio = dist(gen);

    // Devuelve la nacionalidad aleatoria seleccionada
    return nacionalidades[indiceAleatorio];
}

string sacarUnNombreAleatorio(const json& datos){
    // Accede a la lista de nombres desde el archivo JSON
    json nombres = datos["pasajero"]["nombre"];

    // Genera un número aleatorio para seleccionar un nombre
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, nombres.size() - 1);
    int indiceAleatorio = dist(gen);

    // Devuelve el nombre aleatorio seleccionado
    return nombres[indiceAleatorio];
}

// Función para obtener 5 elementos aleatorios de la sección "posibleContenidoDeLasMaletas"
vector<string> obtenerContenidoMaletaAleatorio(const json& datos) {
    // Accede a la lista de posibles contenidos de las maletas desde el archivo JSON
    json contenidos = datos["maleta"]["posibleContenidoDeLasMaletas"];

    // Verifica si hay al menos 5 elementos en la lista
    if (contenidos.size() < 5) {
        cerr << "No hay suficientes elementos en la lista de contenidos de maletas." << std::endl;
        return {};
    }

    // Genera un número aleatorio para seleccionar 5 elementos diferentes
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, contenidos.size() - 1);

    vector<string> contenidoAleatorio;
    set<int> indicesSeleccionados;

    while (indicesSeleccionados.size() < 5) {
        int indiceAleatorio = dist(gen);

        // Asegura que no seleccionemos el mismo elemento dos veces
        if (indicesSeleccionados.find(indiceAleatorio) == indicesSeleccionados.end()) {
            indicesSeleccionados.insert(indiceAleatorio);
            contenidoAleatorio.push_back(contenidos[indiceAleatorio]);
        }
    }

    return contenidoAleatorio;
}

int sacarEdadAleatoria(const json& datos){
    // Accede a la lista de edades desde el archivo JSON
    json edadMinima = datos["pasajero"]["minEdad"];
    json edadMaxima = datos["pasajero"]["maxEdad"];

    // Genera un número aleatorio para seleccionar una edad
    random_device rd;
    mt19937 gen(rd()); // Generador de números aleatorios
    uniform_int_distribution<int> dist(edadMinima, edadMaxima);
    int edadAleatoria = dist(gen); // Edad aleatoria

    // Devuelve la edad aleatoria seleccionada
    return edadAleatoria;
}

json sacarSexoAleatorio(const json& datos){
    // Accede a la lista de sexos desde el archivo JSON
    json sexos = datos["pasajero"]["sexo"];

    // Genera un número aleatorio para seleccionar un sexo
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, sexos.size() - 1);
    int indiceAleatorio = dist(gen);

    // Devuelve el sexo aleatorio seleccionado
    return sexos[indiceAleatorio];
}

/**
 * @brief Función que genera un código de pasaporte erróneo para una persona con los parámetros dados.
 * 
 * @param pNacionalidad La nacionalidad de la persona.
 * @param pNombre El nombre de la persona.
 * @param pEdad La edad de la persona.
 * @return Un string con el código de pasaporte erróneo generado.
 */
string generadorDePasaportesErroneos(string pNacionalidad, string pNombre, int pEdad, const json& datos){;
    bool codigoValido = false;

    string codigoErroneo = "";

    while(!codigoValido){
        codigoErroneo = "";
        codigoErroneo += sacarUnPaisAleatorio(datos);
        codigoErroneo += sacarUnNombreAleatorio(datos);
        codigoErroneo += to_string(sacarEdadAleatoria(datos));
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
Pasajero generarUnPasajero(const json& datos){
    string nombre = sacarUnNombreAleatorio(datos);
    int edad = sacarEdadAleatoria(datos);
    string nacionalidad = sacarUnPaisAleatorio(datos);
    string sexo = SEXO[rand() % 2];
    int ruletaCodigo = rand() % 2; // Si sale 1 el codigo sera erroneo y si sale 0 sera correcto
    string codigoPasaporte;
    if (ruletaCodigo == 1){
        codigoPasaporte = generadorDePasaportesErroneos(nacionalidad, nombre, edad, datos);
    } else {  
        codigoPasaporte = generadorDePasaportes(nacionalidad, nombre, edad);
    };
    vector <string> contenidoMaleta = obtenerContenidoMaletaAleatorio(datos);
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
    // Abre el archivo JSON
    std::ifstream archivo("aeropuerto.json");

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo JSON." << std::endl;
        return 1;
    }

    // Lee el contenido JSON en un objeto json
    json datos;
    archivo >> datos;

    
    for (int i = 0; i < 5; i++){
        pasajeros.push_back(generarUnPasajero(datos));
    }

    for (int i = 0; i < 5; i++){
        pasajeros[i].mostrarDatos();
        cout << pasajeros[i].getMaleta().getContenido() << endl;
    }

    

    return 0;
}