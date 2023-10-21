/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 08/10/2021 17:20
*/

#include "ListaPasajeroMaleta.h"
// Se usara para el entregable final


ListaDoblePasajero::ListaDoblePasajero() { //Constructor de la lista doble.
    primerNodo = NULL;
}

/**
 * @brief Destructor de la lista doble de pasajeros.
 * 
 * Elimina todos los nodos de la lista doble de pasajeros.
 * 
 */

ListaDoblePasajero::~ListaDoblePasajero(){ // Destructor de la lista doble.
    ListaDoblePasajero* aux;
    while(primerNodo){
        aux = primerNodo;
        primerNodo = primerNodo -> siguiente;
        delete aux;
    }
}


int ListaDoblePasajero::largoLista() {
    // Explicacion:
    // Este metodo se encarga de recorrer la lista  desde el primer elemento de la lista hasta
    // el ultimo elemento realizandolo a traves de los nodos.
    int contador=0;
    ListaDoblePasajero*aux=primerNodo;
    if(listaVacia()){
        return contador;
    }
    else{
        while(aux !=nullptr){
            aux=aux->siguiente;
            contador++;
        }
        return contador;
    }
}

/**
 * @brief Muestra la lista doble de pasajeros.
 * 
 */

void ListaDoblePasajero::mostrar() {
    // Explicacion:
    //
    ListaDoblePasajero* actual = primerNodo;
    while (actual) {
        cout << "Pasajero: " << actual->pasajero.getNombre() << endl;
        cout << "Pasaporte: " << actual->pasaporte.codigo << endl;
        actual = actual->siguiente;
    }
}

/**
 * @brief Inserta un nodo al final de la lista doble de pasajeros.
 * 
 * @param pasaporte Pasaporte del pasajero.
 * @param nacion Nacionalidad del pasajero.
 * @param pasajero Nombre del pasajero.
 */

void ListaDoblePasajero::insertarFinal(Pasajero pasajero) {
    // Explicacion:
    //
    ListaDoblePasajero* nuevoNodo = new ListaDoblePasajero(pasajero);
    if (!primerNodo) {
        primerNodo = nuevoNodo;
    } else {
        ListaDoblePasajero* temp = primerNodo;
        while (temp->siguiente) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
        nuevoNodo->anterior = temp;
    }
}

/**
 * @brief Busca un nodo en la lista doble de pasajeros.
 * 
 * @param pasaporte Pasaporte del pasajero.
 * @return ListaDoblePasajero* Nodo encontrado.
 */

ListaDoblePasajero* ListaDoblePasajero::buscarPasaporte(Pasaporte pasaporte) {
    ListaDoblePasajero*aux=primerNodo;
    while (aux) {
        if (aux->pasaporte.codigo() == pasaporte.codigo())
            return aux;
        aux = aux->siguiente;
    }
    return 0;
}

/**
 * @brief Elimina un nodo de la lista doble de pasajeros.
 * 
 * @param pasaporte Pasaporte del pasajero.
 */

