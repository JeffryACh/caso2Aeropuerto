//
// Created by aquir on 30/9/2023.
//



#include <iostream>
#include <stack>
#include <string>
// Definición de la clase Maletas
class Maletas{
public:
    // Constructor de la clase Maletas que recibe una identificación de maleta

    Maletas(std::string& identificacionMaleta){
        this->idMaleta=identificacionMaleta;


    }
    std::string getIdent(){
        return idMaleta;

    }
private:

    std::string idMaleta;// Miembro privado (IdMaleta) que sirve para almacenar la identificación de la maleta
};
class AlmacenarMaletas{
public:
    // Este metodo se encarga de agregar una maleta al almacenamiento.
    void agregarMaleta(Maletas id) {
        Maletas maletas(id);// Instancia de maletas
        pilaMaletas.push(maletas);// Se agrega la maleta a la pila
    }
    // Este método se encarga de retirar una maleta del almacenamiento
    void retirarMaleta() {
        if (!pilaMaletas.empty()) {
            std::cout << "Retirando maleta con ID: " << pilaMaletas.top().getIdent() << std::endl;
            pilaMaletas.pop();// Se saca la maleta de la pila
        } else {
            std::cout << "No hay maletas en el almacenamiento." << std::endl;
        }
    }
    // Este método se encarga de mostrar la cantidad de maletas en el almacenamiento
    void mostrarCantidadMaletas() const {
        std::cout << "Cantidad de maletas en el almacenamiento: " << pilaMaletas.size() << std::endl;
    }

private:
    std::stack<Maletas> pilaMaletas;//Pila de objetos Maletas para almacenar las maletas
};