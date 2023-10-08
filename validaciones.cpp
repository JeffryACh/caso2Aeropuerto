/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 10/09/2021 15:35
*/

#include <iostream>
#include <string>
#include "validaciones.h"
using namespace std;

/*
    Funcion que valida que el codigo de pasaporte sea correcto
    Parametros: string pCodigo, string pPais, string pNombre, int pEdad
    Retorno: bool
*/
bool validarCodigoPasaporte(std::string pCodigo, std::string pPais, std::string pNombre, int pEdad){
    if(pCodigo.length() != 11){
        return false;
    }

    if(pCodigo.substr(0,3) != pPais){
        return false;
    }

    if(pCodigo.substr(3,3) != pNombre){
        return false;
    }

    if(pCodigo.substr(6,2) != to_string(pEdad)){
        return false;
    }
    
    for (int i = 8; i < 14; i++){ //verifica que los ultimos 6 caracteres sean numeros
        if (!isdigit(pCodigo[i])){
            return false;
        }
    }

    return true;
}

/*
    Funcion que valida que el contenido de la maleta sea correcto
    Parametros: string pContenido[]
    Retorno: bool
*/
bool validarContenidoMaleta(std::string pContenido[]){
    for (int i = 0; i < 5; i++){
        if(pContenido[i] == "Pistola" || pContenido[i] == "Cuchillo" || pContenido[i] == "Explosivos" || pContenido[i] == "Quimicos peligrosos" || pContenido[i] == "Drogas"){
            return false;
        }
    }
    return true;
}