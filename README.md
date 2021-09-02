Convert Alpha to Hexdecimal to use on #AARRGGBB colors.

Use:

```bash
./alpha2hex -a {alpha_value}
```

The requirements are:

* cmake 3.14+.
* C++17 compatible compiler
* Git

To configure:

```bash
cmake -S . -B build
```

Add `-GNinja` if you have Ninja.

To build:

```bash
cmake --build build
```

To test (`--target` can be written as `-t` in CMake 3.15+):

```bash
cmake --build build --target test
```

To use an IDE, such as Xcode:

```bash
cmake -S . -B xbuild -GXcode
cmake --open xbuild
```

Kudos for:

* https://cliutils.gitlab.io/modern-cmake/ for the great resource about modern cmake.
* https://stackoverflow.com/a/11286013/378589 very well explained answer.
* https://github.com/ademar111190 for the lovely java version.
