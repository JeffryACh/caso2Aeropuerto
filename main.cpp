/*
    * Caso2 - Preliminar 1
    * Author: Jeffry Araya Ch y Andres Quiros P.
    * Created on: 06/09/2023 09:00
    * Last modified on:
*/

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

void printHello(){
    cout << "Hello from thread" << endl;
}

int main(){
    thread th1(printHello);
    th1.join();
    chrono::milliseconds dura(10000);
    cout << "Hello World" << endl;
    return 0;
}