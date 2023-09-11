#include <iostream>
#include <string>
#include "claseHilos.cpp"

using namespace std;

bool validarCodigoPasaporte(string pCodigo, string pPais, string pNombre, int pEdad){
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

bool validarContenidoMaleta(string pContenido[]){
    for (int i = 0; i < 5; i++){
        if(pContenido[i] == "Pistola" || pContenido[i] == "Cuchillo" || pContenido[i] == "Explosivos" || pContenido[i] == "Quimicos peligrosos" || pContenido[i] == "Drogas"){
            return false;
        }
    }
    return true;
}