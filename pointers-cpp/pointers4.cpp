// Copyright (C) 2022 bunnicash "@bunnicash" and licensed under GPL-2.0
#include <iostream>
#include <string>

class User {
public:
    std::string name;

};

int main() {
    int *x = new int(5);                    // explicity allocate memory for int x = 5
    std::cout << "Pointer " << x << " points to " << *x << std::endl;
    delete x;                               // delete int x, otherwise memory will stay occupied

    int y = 10, *p_y = &y;                  // have the computer allocate for us
    std::cout << "Pointer " << p_y << " points to " << *p_y << std::endl;

    // Class User Example (1)
    User one;
    one.name = "First Name";
    std::cout << one.name << std::endl;

    // Class User Example (2)
    User *two = new User();
    (*two).name = "Second Name";             // two gets dereferenced, pointer is followed in (...)
    std::cout << (*two).name << std::endl;
    delete two;

    // Class User Example (3, arrow operator) [Definition:  a->b = (*a).b)  OR  -> = (*expr). ]
    User *three = new User();
    three->name = "Third Name";             // instead of dereferencing, * in (), work with the pointer directly (combines both)
    std::cout << three->name << std::endl;
    delete three;
    return 0;
}
