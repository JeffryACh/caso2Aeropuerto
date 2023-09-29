#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "claseZonas.cpp"
#include "claseMaletas.cpp"
#include "validaciones.cpp"

using namespace std;

class AduanaPersonas : public Zonas{
    // Atributos específicos de AduanaPersonas
private:
    int capacidad;
    string pCodigo;
    string pPais;
    string pNombre;
    int pEdad;
    bool revisionPersona; // Indica si se ha realizado la revisión de la persona

public:
    // Constructor
    AduanaPersonas(int capacidad, int cantidadPersonas, int cantidadMaletas, Maleta maletas[], int cantidadMaletasRevisadas, bool revisionPersona,string codigo, string pais, string nombre) : Zonas(capacidad, cantidadPersonas, cantidadMaletas) {
        this->revisionPersona = revisionPersona;
    }

    // Métodos específicos de AduanaPersonas
    bool haSidoRevisada() {
        return revisionPersona;
    }

    bool realizarRevision(string pCodigo, string pPais, string pNombre, int pEdad) {
        return validarCodigoPasaporte( pCodigo, pPais,  pNombre,  pEdad);
    }
};

class AduanaMaleta :public Zonas{
    private:
        int cantMaletasRevisadas;
        string contenidoMaletas[5];
        std::vector<Maleta> maletas;
    public:
        AduanaMaleta(int capacidad, int cantidadPersonas, int cantidadMaletas, Maleta maletas[], int cantidadMaletasRevisadas, string contenidoMaleta[]) : Zonas(capacidad, cantidadPersonas, cantidadMaletas){
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