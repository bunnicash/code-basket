// Copyright (C) 2022 bunnicash "@bunnicash" and licensed under GPL-2.0
#include <iostream>
#include <string>

/*
__________________________
- Memory: Address (Location), Value (Data stored)
- "0x1000 0x4" = (hex) 4 is stored at location hex 1000, "int x = 4;"
- "0x1004 0x1000" = location of 4 is stored in new address, pointer!, "int *ptr_x = &x;"
- Pointer is a value that happens to be an address

* = pointer
& = address of
__________________________
*/

int main() {
    int x = 4;
    int *ptr_x = &x;
    int y = *ptr_x;  // Here, (*) is a dereference, go to location, get the value
    std::string spc = " ";
    std::cout << x << spc << *ptr_x << spc << y << spc << ptr_x << spc << &ptr_x << spc << &x << std::endl;
    // Output: 4, 4, 4, x_address, pointer_address, x_address
    return 0;
}
