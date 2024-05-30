#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

void *PrintHello(void *threadid) {
    long tid;
    tid = (long)threadid;
    printf("Hello World! It's me, thread #%ld!\n", tid);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS]; // Array to hold thread IDs
    int rc; // Variable to hold return code
    long t; // Loop variable for thread index

    // Loop to create threads
    for(t = 0; t < NUM_THREADS; t++) {
        printf("In main: creating thread %ld\n", t);
        // Create a thread; pass thread ID, thread attributes, function to execute, and argument to the function
        rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for all threads to finish
    pthread_exit(NULL);
}
