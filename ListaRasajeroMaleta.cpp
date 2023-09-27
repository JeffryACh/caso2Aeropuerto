//
// Created by aquir on 23/9/2023.
//

#include "ListaRasajeroMaleta.h"

//*********************************************************************************
// Metodos de la Lista Doble de Pasajeros
//*********************************************************************************
ListaDoblePasajero::ListaDoblePasajero() { //Constructor de la lista doble.
    primerNodo = NULL;
}

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
void ListaDoblePasajero::mostrar() {
    // Explicacion:
    //
    ListaDoblePasajero* actual = primerNodo;
    while (actual) {
        cout << "Pasajero: " << actual->pasajero << endl;
        cout << "Pasaporte: " << actual->pasaporte << endl;
        cout << "Nacionalidad: " << actual->nacion << endl;
        actual = actual->siguiente;
    }
}
void ListaDoblePasajero::insertarFinal(string pasaporte,string nacion,string pasajero) {
    // Explicacion:
    //
    ListaDoblePasajero* nuevoNodo = new ListaDoblePasajero(pasaporte,nacion,pasajero);
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
ListaDoblePasajero* ListaDoblePasajero::buscarPasaporte(string pasaporte) {
    ListaDoblePasajero*aux=primerNodo;
    while (aux) {
        if (aux->pasaporte == pasaporte)
            return aux;
        aux = aux->siguiente;
    }
    return 0;
}
void ListaDoblePasajero::Borrar(string pasaporte) {
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
        if (actual->pasaporte == pasaporte) {
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
    cout << "Pasaporte eliminado: " << pasaporte << endl;
}


//*********************************************************************************
// Metodos de la Lista Doble de Maletas
//*********************************************************************************

listaDobleMaleta::listaDobleMaleta() { //Constructor de la lista doble.
    segundoNodo = NULL;
}

listaDobleMaleta::~listaDobleMaleta(){ // Destructor de la lista doble.
    listaDobleMaleta* aux;
    while(segundoNodo){
        aux = segundoNodo;
        segundoNodo = segundoNodo -> siguiente;
        delete aux;
    }
}
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
void listaDobleMaleta::mostrar() {
    // Explicacion:
    //
    listaDobleMaleta* actual = segundoNodo;
    while (actual) {
        cout << "Contenido de la maleta: " << actual->contMaleta << endl;
        cout << "Color de la maaleta: " << actual->colorMaleta << endl;
        actual = actual->siguiente;
    }
}
void listaDobleMaleta::insertarFinal(string contMaleta,string colorMaleta) {
    // Explicacion:
    //
    listaDobleMaleta* nuevoNodo = new listaDobleMaleta(contMaleta,colorMaleta);
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
listaDobleMaleta * listaDobleMaleta::buscarMaleta(string colorMaleta) {
    listaDobleMaleta*aux=segundoNodo;
    while (aux) {
        if (aux->colorMaleta == colorMaleta)
            return aux;
        aux = aux->siguiente;
    }
    return 0;
}
void listaDobleMaleta::Borrar(string colorMaleta) {
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
        if (actual->colorMaleta == colorMaleta) {
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
    cout << "Color de maleta eliminado: " << colorMaleta << endl;
}