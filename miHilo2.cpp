#include <iostream>
#include <pthread.h>
#include <errno.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;

void* thread(void*);

const int N = 5;
const char *messages[N] = {"Hablalo", "Ladralo", "Mi padre", "Amen", "Cuchito"};

int main() {
    pthread_t ph_thread[N];

    for (int i = 0; i < N; i++) {
        if (pthread_create(&ph_thread[i], nullptr, thread, (void *) messages[i]) != 0) {
            cerr << "Unexpected error creating the thread" << errno << endl;
            _exit(1);
        }
    }

    for (int i = 0; i < N; i++) {
        void *valRet;

        if (pthread_join(ph_thread[i], &valRet) != 0) {
            cerr << "Unexpected error waiting for thread" << errno << endl;
            _exit(1);
        }

        else {
            cout << i << endl;
        }
    }

    return 0;
}

void* thread(void *arg) {
    const char *message = (const char*) arg;
    char *newMessage = new char[strlen(message) + 1];
    cout << message << endl;

    int i;
    for (i = 0; message[i]; i++)
        newMessage[i] = message[i] != ' ' ? message[i]: '/';

    newMessage[i] = '\0';

    return newMessage;
}
