#include<iostream>
#include"clasePasajeros.h"

using namespace std;

// Definición de la estructura Nodo
struct Node {
    Pasajero data; // dato del nodo
    Node* next; // puntero al siguiente nodo

    // Constructor de la estructura Nodo
    Node(string nombre, int edad, Pasaporte pasaporte, string nacionalidad, string sexo, Maleta maleta) : data(nombre, edad, pasaporte, nacionalidad, sexo, maleta) {
    next = NULL;
    }
};

// Definición de la clase Cola
class Personas {
    private:
        Node* front; // puntero al frente de la cola
        Node* rear; // puntero a la parte trasera de la cola
    public:
        // Constructor de la clase Cola
        Personas() {
            front = NULL;
            rear = NULL;
        }

        // Métodos de la clase Cola
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

        // Función para eliminar un elemento de la cola
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

        // Función para mostrar los elementos de la cola
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

        bool isEmpty() {
            return front == NULL;
        }

        // Función para mostrar el elemento del frente de la cola
        void frontElement() {
            if(isEmpty()) {
                cout << "La cola está vacía" << endl;
            } else {
                cout << "El elemento del frente es: " << front->data.getNombre() << endl;
            }
        }

        // Metodo para retornar el elemento del frente de la cola
        Pasajero getFrontElement() {
            if(isEmpty()) {
                cout << "La cola está vacía" << endl;
            } else {
                return front->data;
            }
        }
};
