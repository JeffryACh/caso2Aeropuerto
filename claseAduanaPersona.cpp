//
// Created by aquir on 27/9/2023.
//
#include "claseAduana.cpp"
#include "validaciones.cpp"
using namespace std;

class AduanaPersonas : public Aduanas {
    // Atributos específicos de AduanaPersonas
private:

    string pCodigo;
    string pPais;
    string pNombre;
    int pEdad;
    bool revisionPersona; // Indica si se ha realizado la revisión de la persona

public:
    // Constructor
    AduanaPersonas(int capacidad, int cantidadPersonas, int cantidadMaletas, Maleta maletas[], int cantidadMaletasRevisadas, bool revisionPersona,string codigo, string pais, string nombre) : Aduanas(capacidad, cantidadPersonas, cantidadMaletas, maletas, cantidadMaletasRevisadas) {
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