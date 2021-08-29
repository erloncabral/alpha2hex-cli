#include <cstdio>
#include <iostream>

#include <alpha2hex/alpha2hex.hpp>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        cerr << "invalid argument: try " << argv[0] << " 83\n\n";
        return EXIT_FAILURE;
    }
    int alpha = -1;
    if (sscanf_s(argv[1], "%i", &alpha) != 1) {
        cerr << "invalid argument: " << argv[1] << "is not a valid alpha" << endl;
        return EXIT_FAILURE;
    }
    if (alpha < 0 || alpha > 100) {
        cerr << "invalid argument: input an alpha between 0 and 100" << endl;
        return EXIT_FAILURE;
    }
    cout << a2h::alpha2hex(alpha);
    return EXIT_SUCCESS;
}
