//
// Created by aquir on 23/9/2023.
//

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

        ListaDoblePasajero(string pasaporte,string nacion,string pasajero){
            this->pasaporte=pasaporte;
            this->nacion=nacion;
            this->pasajero=pasajero;
            siguiente=anterior = NULL;
        }
        ListaDoblePasajero();//Constructor
        ~ListaDoblePasajero();//Destructor
        void insertarFinal(string pasaporte,string nacion,string pasajero);
        // Explicacion:
        // Este metodo se encarga de insertar noticias a final de la lista doble.
        int  largoLista();
        // Explicacion:
        //  Este metodo se encarga de retornar el largo de la lista doble.
        ListaDoblePasajero * buscarPasaporte(string pasaporte);
        // Explicacion:
        //  Este metodo se encarga de buscar un nodo de la lista doble.
        void mostrar() ;
        // Explicacion:
        //  Este metodo se encarga de mostrar la lista doble.
        void Borrar(string pasaporte);
        // Explicacion:
        //  Este metodo se encarga de borrar un nodo de la lista doble.
        bool listaVacia(){return primerNodo=nullptr;}
        // Explicacion:
        //  Este metodo se encarga de validar si la lista doble se encuentra vacia o no se encuentra vacia.
};


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
};