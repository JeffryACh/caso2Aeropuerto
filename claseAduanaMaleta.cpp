//
// Created by aquir on 27/9/2023.
//

#include "claseZonas.h"
#include "claseMaletas.h"
#include "AlmMaleta.h"
#include "claseAduanaMaleta.h"
#include "validaciones.h"

AduanaMaleta::AduanaMaleta(AlmacenarMaletas &almacenarMaletas, int capacidad, int cantidadPersonas, int cantidadMaletas,
                           Maleta maletas[], int cantidadMaletasRevisadas, std::string contenidoMaleta[],
                           AlmacenarMaletas &almacenarMaletas1) : almacenarMaletas(almacenarMaletas1) {
    for (int i = 0; i < 5; i++) {
        this->contenidoMaletas[i] = contenidoMaleta[i];
    }
}

// Este método sirve para obtener el contenido de las maletas
std::string* AduanaMaleta::getContenidoMaleta() {
    return this->contenidoMaletas;
}

// Este método sirve para establecer el contenido de las maletas
void AduanaMaleta::setContenidoMaleta(std::string contenidoMaleta[]) {
    for (int i = 0; i < 5; i++) {
        this->contenidoMaletas[i] = contenidoMaleta[i];
    }
}

// Este método sirve para revisar el contenido de una maleta
bool AduanaMaleta::revisarMaleta(std::string contenidoMaleta[5]) {
    return validarContenidoMaleta(contenidoMaleta);
}

// Este método sirve para establecer la cantidad de maletas revisadas
void AduanaMaleta::setCantidadMaletasRevisadas(int nuevaCantidad) {
    this->cantMaletasRevisadas = nuevaCantidad;
}

// Este método sirve para obtener el contenido de las maletas en un formato legible
std::string AduanaMaleta::getContenidoBonito() {
    std::string contenidoStr = "";
    for (int i = 0; i < 5; i++) {
        contenidoStr += this->contenidoMaletas[i];
        contenidoStr += ", ";
    }
    return contenidoStr;
}