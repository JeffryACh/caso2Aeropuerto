//
// Created by aquir on 14/10/2023.
//

#ifndef CASO2_ED_LOBBYESPERA_H
#define CASO2_ED_LOBBYESPERA_H



#include <iostream>
#include "clasePasajero.h"

struct Node {
    Pasajero data;
    Node* next;

    Node(const Pasajero& pasajero);
};
// Constructor de la clase

class Personas {
private:
    Node* front;
    Node* rear;
    int limitePasajeros;
public:
    Personas(int limitePasajeros) : front(nullptr), rear(nullptr), limitePasajeros(limitePasajeros) {}
    Personas();
    // Destructor de la clase
    ~Personas();
    // Declaración de la función que agrega un pasajero a la cola.
    void agregarPasajero(const Pasajero& pasajero);
    // Declaración de la función que elimina un pasajero de la cola.
    void salidaDePasajero();
    // Declaración de la función que muestra el contenido de la cola.
    void display();
    //  Declaración de la función que verifica si la cola está vacía.

    bool isEmpty() const;
    Pasajero getFrontElement() const;
    void iniciarHilosGeneracion();
    void generarYMostrarPasajeros(int cantidadPasajeros);

};
#endif // CASO2_ED_LOBBYESPERA_H
