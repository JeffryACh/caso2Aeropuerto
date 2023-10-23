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
#include <mutex>
#include "validaciones.h"
#include "claseAbordaje.h"
#include "lobbyEspera.h"
#include "AlmMaleta.h"
#include "json.hpp"
#include "retencion.h"
#include "claseRecepcionEquipaje.h"
const int totalPasajeros = 100;
const int pasajerosPorGrupo = 10;
std::mutex mtx;  // Mutex para asegurarse de que los hilos impriman de manera ordenada

using json = nlohmann::json;
using namespace std;

string sacarPaisesDelJson(json& pJson){
    json paises = pJson["pasaporte"]["nacionalidad"];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, paises.size() - 1);
    int indiceAleatorio = dist(gen);

    // Devuelve la nacionalidad aleatoria seleccionada
    return paises[indiceAleatorio];
}

string sacarNombreRamdomDelJson(json& pJson){
    json nombres = pJson["pasajero"]["nombre"];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, nombres.size() - 1);
    int indiceAleatorio = dist(gen);

    // Devuelve el nombre aleatorio seleccionado
    return nombres[indiceAleatorio];
}

string sacarSexoRamdom(json& pJson){
    json sexos = pJson["pasajero"]["sexo"];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, sexos.size() - 1);
    int indiceAleatorio = dist(gen);

    // Devuelve el sexo aleatorio seleccionado
    return sexos[indiceAleatorio];
}

vector<string> sacarContenidoRamdom(json& pJson){
    json contenidos = pJson["maleta"]["contenido"];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, contenidos.size() - 1);
    int indiceAleatorio = dist(gen);

    // Devuelve el contenido aleatorio seleccionado
    return contenidos[indiceAleatorio];
}

int sacarEdadRandom(json& pJson){
    int edadeMin = pJson["pasajero"]["minEdad"];
    int edadeMax = pJson["pasajero"]["maxEdad"];

    int edad = rand() % (edadeMax - edadeMin + 1) + edadeMin;

    // Devuelve la edad aleatoria seleccionada
    return edad;
}

/**
 * @brief Función que genera un código de pasaporte erróneo para una persona con los parámetros dados.
 * 
 * @param pNacionalidad La nacionalidad de la persona.
 * @param pNombre El nombre de la persona.
 * @param pEdad La edad de la persona.
 * @return Un string con el código de pasaporte erróneo generado.
 */
string generadorDePasaportesErroneos(string pNacionalidad, string pNombre, int pEdad, json& pJson){;
    bool codigoValido = false;

    string codigoErroneo = "";

    while(!codigoValido){
        codigoErroneo = "";
        codigoErroneo += sacarPaisesDelJson(pJson);
        codigoErroneo += sacarNombreRamdomDelJson(pJson).substr(0,3);
        codigoErroneo += to_string(sacarEdadRandom(pJson));
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
Pasajero generarUnPasajero(json& pJson){
    string nombre = sacarNombreRamdomDelJson(pJson).substr(0,3);
    int edad = sacarEdadRandom(pJson);
    string nacionalidad = sacarPaisesDelJson(pJson);
    string sexo = sacarSexoRamdom(pJson);
    int ruletaCodigo = rand() % 2; // Si sale 1 el codigo sera erroneo y si sale 0 sera correcto

    cout<<ruletaCodigo<<endl;

    cout << "Ruleta: " << ruletaCodigo << endl;
    string codigoPasaporte;
    if (ruletaCodigo == 1){
        codigoPasaporte = generadorDePasaportesErroneos(nacionalidad, nombre, edad, pJson);
    } else {  
        codigoPasaporte = generadorDePasaportes(nacionalidad, nombre, edad);
    };
    vector <string> contenidoMaleta;
    contenidoMaleta = sacarContenidoRamdom(pJson);
    int peso = rand() % 20 + 1;
    string descripcion = "Maleta de " + nombre;
    string propietario = nombre;
    Maleta maleta(peso, descripcion, propietario, contenidoMaleta);
    Pasaporte pasaporte = {codigoPasaporte, nacionalidad, sexo};
    Pasajero pasajero(nombre, edad, pasaporte, nacionalidad, sexo, maleta);
    return pasajero;
}

// Función para generar pasajeros con maletas y mostrar sus datos

void generarYMostrarPasajeros(int cantidadPasajeros, json& pJson) {
    queue<Pasajero> colaPasajeros;
    queue<Maleta> colaMaletas;


    // Genera la cantidad de pasajeros especificada y encola cada uno
    for (int i = 0; i < cantidadPasajeros; i++) {
        Pasajero pasajero = generarUnPasajero(pJson);
        colaPasajeros.push(pasajero);
        Maleta maleta = generarUnPasajero(pJson).getMaleta();
        colaMaletas.push(maleta);
    }

    // Muestra los datos de los pasajeros al desencolarlos
    int numeroPasajero = 1;
    while (!colaPasajeros.empty() && !colaMaletas.empty()) {
        Pasajero pasajero = colaPasajeros.front();

        // Validar el código de pasaporte
        bool codigoValido = validarCodigoPasaporte(pasajero.getPasaporte().codigo, pasajero.getPasaporte().nacionalidad, pasajero.getNombre(), pasajero.getEdad());
        bool contenidoValido = validarContenidoMaleta(pasajero.getMaleta().getContenidoVector());

        // Mostrar datos del pasajero
        cout << "Datos del Pasajero " << numeroPasajero << ":" << endl;
        pasajero.mostrarDatos();
        cout << "-------------------------------------" << endl;

        cout << "Datos de la Maleta " << numeroPasajero << ":" << endl;
        pasajero.getMaleta().getDescripcion();
        pasajero.getMaleta().getContenido();
        cout << "-------------------------------------" << endl;

        
        if (!codigoValido || !contenidoValido) {
            cout << "La Maleta " << pasajero.getMaleta().getDescripcion() << " contiene elementos peligrosos." << endl;
            cout << "El pasaporte de " << pasajero.getNombre() << " es erróneo." << endl;
            Retencion retencion = Retencion(10, 10, 10, pasajero.getMaleta(), pasajero);
            // Puedes agregar aquí una lógica adicional, como notificar al pasajero o a las autoridades.
        }

        colaPasajeros.pop();
        numeroPasajero++;
    }
}

void procesarGrupoDePasajeros(int inicio, int fin, json& pJson) {
    std::mutex mtx;  // Mutex para bloquear la impresión
    for (int i = inicio; i < fin; i++) {
        {
            std::lock_guard<std::mutex> lock(mtx);  // Bloquear la impresión
            std::cout << "Procesando pasajero " << i << std::endl;
            generarYMostrarPasajeros(pasajerosPorGrupo, pJson);
        }
        // Realizar aquí el procesamiento específico para el pasajero i
    }
}

int main(){
    std::vector<std::thread> hilo;

    AlmacenarMaletas almacenMaletas;
    int limitePasajeros = 10;
    std::vector<std::thread> hilos;

    json pJson;
    ifstream i("aeropuerto.json");
    i >> pJson;
    int totalPasajeros = pJson["totalPasajeros"];
    int pasarPorGrupo = 10;

    for (int i = 0; i < totalPasajeros ; i += pasarPorGrupo) {
        int inicio = i;
        int fin = std::min(i + pasarPorGrupo, totalPasajeros);
        hilos.push_back(std::thread(procesarGrupoDePasajeros, inicio, fin, std::ref(pJson)));
    }

    // Esperar a que todos los hilos terminen
    for (std::thread &hilo : hilos) {
        hilo.join();
    }
    

    return 0;
}