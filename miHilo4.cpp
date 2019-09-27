#include <iostream>
#include <pthread.h>
#include <errno.h>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

using namespace std;

void* thread(void*);

const int N = 5;
int var = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main() {
	pthread_t ph_thread[N];

	for (int i = 0; i < N; i++) {
		if(pthread_create(&ph_thread[i], nullptr, thread, nullptr) != 0) {
			cout << "Error creating the current thread" << errno << endl;
			_exit(1);
		}
	}

	
	for (int i = 0; i < N; i++) {
		void *valRet;
		pthread_join(ph_thread[i], &valRet);

	}

	cout << "Var: " << var << endl;

	return 0;
}

void* thread(void* arg) {
	int value = 10;

	for (int i = 0; i < 5000; i++) {
		pthread_mutex_lock(&mutex);
		var ++;
		pthread_mutex_unlock(&mutex);
	}

	return nullptr;
}
