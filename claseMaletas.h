//
// Created by aquir on 8/10/2023.
//

#ifndef CASO2_ED_CLASEMALETAS_H
#define CASO2_ED_CLASEMALETAS_H

#endif //CASO2_ED_CLASEMALETAS_H
#ifndef MALETA_H
#define MALETA_H

#include <string>
#include <vector>

class Maleta {
private:
    int peso;
    std::string descripcion;
    std::string propietario;
    std::vector<std::string> contenido;

public:
    Maleta(int peso, const std::string& descripcion, const std::string& propietario, const std::vector<std::string>& contenido);

    int getPeso() const;
    std::string getDescripcion() const;
    std::string getPropietario() const;
    std::string getContenido() const;
};

#endif // MALETA_H