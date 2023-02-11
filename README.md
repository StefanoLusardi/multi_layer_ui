# multi layer ui

Proof of concept for a cross-platform, multi-layered UI, made in C++ with ImGui, CMake, Ninja and Conan.

---

## Pre requisites
- Python3
- MSVC (on Windows), GCC or Clang (on Linux/Mac)

## Setup CMake, Ninja and Conan
```bash
pip install conan
pip install cmake
pip install ninja
```

## Configure Dependencies
- Create Conan profile for the current environment and choosen compiler
```bash
python conan/profile.py <COMPILER_NAME> <COMPILER_VERSION>

# Example: clang 15
python conan/profile.py clang 15 
# This will create a conan profile file under conan/profiles/clang15

# Example: gcc 12
python conan/profile.py gcc 12
# This will create a conan profile file under conan/profiles/gcc12
```

- Install packages for the given conan profile and build configuration (Debug or Release)
```bash
python conan/install.py <Debug|Release> <PROFILE>

# Example: Release with gcc12 profile
python conan/install.py Release gcc12

# Example: Debug with gcc12 profile
python conan/install.py Debug clang15
```

## Configure Project
```bash
# Debug
cmake -G Ninja -D CMAKE_BUILD_TYPE=Debug -B ./build/Debug -S .

# Release
cmake -G Ninja -D CMAKE_BUILD_TYPE=Release -B ./build/Release -S .
```

## Build Project
```bash
# Debug
cmake --build ./build/Debug --config Debug

# Release
cmake --build ./build/Release --config Release
```