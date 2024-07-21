#include <print>

#include "Student.hpp"
#include "orielmath.hpp"  // Always include header files, never .cpp files

int main()
{
    std::println("{}", add(7, 2));
    {
        Student oriel;
        oriel.printName();
        oriel.setName("Oriel");
        oriel.printName();
    }

    return 0;
}

// If we have implementation file (.cpp),
// run g++ main.cpp orielmath.cpp -o prog

// Can compile orielmath.cpp:
// g++ orielmath.cpp -c
// Then we can use object file to compile
// g++ main.cpp orielmath.o -o prog
