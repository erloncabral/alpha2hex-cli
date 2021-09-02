#include <iostream>
#include <string>
#include <vector>

#include <alpha2hex/alpha2hex.hpp>

int main(int argc, char *argv[]) {
    std::vector<std::string> args(argv + 1, argv + argc);

    auto dumpInvalidArgument = [](const std::string &argument) {
        std::cerr << "invalid argument " << argument << std::endl;
    };

    auto dumpHelp = []() {
        std::cout << "Usage: alpha2hex [options]\n";
        std::cout << "Options:\n\t";
        std::cout << "[-a --alpha]\tPass alpha (0 to 100).\n\t";
        std::cout << "[-x --hex]\tPass hex (00 to FF).\n\n";
    };

    for (auto i = args.begin(); i != args.end(); ++i) {
        if (*i == "-h" || *i == "--help") {
            dumpHelp();
            return EXIT_SUCCESS;
        } else if (*i == "-x" || *i == "--hex") {
            const std::string hex = *++i;
            if (auto value = a2h::hex2alpha(hex); value) {
                std::cout << "Alpha: " << *value << std::endl;
                return EXIT_SUCCESS;
            } else {
                dumpInvalidArgument(hex);
                return EXIT_FAILURE;
            }
        } else if (*i == "-a" || *i == "--alpha") {
            const std::string alpha = *++i;
            if (auto value = a2h::alpha2hex(alpha); value) {
                std::cout << "Hex: " << a2h::hexPrintable(*value) << std::endl;
                return EXIT_SUCCESS;
            } else {
                dumpInvalidArgument(alpha);
                return EXIT_FAILURE;
            }
        }
    }

    dumpHelp();
    return EXIT_FAILURE;
}
