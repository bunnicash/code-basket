#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "No arguments have been specified \n";
        return 1;
    } else {
        std::cout << argv << std::endl; // address of first item in array (same as &argv)
        std::cout << *argv << std::endl; // value of first item in array
        std::cout << argv[0] << std::endl;
        std::cout << argv[1] << std::endl;

        if (argv[1] == std::string("-Sy")) {
            std::cout << "installing..." << std::endl;

            // output array contents starting at...
            for (int i = 2; i < argc; i++) {
                std::cout << argv[i] << " ";
            }
        }
        std::cout << "\n";
        return 0;
    }
}
