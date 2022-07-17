// Copyright (C) 2022 bunnicash "@bunnicash" and licensed under GPL-2.0
// Threading demo 2: Using mutex
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t aLock;    // mutex locks and unlocks will fail without it, "aLock undeclared"
long int a = 0;           // long int: https://en.wikipedia.org/wiki/C_data_types

void threadFunc1(void *arg) {
    int i;
    long int localA = 0;

    for(i = 1; i < 500000; i++) {
        localA = localA + i;
    }

    pthread_mutex_lock(&aLock);    // Lock/unlock once in thread (locks/unlocks would happen always if inside for-loop
    a = a + localA;
    pthread_mutex_unlock(&aLock);
}

void threadFunc2(void *arg) {
    int i;
    long int localA = 0;

    for(i = 500000; i <= 1000000; i++) {
        localA = localA + i;
    }

    pthread_mutex_lock(&aLock);    // Lock/unlock once in thread (locks/unlocks would happen always if inside for-loop
    a = a + localA;
    pthread_mutex_unlock(&aLock);
}

int main(int argc, char **argv) {  // This will properly add "a" now
    pthread_t one, two;            // Thread names
    int i;
    a = 0;

    pthread_mutex_init(&aLock, NULL);  // Initialize mutex
    pthread_create(&one, NULL, (void*)&threadFunc1, NULL);
    pthread_create(&two, NULL, (void*)&threadFunc2, NULL);

    pthread_join(one, NULL);
    pthread_join(two, NULL);

    printf("%ld\n", a);
    pthread_mutex_destroy(&aLock);     // Uninitialize mutex (https://pubs.opengroup.org/onlinepubs/007904875/functions/pthread_mutex_destroy.html)
    return 0;
}
