#include <iostream>
#include <pthread.h>
#include <errno.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;

void* hilo(void*);

int main() {
    pthread_t ph_hilo1;

    if (pthread_create(&ph_hilo1, nullptr, hilo, nullptr) != 0) {
        cerr << "No se pudo crear el hilo" << errno << endl;
        _exit(1);
    }

    void *valRet;

    if (pthread_join(ph_hilo1, &valRet) != 0) {
        cerr << "Error:" << errno << endl;
        _exit(1);
    }
    else {
        cout << "proccess successfull" << endl;
    }

    return 0;
}

void* hilo(void *arg) {
    cout << "Mi primer hilo!!!" << endl;
    return nullptr;
}
