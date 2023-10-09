/*
    * Caso2: Aeropuerto
    * Authors: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 08/10/2021 17:20
*/

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

/**
 * La clase AduanaMaleta representa una aduana de revisión de maletas en un aeropuerto.
 * Esta clase tiene la capacidad de revisar el contenido de las maletas y almacenarlas en un vector.
 * Además, se puede obtener el contenido de las maletas de manera legible y se puede modificar el contenido de las mismas.
 */
class AduanaMaleta {
private:
    int cantMaletasRevisadas;
    std::string contenidoMaletas[5];
    std::vector<Maleta> maletas;
    AlmacenarMaletas &almacenarMaletas;

public:
    /**
     * Constructor de la clase AduanaMaleta.
     * @param almacenarMaletas Objeto de la clase AlmacenarMaletas que se encarga de almacenar las maletas revisadas.
     * @param capacidad Capacidad máxima de la aduana.
     * @param cantidadPersonas Cantidad de personas que pueden pasar por la aduana.
     * @param cantidadMaletas Cantidad de maletas que pueden pasar por la aduana.
     * @param maletas Arreglo de objetos de la clase Maleta que se van a revisar.
     * @param cantidadMaletasRevisadas Cantidad de maletas que ya han sido revisadas.
     * @param contenidoMaleta Arreglo de strings que representa el contenido de las maletas.
     * @param almacenarMaletas1 Objeto de la clase AlmacenarMaletas que se encarga de almacenar las maletas revisadas.
     */
    AduanaMaleta(AlmacenarMaletas &almacenarMaletas, int capacidad, int cantidadPersonas, int cantidadMaletas,
                 Maleta maletas[], int cantidadMaletasRevisadas, std::string contenidoMaleta[],
                 AlmacenarMaletas &almacenarMaletas1);

    /**
     * Método que devuelve el contenido de las maletas.
     * @return Arreglo de strings que representa el contenido de las maletas.
     */
    std::string* getContenidoMaleta();

    /**
     * Método que modifica el contenido de las maletas.
     * @param contenidoMaleta Arreglo de strings que representa el nuevo contenido de las maletas.
     */
    void setContenidoMaleta(std::string contenidoMaleta[]);

    /**
     * Método que revisa el contenido de una maleta.
     * @param contenidoMaleta Arreglo de strings que representa el contenido de la maleta a revisar.
     * @return True si la maleta es segura, false si no lo es.
     */
    bool revisarMaleta(std::string contenidoMaleta[5]);

    /**
     * Método que modifica la cantidad de maletas revisadas.
     * @param nuevaCantidad Nueva cantidad de maletas revisadas.
     */
    void setCantidadMaletasRevisadas(int nuevaCantidad);

    /**
     * Método que devuelve el contenido de las maletas de manera legible.
     * @return String que representa el contenido de las maletas de manera legible.
     */
    std::string getContenidoBonito();
};

#endif // ADUANAMALETAS_H