// Encapsulated
#include <iostream>

class Employee {
    private:
        // Private attribute
        int salary;

    public:
        // Setter, Mutator
        void setSalary(int s) {
            salary = s;
        }
        // Getter
        int getSalary() {
            return salary;
        }
};

int main() {
    Employee myObj;
    myObj.setSalary(50000);
    std::cout << myObj.getSalary();
    return 0;
}
