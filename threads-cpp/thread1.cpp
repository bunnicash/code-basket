// Copyright (C) 2022 bunnicash "@bunnicash" and licensed under GPL-2.0
// Single thread (Note: could just do int a, a + i...)
#include <iostream>
#include <atomic>

std::atomic_int a = 0;

void thread1() {
    int i = 0;
    for(i; i <= 10; i++) {
        a.fetch_add(i);
    }
}

int main() {
    thread1();
    printf("%d\n", a.load());
    return 0;
}
