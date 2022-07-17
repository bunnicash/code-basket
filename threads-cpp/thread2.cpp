// Copyright (C) 2022 bunnicash "@bunnicash" and licensed under GPL-2.0
// Two threads executed one after another
#include <iostream>
#include <atomic>
#include <thread>

std::atomic_int a = 0;  // alt:  std::atomic_int a{0};

void thread1() {
    int i = 0;
    for(i; i < 5; i++) {
        a.fetch_add(i);
    }
}

void thread2() {
    int i = 5;
    for(i; i <= 10; i++) {
        a.fetch_add(i);
    }
}

int main() {
    std::thread t1(thread1);
    std::thread t2(thread2);
    t1.join();
    t2.join();
    printf("%d\n", a.load());
    return 0;
}
