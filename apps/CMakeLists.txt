add_executable(alpha2hex-cli cli.cpp)
target_compile_features(alpha2hex-cli PRIVATE cxx_std_17)

target_link_libraries(alpha2hex-cli PUBLIC libalpha2hex)
