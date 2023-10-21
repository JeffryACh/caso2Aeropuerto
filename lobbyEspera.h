//
// Created by aquir on 14/10/2023.
//

#ifndef CASO2_ED_LOBBYESPERA_H
#define CASO2_ED_LOBBYESPERA_H

#endif //CASO2_ED_LOBBYESPERA_H
#include <iostream>
#include "clasePasajeros.h"

struct Node {
    Pasajero data;
    Node* next;

    Node(const Pasajero& pasajero);
};
class Personas {
private:
    Node* front;
    Node* rear;

public:
    Personas();
    ~Personas();

    void agregarPasajero(const Pasajero& pasajero);
    void salidaDePasajero();
    void display();
    bool isEmpty() const;
    Pasajero getFrontElement() const;
};