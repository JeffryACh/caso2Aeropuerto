//
// Created by aquir on 8/10/2023.
//

#ifndef CASO2_ED_ALMMALETA_H
#define CASO2_ED_ALMMALETA_H

#endif //CASO2_ED_ALMMALETA_H
#ifndef ALMACENARMALETAS_H
#define ALMACENARMALETAS_H

#include <iostream>
#include <stack>
#include <string>

class Maletas {
public:
    Maletas(std::string& identificacionMaleta);
    std::string getIdent();
private:
    std::string idMaleta;
};

class AlmacenarMaletas {
public:
    void agregarMaleta(Maletas id);
    void retirarMaleta();
    void mostrarCantidadMaletas() const;
private:
    std::stack<Maletas> pilaMaletas;
};

#endif // ALMACENARMALETAS_H