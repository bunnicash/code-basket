// Copyright (C) 2022 bunnicash "@bunnicash" and licensed under GPL-2.0
#include <iostream>
#include <string>

int main() {
    int numberarray[5];  // 0, 1, 2, 3, 4
    int *ptr_a = numberarray;  // &numberarray[0], array name is a pointer to itself (beginning)
    int v = 10;

    for(; ptr_a < &numberarray[5]; ptr_a++) {  // for address of element in array < 5 do (5 doesn't exist)
        *ptr_a = v;   // &numberarray[0] is 10, then ...
        v = v * 2;  // 10*2 follows, loop repeats, ptr++ incremements, &numberarray[1] is 20 etc
    }

    int i;
    for(i = 0; i < 5; i++) {
        std::cout << numberarray[i] << std::endl;
    }
    return 0;
}
