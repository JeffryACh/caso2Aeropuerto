#include <iostream>
#include <thread>

using namespace std;

class MyThread {
public:
    void start() {
        thread t(&MyThread::run, this); // Se crea un hilo que ejecuta el método run() de esta clase
        t.detach();
    }

private:
    void run() {
        // Aquí va el código que se ejecutará en el hilo
        cout << "Hello from thread!" << endl;
    }
};