void ListaDoblePasajero::Borrar(Pasaporte pasaporte) {
    // Verificar si la lista está vacía
    if (listaVacia()) {
        cout << "La lista está vacía. No se puede eliminar." << endl;
        return;
    }
    ListaDoblePasajero* actual = primerNodo;
    ListaDoblePasajero* anterior = nullptr;
    bool encontrado = false;
    // Buscar el nodo con el pasaporte dado
    while (actual != nullptr) {
        if (actual->pasaporte.codigo() == pasaporte.codigo()) {
            encontrado = true;
            break;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    if (!encontrado) {
        cout << "Pasaporte no encontrado en la lista." << endl;
        return;
    }
    // Si el nodo a borrar es el primer nodo
    if (actual == primerNodo) {
        primerNodo = actual->siguiente;
        if (primerNodo != nullptr) {
            primerNodo->anterior = nullptr;
        }
        delete actual;
    } else {
        // Si el nodo a borrar no es el primer nodo
        anterior->siguiente = actual->siguiente;
        if (actual->siguiente != nullptr) {
            actual->siguiente->anterior = anterior;
        }
        delete actual;
    }
    cout << "Pasaporte eliminado: " << pasaporte.codigo() << endl;
}

/**
 * @brief Constructor de la lista doble de maletas.
 * 
 */

listaDobleMaleta::listaDobleMaleta() { //Constructor de la lista doble.
    segundoNodo = NULL;
}

/**
 * @brief Destructor de la lista doble de maletas.
 * 
 * Elimina todos los nodos de la lista doble de maletas.
 * 
 */

listaDobleMaleta::~listaDobleMaleta(){ // Destructor de la lista doble.
    listaDobleMaleta* aux;
    while(segundoNodo){
        aux = segundoNodo;
        segundoNodo = segundoNodo -> siguiente;
        delete aux;
    }
}

/**
 * @brief Retorna el largo de la lista doble de maletas.
 * 
 * @return int Largo de la lista doble de maletas.
 */

int listaDobleMaleta::largoLista() {
    // Explicacion:
    // Este metodo se encarga de recorrer la lista  desde el primer elemento de la lista hasta
    // el ultimo elemento realizandolo a traves de los nodos.
    int contador=0;
    listaDobleMaleta*aux=segundoNodo;
    if(listaVacia()){
        return contador;
    }
    else{
        while(aux !=nullptr){
            aux=aux->siguiente;
            contador++;
        }
        return contador;
    }
}

/**
 * @brief Muestra la lista doble de maletas.
 * 
 */

void listaDobleMaleta::mostrar() {
    // Explicacion:
    //
    listaDobleMaleta* actual = segundoNodo;
    while (actual) {
        cout << "Maleta: " << actual->maleta.getDescripcion() << endl;
        cout << "Contenido: " << actual->maleta.getContenido() << endl;
        actual = actual->siguiente;
    }
}

/**
 * @brief Inserta un nodo al final de la lista doble de maletas.
 * 
 * @param contMaleta Contenido de la maleta.
 * @param colorMaleta Color de la maleta.
 */

void listaDobleMaleta::insertarFinal(Maleta maleta) {
    // Explicacion:
    //
    listaDobleMaleta* nuevoNodo = new listaDobleMaleta(maleta);
    if (!segundoNodo) {
        segundoNodo = nuevoNodo;
    } else {
        listaDobleMaleta* temp = segundoNodo;
        while (temp->siguiente) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
        nuevoNodo->anterior = temp;
    }
}

/**
 * @brief Busca un nodo en la lista doble de maletas.
 * 
 * @param colorMaleta Color de la maleta.
 * @return listaDobleMaleta* Nodo encontrado.
 */

listaDobleMaleta * listaDobleMaleta::buscarMaleta(maleta) {
    listaDobleMaleta*aux=segundoNodo;
    while (aux) {
        if (aux->maleta.getDescripcion() == maleta.getDescripcion())
            return aux;
        aux = aux->siguiente;
    }
    return 0;
}

/**
 * @brief Elimina un nodo de la lista doble de maletas.
 * 
 * @param colorMaleta Color de la maleta.
 */

void listaDobleMaleta::Borrar(Maleta maleta) {
    // Verificar si la lista está vacía
    if (listaVacia()) {
        cout << "La lista está vacía. No se puede eliminar." << endl;
        return;
    }
    listaDobleMaleta* actual = segundoNodo;
    listaDobleMaleta* anterior = nullptr;
    bool encontrado = false;
    // Buscar el nodo con el color de maleta dado
    while (actual != nullptr) {
        if (actual->maleta.getDescripcion() == maleta.getDescripcion()) {
            encontrado = true;
            break;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    if (!encontrado) {
        cout << "Color de maleta no encontrado en la lista." << endl;
        return;
    }
    // Si el nodo a borrar es el segundo nodo
    if (actual == segundoNodo) {
        segundoNodo = actual->siguiente;
        if (segundoNodo != nullptr) {
            segundoNodo->anterior = nullptr;
        }
        delete actual;
    } else {
        // Si el nodo a borrar no es el segundo nodo
        anterior->siguiente = actual->siguiente;
        if (actual->siguiente != nullptr) {
            actual->siguiente->anterior = anterior;
        }
        delete actual;
    }
    cout << maleta.getPropietario() << endl;
} 