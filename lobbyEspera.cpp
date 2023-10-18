
#include "lobbyEspera.h"
#include "clasePasajeros.h"

Node::Node(const Pasajero& pasajero) : data(pasajero), next(nullptr) {
}

Personas::Personas() : front(nullptr), rear(nullptr) {
}

Personas::~Personas() {
    while (front != nullptr) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

void Personas::agregarPasajero(const Pasajero& pasajero) {
    Node* temp = new Node(pasajero);
    if (front == nullptr) {
        front = temp;
    } else {
        rear->next = temp;
    }
    rear = temp;
}

void Personas::salidaDePasajero() {
    if (front == nullptr) {
        std::cout << "La cola está vacía" << std::endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }
    }
}

void Personas::display() {
    if (front == nullptr) {
        std::cout << "La cola está vacía" << std::endl;
    } else {
        Node* temp = front;

        while (temp != nullptr) {
            std::cout << temp->data.getNombre() << std::endl;
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}

bool Personas::isEmpty() const {
    return front == nullptr;
}

Pasajero Personas::getFrontElement() const {
    if (isEmpty()) {
        std::cout << "La cola está vacía" << std::endl;
    } else {
        return front->data;
    }
}