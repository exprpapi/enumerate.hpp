# enumerate.hpp
Python Style Enumerate for C++20

## Installation
Locate your include path, in my case: `LOCAL_INCLUDE=${HOME}/.local/include/`.  
Emplace the header: `${LOCAL_INCLUDE}/enumerate/enumerate.hpp`.

## Example Usage
Using your compile command, in my case: `CPP_CMD=g++ --std=c++2b -g -Wall -Wextra -Wpedantic` compile like:
```bash
$ ${CPP_CMD} -I"${LOCAL_INCLUDE}/enumerate" example.cpp
```
where
```C++
// example.cpp
#include <vector>
#include <iostream>
#include <enumerate.hpp>

auto print(auto... args) {
  (std::cout << ... << args) << std::endl;
}

auto main(int argc, char** argv) -> int {
  auto args = std::vector<std::string>(argv, argv + argc);
  for (auto [i, arg] : enumerate(args)) {
    print(i, ": ", arg);
  }
}
```
