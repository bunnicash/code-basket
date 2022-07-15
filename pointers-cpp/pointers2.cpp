// Copyright (C) 2022 bunnicash "@bunnicash" and licensed under GPL-2.0
#include <iostream>
#include <string>

int main() {
    int x = 7;
    x = 14;

    int *ptr_x = &x;
    std::cout << *ptr_x << ptr_x << std::endl;  // Output: 14, x_address
    *ptr_x = 21;
    std::cout << *ptr_x << x << std::endl;  // 21, 21
    return 0;
}
