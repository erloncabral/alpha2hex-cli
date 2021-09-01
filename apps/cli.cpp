#include <iostream>
#include <string>

#include <alpha2hex/alpha2hex.hpp>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        cerr << "invalid argument: try " << argv[0] << " 83\n\n";
        return EXIT_FAILURE;
    }

    if (auto value = a2h::alpha2hex(argv[1]); value) {
        std::cout << a2h::hexPrintable(*value);
        return EXIT_SUCCESS;
    } else {
        cerr << "invalid argument: input an alpha between 0 and 100" << endl;
        return EXIT_FAILURE;
    }
}
