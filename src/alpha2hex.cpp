#include <cmath>
#include <iomanip>
#include <sstream>

#include "alpha2hex/alpha2hex.hpp"

namespace a2h {
    int alpha_value(int alpha) {
        return static_cast<int>(round(255 * alpha / 100.0));
    }

    std::string hex_string(int alpha) {
        std::ostringstream stream;
        stream << std::setw(2) << std::setfill('0') << std::uppercase << std::hex << alpha_value(alpha);
        return stream.str();
    }

    std::string alpha2hex(int alpha) {
        return hex_string(alpha);
    }
}
