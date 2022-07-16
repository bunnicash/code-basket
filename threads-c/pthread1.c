// Copyright (C) 2022 bunnicash "@bunnicash" and licensed under GPL-2.0
// Threading demo 1: No sync/mutex
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

volatile long int a = 0;  // volatile = it'll change when it's running (long int: https://en.wikipedia.org/wiki/C_data_types)

void threadFunc1(void *arg) {
    int i;

    for(i = 1; i < 500000; i++) {
        a = a + i;
    }
}

void threadFunc2(void *arg) {
    int i;

    for(i = 500000; i <= 1000000; i++) {
        a = a + i;
    }
}

int main(int argc, char **argv) {  // This will add "a" on two threads, some of these operations get lost in loading/saving!
    pthread_t one, two;            // Thread names
    int i;
    a = 0;

    pthread_create(&one, NULL, (void*)&threadFunc1, NULL);
    pthread_create(&two, NULL, (void*)&threadFunc2, NULL);

    pthread_join(one, NULL);
    pthread_join(two, NULL);

    printf("%ld\n", a);
    return 0;
}
