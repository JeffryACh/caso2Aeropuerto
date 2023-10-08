

#include "claseZonas.h"

class Retencion : public Zonas {
private:
    int capacidad;
    int cantidadPersonas;
    int cantidadMaletas;

public:
    Retencion(int capacidad, int cantidadPersonas, int cantidadMaletas);

    int getCapacidad() const;
    int getCantidadPersonas() const;
    int getCantidadMaletas() const;
};

