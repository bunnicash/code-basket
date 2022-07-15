// https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    std::cout << "You have entered " << argc - 1 << " arguments:" << "\n";

    for (int i = 1; i < argc; ++i)
        std::cout << argv[i] << "\n";

    return 0;
}


/*

// Unmodified version, outputs and counts "./main" as argument

int main(int argc, char** argv)
{
    cout << "You have entered " << argc << " arguments:" << "\n";

    for (int i = 0; i < argc; ++i)
        cout << argv[i] << "\n";

    return 0;
}
*/
