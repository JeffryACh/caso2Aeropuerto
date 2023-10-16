/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 08/10/2021 17:20
*/

#ifndef CASO2_ED_CLASEMALETAS_H
#define CASO2_ED_CLASEMALETAS_H

#endif //CASO2_ED_CLASEMALETAS_H
#ifndef MALETA_H
#define MALETA_H

#include <string>
#include <vector>

/**
 * @brief Clase que representa una maleta
 * 
*/
class Maleta {
private:
    int peso;
    std::string descripcion;
    std::string propietario;
    std::vector<std::string> contenido;

public:
    /**
     * @brief Constructor de la clase Maleta
     * 
     * @param peso Peso de la maleta
     * @param descripcion Descripción de la maleta
     * @param propietario Propietario de la maleta
     * @param contenido Vector con el contenido de la maleta
    */
    Maleta(int peso, const std::string descripcion, const std::string propietario, const std::vector<std::string> contenido);

    /**
     * @brief Retorna el peso de la maleta.
     * 
     * @return int Peso de la maleta.
    */
    int getPeso() const;
    /**
     * @brief Retorna la descripción de la maleta.
     * 
     * @return std::string Descripción de la maleta.
    */
    std::string getDescripcion() const;
    /**
     * @brief Retorna el propietario de la maleta.
     * 
     * @return std::string Propietario de la maleta.
    */
    std::string getPropietario() const;
    /**
     * @brief Retorna el contenido de la maleta como una cadena de texto.
     * 
     * @return std::string Cadena de texto con el contenido de la maleta.
    */
    std::string getContenido() const;
};

#endif // MALETA_H