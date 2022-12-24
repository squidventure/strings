# strings
strings is a header-only library written in modern C++ to give users access to simple string functions. Inspired by Go's string package, it's designed to have a similar interface, although each function's implementation is written from scratch rather than just ported from Go. it includes benchmarks (using google benchmark) and tests (using gtest).

# usage
usage is designed to be simple. the functions are all encapsulated within namespace strings.
```c++
    #include <iostream>

    #include "strings.hpp"
    auto main(int argc, char* argv[]) -> int {
        std::string buffer = "hello world";
        std::cout << strings::ToUpper(buffer) << std::endl;
        auto split = strings::Split(buffer, ' ');
        for (auto &s: split) std::cout << s << std::endl;
        std::cout << strings::Join(split, ' ') << std::endl;
    }
```