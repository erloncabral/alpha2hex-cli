set(HEADER_LIST "${Alpha2Hex_SOURCE_DIR}/include/alpha2hex/alpha2hex.hpp")

add_library(alpha2hexlib STATIC alpha2hex.cpp ${HEADER_LIST})

target_include_directories(alpha2hexlib PUBLIC ../include)
target_compile_features(alpha2hexlib PUBLIC cxx_std_17)
target_compile_options(alpha2hexlib PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)
