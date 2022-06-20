# multi layer ui

Proof of concept for a cross-platform, multi-layered UI, made in C++ with ImGui, Conan and CMake.

---

## Pre requisites
- CMake
- Python3
- Ninja
- MSVC (on Windows), GCC or Clang (on Linux/Mac)

## Setup Conan
```bash
pip install conan
```

## Configure Dependencies
```bash
./conan/run_conan.sh <Debug|Release> <gcc|clang> <COMPILER_MAJOR_VERSION> # Linux/Mac
conan\run_conan.bat <Debug|Release> # Windows
```

## Configure Project
```bash
cmake -G Ninja -D CMAKE_BUILD_TYPE=<Debug|Release> -B ./build/<Debug|Release> -S .
```

## Build Project
```bash
cmake --build ./build/<Debug|Release> --config <Debug|Release>
```