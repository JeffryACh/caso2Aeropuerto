#include <iostream>
#include <string>
#include <vector>
#include "claseZonas.cpp"
#include "claseMaletas.cpp"

using namespace std;

class Aduanas : public Zonas{
    // Atributos
    private:
        int capacidad;
        int cantidadPersonas;
        int cantidadMaletas;
        Maleta* maletas[];
    public:
        // Constructor
        Aduanas(int capacidad, int cantidadPersonas, int cantidadMaletas, Maleta maletas[]) : Zonas(capacidad, cantidadPersonas, cantidadMaletas){
            this->capacidad = capacidad;
            this->cantidadPersonas = cantidadPersonas;
            this->cantidadMaletas = cantidadMaletas;
            *this->maletas = maletas;
        }

        // Metodos
        // Getters y setters
        int getCapacidad(){
            return this->capacidad;
        }

        int getCantidadPersonas(){
            return this->cantidadPersonas;
        }

        Maleta* getMaletas(){
            return *this->maletas;
        }

        int getCantidadMaletas(){
            return this->cantidadMaletas;
        }

        void setCantidadPersonas(int nuevaCantidad){
            this->cantidadPersonas = nuevaCantidad;
        }

        void setCantidadMaletas(int nuevaCantidad){
            this->cantidadMaletas = nuevaCantidad;
        }

        void setMaletas(Maleta maletas[]){
            *this->maletas = maletas;
        }
};