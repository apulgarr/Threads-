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
    pthread_join(ph_hilo1, &valRet);

    return 0;
}

void* hilo(void *arg) {
    cout << "Mi primer hilo!!!" << endl;
    return nullptr;
}
