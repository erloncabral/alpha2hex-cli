#include <cmath>
#include <iomanip>
#include <sstream>

#include "alpha2hex/alpha2hex.hpp"

namespace a2h {
    std::unique_ptr<int> alpha2hex(const std::string &alpha) {
        try {
            return std::make_unique<int>(alpha2hex(std::stoi(alpha)));
        } catch (...) {
            return nullptr;
        }
    }

    int alpha2hex(int alpha) {
        return static_cast<int>(round(static_cast<double>(alpha) * 255.0 / 100.0));
    }

    std::unique_ptr<int> hex2alpha(const std::string &hex) {
        try {
            return std::make_unique<int>(hex2alpha(std::stoi(hex, nullptr, 16)));
        } catch (...) {
            return nullptr;
        }
    }

    int hex2alpha(int hex) {
        return static_cast<int>(round(static_cast<double>(hex) / 255.0 * 100.0));
    }

    std::string hexPrintable(int hex) {
        std::ostringstream stream;
        stream << std::setw(2) << std::setfill('0') << std::uppercase << std::hex << hex;
        return stream.str();
    }
}
