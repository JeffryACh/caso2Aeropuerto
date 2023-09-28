//
// Created by aquir on 27/9/2023.
//
#include "claseAduana.cpp"
#include "validaciones.cpp"
#include "claseZonas.cpp"
using namespace std;

class AduanaMaleta :public Aduanas{
private:

    int cantMaletasRevisadas;
    string contenidoMaletas[5] ;
    std::vector<Maleta> maletas;
public:
    AduanaMaleta(int capacidad, int cantidadPersonas, int cantidadMaletas, Maleta maletas[], int cantidadMaletasRevisadas, string contenidoMaleta[]) : Aduanas(capacidad, cantidadPersonas, cantidadMaletas, maletas, cantidadMaletasRevisadas) {
        // Inicializar el atributo contenidoMaleta
        for (int i = 0; i < 5; i++) {
            this->contenidoMaletas[i] = contenidoMaleta[i];
        }
    }
    string* getContenidoMaleta() {
        return this->contenidoMaletas;
    }

    void setContenidoMaleta(string contenidoMaleta[]) {
        // Copiar el contenido del nuevo vector al atributo contenidoMaleta
        for (int i = 0; i < 5; i++) {
            this->contenidoMaletas[i] = contenidoMaleta[i];
        }
    }
    bool revisarMaleta(string contenidoMaleta[5]) {
        // Utilizar la función validarContenidoMaleta para verificar el contenido
        return validarContenidoMaleta(contenidoMaleta);
    }
    void setCantidadMaletasRevisadas(int nuevaCantidad) {
        this->cantMaletasRevisadas = nuevaCantidad;
    }

    string getContenidoBonito() {
        string contenidoStr = "";
        for (int i = 0; i < 5; i++) {
            contenidoStr += this->contenidoMaletas[i];
            contenidoStr += ", ";
        }
        return contenidoStr;
    }

};