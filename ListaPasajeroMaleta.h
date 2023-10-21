/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 08/10/2021 17:20
*/
/*
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class ListaDoblePasajero {
    public:
        string pasaporte;
        string nacion;
        string pasajero;// cambiar por clase pasajero
        ListaDoblePasajero*siguiente;
        ListaDoblePasajero* anterior;
        ListaDoblePasajero *primerNodo;

        /**
         * @brief Constructor de la clase ListaDoblePasajero
         *
         * @param pasaporte Numero de pasaporte del pasajero
         * @param nacion Nacionalidad del pasajero
         * @param pasajero Nombre completo del pasajero
         */
        ListaDoblePasajero(string pasaporte,string nacion,string pasajero);

        /**
         * @brief Constructor por defecto de la clase ListaDoblePasajero
         *
         */
        ListaDoblePasajero();//Constructor

        /**
         * @brief Destructor de la clase ListaDoblePasajero
         *
         */
        ~ListaDoblePasajero();//Destructor

        /**
         * @brief Inserta un nodo al final de la lista doble
         *
         * @param pasaporte Numero de pasaporte del pasajero
         * @param nacion Nacionalidad del pasajero
         * @param pasajero Nombre completo del pasajero
         */
        void insertarFinal(string pasaporte,string nacion,string pasajero);

        /**
         * @brief Retorna el largo de la lista doble
         *
         * @return int Largo de la lista doble
         */
        int  largoLista();

        /**
         * @brief Busca un nodo en la lista doble
         *
         * @param pasaporte Numero de pasaporte del pasajero a buscar
         * @return ListaDoblePasajero* Puntero al nodo encontrado, o nullptr si no se encuentra
         */
        ListaDoblePasajero * buscarPasaporte(string pasaporte);

        /**
         * @brief Muestra los elementos de la lista doble
         *
         */
        void mostrar() ;

        /**
         * @brief Borra un nodo de la lista doble
         *
         * @param pasaporte Numero de pasaporte del pasajero a borrar
         */
        void Borrar(string pasaporte);

        /**
         * @brief Valida si la lista doble se encuentra vacia
         *
         * @return true Si la lista doble se encuentra vacia
         * @return false Si la lista doble no se encuentra vacia
         */
        bool listaVacia(){return primerNodo=nullptr;}
};

/*
class listaDobleMaleta{
    public:
        string contMaleta;
        string colorMaleta;
        listaDobleMaleta*siguiente;
        listaDobleMaleta* anterior;
        listaDobleMaleta *segundoNodo;
        listaDobleMaleta(string contMaleta,string colorMaleta){
            this->contMaleta=contMaleta;
            this->colorMaleta=colorMaleta;
            siguiente=anterior = NULL;

        }
        listaDobleMaleta(); // Constructor
        ~listaDobleMaleta();// Destructor
        void insertarFinal(string contMaleta,string colorMaleta);
        // Explicacion:
        // Este metodo se encarga de insertar noticias a final de la lista doble.
        int  largoLista();
        // Explicacion:
        //
        listaDobleMaleta * buscarMaleta(string colorMaleta);
        // Explicacion:
        //
        void mostrar() ;
        // Explicacion:
        //
        void Borrar(string colorMaleta);
        // Explicacion:
        //
        bool listaVacia(){return segundoNodo=nullptr;}
        // Explicacion:
        //  Este metodo se encarga de validar si la lista doble se encuentra vacia o no se encuentra vacia.
};*/