/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 08/10/2021 17:20
*/

#include<iostream>
#include"clasePasajeros.h"

using namespace std;


/**
 * @brief Estructura de datos que representa un nodo de una lista enlazada simple.
 * 
 */
struct Node {
    Pasajero data; // dato del nodo
    Node* next; // puntero al siguiente nodo

    /**
     * @brief Constructor de la estructura Node.
     * 
     * @param nombre Nombre del pasajero.
     * @param edad Edad del pasajero.
     * @param pasaporte Pasaporte del pasajero.
     * @param nacionalidad Nacionalidad del pasajero.
     * @param sexo Sexo del pasajero.
     * @param maleta Maleta del pasajero.
     */
    Node(string nombre, int edad, Pasaporte pasaporte, string nacionalidad, string sexo, Maleta maleta) : data(nombre, edad, pasaporte, nacionalidad, sexo, maleta) {
        next = NULL;
    }
};


/**
 * @brief Clase que representa una cola de personas en un aeropuerto.
 * 
 */
class Personas {
    private:
        Node* front; // puntero al frente de la cola
        Node* rear; // puntero a la parte trasera de la cola
    public:
        /**
         * @brief Constructor de la clase Cola.
         * 
         */
        Personas() {
            front = NULL;
            rear = NULL;
        }

        /**
         * @brief Agrega un pasajero a la cola.
         * 
         * @param p Pasajero a agregar.
         */
        void agregarPasajero(Pasajero p) {
            Node* temp = new Node(p.getNombre(), p.getEdad(), p.getPasaporte(), p.getNacionalidad(), p.getSexo(), p.getMaleta());
            temp->data = p;
            temp->next = NULL;
            if (front == NULL) {
                front = temp;
            } else {
                rear->next = temp;
            }
            rear = temp;
        }

        /**
         * @brief Elimina el primer elemento de la cola.
         * 
         */
        void salidaDePasajero() {
            if(front == NULL) {
                cout << "La cola está vacía" << endl;
            } else {
                Node* temp = front;
                front = front->next;
                delete temp;

                if(front == NULL) {
                    rear = NULL;
                }
            }
        }

        /**
         * @brief Muestra los elementos de la cola.
         * 
         */
        void display() {
            if(front == NULL) {
                cout << "La cola está vacía" << endl;
            } else {
                Node* temp = front;

                while(temp != NULL) {
                    cout << temp->data.getNombre() << endl;
                    temp = temp->next;
                }
                cout << endl;
            }
        }

        /**
         * @brief Verifica si la cola está vacía.
         * 
         * @return true si la cola está vacía.
         * @return false si la cola no está vacía.
         */
        bool isEmpty() {
            return front == NULL;
        }

        /**
         * @brief Muestra el elemento del frente de la cola.
         * 
         */
        void frontElement() {
            if(isEmpty()) {
                cout << "La cola está vacía" << endl;
            } else {
                cout << "El elemento del frente es: " << front->data.getNombre() << endl;
            }
        }

        /**
         * @brief Retorna el elemento del frente de la cola.
         * 
         * @return Pasajero Elemento del frente de la cola.
         */
        Pasajero getFrontElement() {
            if(isEmpty()) {
                cout << "La cola está vacía" << endl;
            } else {
                return front->data;
            }
        }
};
