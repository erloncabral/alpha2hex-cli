#define CATCH_CONFIG_MAIN

#include <tuple>
#include <array>

#include <catch2/catch.hpp>
#include <alpha2hex/alpha2hex.h>

TEST_CASE("alpha decimal to hexadecimal", "[alpha2hex]") {
    const std::array<std::tuple<int, int>, 10> fixtures = {
            std::make_tuple<int, int>(0, 0),
            std::make_tuple<int, int>(15, 38),
            std::make_tuple<int, int>(30, 77),
            std::make_tuple<int, int>(45, 115),
            std::make_tuple<int, int>(50, 128),
            std::make_tuple<int, int>(56, 143),
            std::make_tuple<int, int>(65, 166),
            std::make_tuple<int, int>(80, 204),
            std::make_tuple<int, int>(95, 242),
            std::make_tuple<int, int>(100, 255)
    };

    SECTION("convert alpha int to alpha hexadecimal part off #AARRGGBB color") {
        for (const auto &fixture: fixtures) {
            const auto&[alpha, hex] = fixture;
            REQUIRE(a2h::alpha2hex(alpha) == hex);
        }
    }

    SECTION("convert alpha string to alpha hexadecimal part off #AARRGGBB color") {
        for (const auto &fixture: fixtures) {
            const auto&[alpha, hex] = fixture;
            if (auto value = a2h::alpha2hex(std::to_string(alpha)); value) {
                REQUIRE(*value == hex);
            }
        }
    }
}

TEST_CASE("alpha hexadecimal to decimal", "[hex2Alpha]") {
    const std::array<std::tuple<int, int>, 10> fixtures = {
            std::make_tuple<int, int>(0, 0),
            std::make_tuple<int, int>(38, 15),
            std::make_tuple<int, int>(77, 30),
            std::make_tuple<int, int>(115, 45),
            std::make_tuple<int, int>(128, 50),
            std::make_tuple<int, int>(143, 56),
            std::make_tuple<int, int>(166, 65),
            std::make_tuple<int, int>(204, 80),
            std::make_tuple<int, int>(242, 95),
            std::make_tuple<int, int>(255, 100)
    };

    SECTION("convert alpha hexadecimal part off #AARRGGBB color to decimal") {
        for (const auto &fixture: fixtures) {
            const auto&[hex, alpha] = fixture;
            REQUIRE(a2h::hex2alpha(hex) == alpha);
        }
    }
}

TEST_CASE("alpha hexadecimal to string", "[hex2alpha]") {
    const std::array<std::tuple<int, std::string>, 10> fixtures = {
            std::make_tuple<int, std::string>(0, "00"),
            std::make_tuple<int, std::string>(38, "26"),
            std::make_tuple<int, std::string>(77, "4D"),
            std::make_tuple<int, std::string>(115, "73"),
            std::make_tuple<int, std::string>(128, "80"),
            std::make_tuple<int, std::string>(143, "8F"),
            std::make_tuple<int, std::string>(166, "A6"),
            std::make_tuple<int, std::string>(204, "CC"),
            std::make_tuple<int, std::string>(242, "F2"),
            std::make_tuple<int, std::string>(255, "FF")
    };

    SECTION("convert alpha hexadecimal part off #AARRGGBB color to string") {
        for (const auto &fixture: fixtures) {
            const auto&[hex, printable] = fixture;
            REQUIRE(a2h::hexPrintable(hex) == printable);
        }
    }
}

TEST_CASE("alpha hexadecimal string to decimal", "[hex2Alpha]") {
    const std::array<std::tuple<std::string, int>, 10> fixtures = {
            std::make_tuple<std::string, int>("00", 0),
            std::make_tuple<std::string, int>("26", 15),
            std::make_tuple<std::string, int>("4D", 30),
            std::make_tuple<std::string, int>("73", 45),
            std::make_tuple<std::string, int>("80", 50),
            std::make_tuple<std::string, int>("8F", 56),
            std::make_tuple<std::string, int>("A6", 65),
            std::make_tuple<std::string, int>("CC", 80),
            std::make_tuple<std::string, int>("F2", 95),
            std::make_tuple<std::string, int>("FF", 100)
    };

    SECTION("convert alpha hexadecimal part off #AARRGGBB color to decimal") {
        for (const auto &fixture: fixtures) {
            const auto&[printable, alpha] = fixture;
            if (auto value = a2h::hex2alpha(printable); value) {
                REQUIRE(*value == alpha);
            }
        }
    }
}
