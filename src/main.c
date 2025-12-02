#include "mutex.h"
#include <stdio.h>
#include <pthread.h>

mutex m;
int counter = 0;

void* thread_func(void* arg) {
    for (int i = 0; i < 100000; i++) {
        mutex_lock(&m);   // acquire lock
        counter++;            // critical section
        mutex_unlock(&m); // release lock
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    mutex_init(&m);

    pthread_create(&t1, NULL, thread_func, NULL);
    pthread_create(&t2, NULL, thread_func, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final Counter: %d\n", counter);
    return 0;
}

