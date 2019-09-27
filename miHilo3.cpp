#include <iostream>
#include <pthread.h>
#include <errno.h>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

using namespace std;

void* thread(void *);

const int N = 5;
int var = 0;

int main() {
	pthread_t ph_threads[N];

	for (int i = 0; i < N; i++) {
		if(pthread_create(&ph_threads[i], nullptr, thread, nullptr) != 0) {
			cout << "Error creating the thread" << errno << endl;
			_exit(1);
		}
	}

	for (int i = 0; i < N; i++) {
		void *valRet;
		pthread_join(ph_threads[i], &valRet);
	}

	cout << "Var: " << var << endl;

	return 0;
}

void* thread(void *arg) {
	for (int i = 0; i < 5000; i++) {
		var ++;
	}

	return nullptr;
}
