//
// Created by aquir on 8/10/2023.
//

#ifndef CASO2_ED_CLASEADUANAMALETA_H
#define CASO2_ED_CLASEADUANAMALETA_H

#endif //CASO2_ED_CLASEADUANAMALETA_H
#ifndef ADUANAMALETAS_H
#define ADUANAMALETAS_H
#include "claseAduanaPersonas.h"
#include "validaciones.h"
#include "claseZonas.h"
#include "AlmMaleta.h"
#include <vector>
#include <string>

class AduanaMaleta {
private:
    int cantMaletasRevisadas;
    std::string contenidoMaletas[5];
    std::vector<Maleta> maletas;
    AlmacenarMaletas &almacenarMaletas;

public:
    AduanaMaleta(AlmacenarMaletas &almacenarMaletas, int capacidad, int cantidadPersonas, int cantidadMaletas,
                 Maleta maletas[], int cantidadMaletasRevisadas, std::string contenidoMaleta[],
                 AlmacenarMaletas &almacenarMaletas1);

    std::string* getContenidoMaleta();
    void setContenidoMaleta(std::string contenidoMaleta[]);
    bool revisarMaleta(std::string contenidoMaleta[5]);
    void setCantidadMaletasRevisadas(int nuevaCantidad);
    std::string getContenidoBonito();
};

#endif // ADUANAMALETAS_H