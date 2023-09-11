#include <iostream>
#include <thread>

using namespace std;

// Struct pasaporte
struct Pasaporte{
    string codigo; //tiene que ser unico y iniciar con las primeras 3 letras del pais y luego 3 letras del nombre y luego la edad del pasajero y por ultimo 6 numeros aleatorios
    string nacionalidad; 
    string sexo;
};

// Struct maleta
struct Maleta
{
    int peso;
    string descripcion;
    string propietario; //nombre del pasajero
    string contenido[5]; //arreglo de strings con el contenido de la maleta
};


// Clase Pasajero
class Pasajero{
    // Atributos
    private:
        string nombre; //nombre del pasajero solo el primer nombre
        int edad;
        Pasaporte pasaporte; //viene de la estructura pasaporte de arriba
        string nacionalidad;
        string sexo;
        Maleta maleta; //viene de la estructura maleta de arriba

    
    // Constructor
    public:
        Pasajero(string nombre, int edad, Pasaporte pasaporte, string nacionalidad, string sexo, Maleta maleta){
            this->nombre = nombre;
            this->edad = edad;
            this->pasaporte = pasaporte;
            this->nacionalidad = nacionalidad;
            this->sexo = sexo;
            this->maleta = maleta;
        }
    
    // Metodos
    public:
        void mostrarDatos(){
            cout << "Nombre: " << nombre << endl;
            cout << "Edad: " << edad << endl;
            cout << "Pasaporte: " << pasaporte.codigo << endl;
            cout << "Nacionalidad: " << nacionalidad << endl;
            cout << "Sexo: " << sexo << endl;
            cout << "Maleta: " << maleta.descripcion << endl;
        }

        // Getters
        string getNombre(){
            return nombre;
        }

        int getEdad(){
            return edad;
        }

        string getPasaporte(){
            return pasaporte.codigo;
        }

        string getNacionalidad(){
            return nacionalidad;
        }

        string getSexo(){
            return sexo;
        }

        string getMaleta(){
            return maleta.descripcion;
        }

        string getContenidoMaleta(){
            string contenido = "";
            for (int i = 0; i < sizeof(maleta.contenido); i++)
            {
                contenido += maleta.contenido[i];
                contenido += ", ";
            }
            return contenido;
        }
};