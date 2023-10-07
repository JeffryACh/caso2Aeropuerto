//
// Created by aquir on 27/9/2023.
//
#include "claseAduanaPersonas.cpp"
#include "validaciones.cpp"
#include "claseZonas.cpp"
#include "AlmMaleta.cpp"
using namespace std;

class AduanaMaleta{
private:

    int cantMaletasRevisadas;
    string contenidoMaletas[5] ;
    std::vector<Maleta> maletas;
    AlmacenarMaletas &almacenarMaletas;
public:
    AduanaMaleta(AlmacenarMaletas &almacenarMaletas, int capacidad, int cantidadPersonas, int cantidadMaletas,
                 Maleta maletas[], int cantidadMaletasRevisadas, string contenidoMaleta[],
                 AlmacenarMaletas &almacenarMaletas1) : almacenarMaletas(almacenarMaletas1) {
        for (int i = 0; i < 5; i++) {
            this->contenidoMaletas[i] = contenidoMaleta[i];
        }
    }
    string* getContenidoMaleta() {
        return this->contenidoMaletas;
    }

    void setContenidoMaleta(string contenidoMaleta[]) {
        for (int i = 0; i < 5; i++) {
            this->contenidoMaletas[i] = contenidoMaleta[i];
        }
    }
    bool revisarMaleta(string contenidoMaleta[5]) {
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