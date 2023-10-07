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

