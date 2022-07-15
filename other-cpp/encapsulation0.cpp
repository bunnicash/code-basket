// Normal
#include <iostream>

class Employee {
    public:
        int salary(int getSalary);
};

int Employee::salary(int getSalary) {
    return getSalary;
}

int main() {
    Employee myObj;
    std::cout << myObj.salary(50000);
    return 0;
}
