
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
void Personas::generarYMostrarPasajeros(int cantidadPasajeros) {
    // Lógica para generar y mostrar pasajeros
    for (int i = 0; i < cantidadPasajeros; i++) {
        // Genera y muestra un pasajero
        std::cout << "Pasajero generado en el hilo " << std::this_thread::get_id() << std::endl;
    }
}

void Personas::iniciarHilosGeneracion() {
    std::vector<std::thread> hilosGeneracion;

    // Crear hilos para la generación de pasajeros
    for (int i = 0; i < limitePasajeros; ++i) {
        hilosGeneracion.emplace_back(&Personas::generarYMostrarPasajeros, this, 1);
    }

    // Esperar a que todos los hilos terminen
    for (auto& thread : hilosGeneracion) {
        thread.join();
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


