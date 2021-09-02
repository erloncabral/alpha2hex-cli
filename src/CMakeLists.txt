set(HEADER_LIST "${Alpha2Hex_SOURCE_DIR}/include/alpha2hex/alpha2hex.hpp")

add_library(libalpha2hex STATIC alpha2hex.cpp ${HEADER_LIST})

target_include_directories(libalpha2hex PUBLIC ../include)
target_compile_features(libalpha2hex PUBLIC cxx_std_17)
target_compile_options(libalpha2hex PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)
