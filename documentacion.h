/*
    * Caso2 - Preliminar 1
    * Author: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 11/09/2023 17:40
*/

// *Caso 2 - Preliminar 1

/*
    * Lista doblemente enlazada con los objetos y structs de los pasajeros, maletas y pasaportes
    * Colas: 
    *   - Cola de entrada de pasajeros
    *   - Cola de aduanas (maletas y pasaportes)
    *   - Cola de lobby de espera
    *   - Cola de checking
    * Pilas:
    *   - Pila de almacenamiento de maletas
    *   - Pila de resepccion de maletas
    * Threads:
    *   - 1 thread por cada pasajero
    * Clases o structs para guardar info:
    *   - Pasajero (Clase[Nombre, Edad, Pasaporte, Nacionalidad, Sexo, Maleta]])
    *   - Maleta (Struct[Peso, Descripcion, Propietario, Contenido])
    *   - Pasaporte (Struct[Codigo, Nacionalidad, Sexo])
    * Clases para controlar la configuracion:
    *   - ConfiguracionGeneral (ClasePadre[Pasajeros, Maletas])
    *   - ConfigLobbys (ClaseHija[Capacidad, Cantidad])
    *   - ConfigAduanas (ClaseHija[Capacidad, Cantidad])
    *   - ConfigCheckings (ClaseHija[Capacidad, Cantidad])
    * Clases de logica y reglas:
    *   - Validaciones (Clase[ValidarCodigoPasaporte, ValidarContenidoMaleta])
    *   - Hilos (Clase[CrearHilos])
    *   - Colas (Clase[CrearColas])
    *   - Pilas (Clase[CrearPilas])
    * Clases para mostrar la simulacion:
    *   - Simulacion (Clase[MostrarSimulacion])
    *   - Estadisticas (Clase[MostrarEstadisticas])
    * Las alertas que tenga la simulacion se pueden mostrar con uno o varios couts
*/  
