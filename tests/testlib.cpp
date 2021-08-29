#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <alpha2hex/alpha2hex.hpp>

TEST_CASE("alpha to hex check", "[main]") {
    REQUIRE(a2h::alpha2hex(00) == "00");
    REQUIRE(a2h::alpha2hex(10) == "1A");
    REQUIRE(a2h::alpha2hex(40) == "66");
    REQUIRE(a2h::alpha2hex(55) == "8C");
    REQUIRE(a2h::alpha2hex(60) == "99");
    REQUIRE(a2h::alpha2hex(80) == "CC");
    REQUIRE(a2h::alpha2hex(100) == "FF");
}
