FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.13.6
)
FetchContent_MakeAvailable(catch)

add_executable(testlib testlib.cpp)

target_compile_features(testlib PRIVATE cxx_std_17)
target_link_libraries(testlib PRIVATE alpha2hexlib Catch2::Catch2)

add_test(NAME alpha2hextest COMMAND testlib)
