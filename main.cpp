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
#include "validacion.h"
#include "claseAbordaje.h"
#include "lobbyEspera.h"
#include "AlmMaleta.h"
#include "json.hpp"
#include "retencion.h"
#include "claseRecepcionEquipaje.h"
const int totalPasajeros = 100;
const int pasajerosPorGrupo = 10;
std::mutex mtx;  // Mutex se usa para asegurarse de que los hilos impriman de manera ordenada


using namespace std;

const string PAISES[15] = {"CRC", "USA", "ESP", "COL", "PAN", "PER", "MEX", "BRA", "ARG", "CHI", "URU", "PAR", "ECU", "BOL", "VEN"};
const string NOMBRES[15] = {"Jeffry", "Andres", "Juan", "Pedro", "Maria", "Jose", "Luis", "Carlos", "Ana", "Sofia", "Luisa", "Fernanda", "Fernando", "Jorge", "Javier"};
const string SEXO[2] = {"M", "F"};
const string CONTENIDO[20] = {"Pistola", "Cuchillo", "Explosivos", "Quimicos peligrosos", "Drogas", "Ropa", "Zapatos", "Laptop", "Tablet", "Audifonos", "Cargador", "Billetera", "Dinero", "Pasaporte", "Maquillaje", "Cepillo de dientes", "Cepillo de cabello", "Cuaderno", "Libro", "Lapicero"};
const int MAXIMA_EDAD = 75;
const int MINIMA_EDAD = 16;
using json = nlohmann::json;

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
    string nombre = NOMBRES[rand() % 15].substr(0,3);
    int edad = rand() % (MAXIMA_EDAD - MINIMA_EDAD + 1) + MINIMA_EDAD;
    string nacionalidad = PAISES[rand() % 15];
    string sexo = SEXO[rand() % 2];
    int ruletaCodigo = rand() % 2; // Si sale 1 el codigo sera erroneo y si sale 0 sera correcto

    cout<<ruletaCodigo<<endl;

    cout << "Ruleta: " << ruletaCodigo << endl;
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

    // Muestra los datos de los pasajeros al desencolarlos
    int numeroPasajero = 1;
    while (!colaPasajeros.empty()) {
        Pasajero pasajero = colaPasajeros.front();

        // Validar el código de pasaporte
        bool codigoValido = validarCodigoPasaporte(pasajero.getPasaporte().codigo, pasajero.getPasaporte().nacionalidad, pasajero.getNombre(), pasajero.getEdad());

        // Mostrar datos del pasajero
        cout << "Datos del Pasajero " << numeroPasajero << ":" << endl;
        pasajero.mostrarDatos();
        cout << "-------------------------------------" << endl;

        if (!codigoValido) {
            cout << "El pasaporte de " << pasajero.getNombre() << " es erróneo." << endl;
            // Puedes agregar aquí una lógica adicional, como notificar al pasajero o a las autoridades.
        }

        colaPasajeros.pop();
        numeroPasajero++;
    }
}
// Función para generar  maletas y mostrar su contenido
void generarYMostrarMaletas(int cantidadMaletas) {
    queue<Maleta> colaMaletas;

    // Genera la cantidad de maletas especificada y encola cada una
    for (int i = 0; i < cantidadMaletas; i++) {
        Maleta maleta = generarUnPasajero().getMaleta();
        colaMaletas.push(maleta);
    }

    // Muestra los datos de las maletas al desencolarlas
    int numeroMaleta = 1;
    while (!colaMaletas.empty()) {
        Maleta maleta = colaMaletas.front();
        vector<string> contenidoMaleta = maleta.getContenidoVector();
        bool contenidoValido = validarContenidoMaleta(contenidoMaleta);

        // Mostrar datos de la maleta
        cout << "Datos de la Maleta " << numeroMaleta << ":" << endl;
        maleta.getDescripcion();
        maleta.getContenido();
        cout << "-------------------------------------" << endl;

        if (!contenidoValido) {
            cout << "La maleta " << maleta.getDescripcion() << " contiene elementos peligrosos." << endl;





        }

        colaMaletas.pop();
        numeroMaleta++;
    }
}


void procesarGrupoDePasajeros(int inicio, int fin) {
    for (int i = inicio; i < fin; i++) {
        {
            std::lock_guard<std::mutex> lock(mtx);  // Bloquear la impresión
            std::cout << "Procesando pasajero " << i + 1 << std::endl;
        }
        // Realizar aquí el procesamiento específico para el pasajero i
    }
}

int main(){
    AlmacenarMaletas almacenMaletas;
    int limitePasajeros = 10;
    std::vector<std::thread> hilos;

    for (int i = 0; i < totalPasajeros; i += pasajerosPorGrupo) {
        int inicio = i;
        int fin = std::min(i + pasajerosPorGrupo, totalPasajeros);
        hilos.push_back(std::thread(procesarGrupoDePasajeros, inicio, fin));
    }

    // Esperar a que todos los hilos terminen
    for (std::thread &hilo : hilos) {
        hilo.join();
    }
    //RecepcionEquipaje recepcionEquipaje;

    // Crear dos hilos para generar y mostrar pasajeros y maletas en paralelo
    thread t1(generarYMostrarPasajeros, limitePasajeros);
    thread t2(generarYMostrarMaletas, limitePasajeros);
    Personas personas(limitePasajeros);
    personas.iniciarHilosGeneracion();
    //std::thread tAlmacenarMaletas(almacenarMaletasThread, std::ref(almacenMaletas));
    //std::thread hiloRecepcionEquipaje(&RecepcionEquipaje::iniciarRecepcionEquipaje, &RecepcionEquipaje);


    //Crear un hilo para ejecutar la funcionalidad del Lobby de Espera
    //personas.iniciarHilosGeneracion();
    generarYMostrarPasajeros(limitePasajeros);
    generarYMostrarMaletas(limitePasajeros);
    //std::thread t(AlmacenarMaletas, std::ref(almacenMaletas));
    t1.join();
    t2.join();


    return 0;
}