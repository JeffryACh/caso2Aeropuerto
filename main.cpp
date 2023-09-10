/*
    * Caso2 - Preliminar 1
    * Author: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on: 10/09/2021 15:35
*/

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "claseHilos.cpp"

using namespace std;

int main(){
    MyThread myThread; // Se crea una instancia de la clase MyThread

    myThread.start(); // Se inicia el hilo

    this_thread::sleep_for(chrono::milliseconds(5000)); // Se duerme el hilo principal por 5 segundo

    cout << "Hello from main!" << endl; // Se imprime un mensaje desde el hilo principal

    return 0;
}