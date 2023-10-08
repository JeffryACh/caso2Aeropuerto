//
// Created by aquir on 27/9/2023.
//
#include "claseAduana.cpp"
#include "validaciones.cpp"
#include "claseZonas.cpp"
#include "AlmMaleta.cpp"
using namespace std;

// Definición de la clase AduanaMaleta
class AduanaMaleta{
private:
    // Constructor de la clase AduanaMaleta

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
    //Este metodo sirve para obtener el contenido de las maletas
    string* getContenidoMaleta() {
        return this->contenidoMaletas;
    }
    //Este metodo sirve para establecer el contenido de las maletas
    void setContenidoMaleta(string contenidoMaleta[]) {
        for (int i = 0; i < 5; i++) {
            this->contenidoMaletas[i] = contenidoMaleta[i];
        }
    }
    //Este metodo sirve para revisar el contenido de una maleta
    bool revisarMaleta(string contenidoMaleta[5]) {
        return validarContenidoMaleta(contenidoMaleta);
    }
    //Este metodo sirve para establecer la cantidad de maletas revisadas
    void setCantidadMaletasRevisadas(int nuevaCantidad) {
        this->cantMaletasRevisadas = nuevaCantidad;
    }
    //Este metodo sirve para obtener el contenido de las maletas en un formato legible
    string getContenidoBonito() {
        string contenidoStr = "";
        for (int i = 0; i < 5; i++) {
            contenidoStr += this->contenidoMaletas[i];
            contenidoStr += ", ";
        }
        return contenidoStr;
    }

};