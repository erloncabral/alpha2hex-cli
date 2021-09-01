#ifndef ALPHA2HEX_HPP
#define ALPHA2HEX_HPP

#include <string>
#include <memory>

namespace a2h {
    std::unique_ptr<int> alpha2hex(const std::string &alpha);

    int alpha2hex(int alpha);

    std::unique_ptr<int> hex2alpha(const std::string &hex);

    int hex2alpha(int hex);

    std::string hexPrintable(int hex);
}

#endif
