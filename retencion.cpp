/*

*/

#include "claseZonas.cpp"
#include "claseMaletas.cpp"
#include "clasePasajeros.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Retencion : public Zonas{
private:
    vector<Maleta> maletas;
    vector<Pasajero> pasajeros;

public:
    // Constructor
    Retencion(int capacidad, int cantidadPersonas, int cantidadMaletas, Maleta maleta, Pasajero pasajero) : Zonas(capacidad, cantidadPersonas, cantidadMaletas) {
        this->maletas.push_back(maleta);
        this->pasajeros.push_back(pasajero);
    };
    
    // Mandar a la carcel
    void mandarALaCarcel(){
        for (int i = 0; i < this->pasajeros.size(); i++) {
            cout << "Mandando a la carcel a " << this->pasajeros[i].getNombre() << endl;
            pasajeros.erase(pasajeros.begin() + i);
            maletas.erase(maletas.begin() + i);
        }
    }
};