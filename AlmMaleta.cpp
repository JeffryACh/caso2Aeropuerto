//
// Created by aquir on 30/9/2023.
//



#include <iostream>
#include <stack>
#include <string>

class Maletas{
public:
    Maletas(std::string& identificacionMaleta){
        this->idMaleta=identificacionMaleta;


    }
    std::string getIdent(){
        return idMaleta;

    }
private:

    std::string idMaleta;
};
class AlmacenarMaletas{
public:
    void agregarMaleta(Maletas id) {
        Maletas maletas(id);
        pilaMaletas.push(maletas);
    }

    void retirarMaleta() {
        if (!pilaMaletas.empty()) {
            std::cout << "Retirando maleta con ID: " << pilaMaletas.top().getIdent() << std::endl;
            pilaMaletas.pop();
        } else {
            std::cout << "No hay maletas en el almacenamiento." << std::endl;
        }
    }

    void mostrarCantidadMaletas() const {
        std::cout << "Cantidad de maletas en el almacenamiento: " << pilaMaletas.size() << std::endl;
    }

private:
    std::stack<Maletas> pilaMaletas;
};