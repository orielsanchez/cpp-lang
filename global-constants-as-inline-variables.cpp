// Best practice If you need global constants and your compiler is C++17
// capable, prefer defining inline constexpr global variables in a header file.
#include "constants.h"
#include <iostream>

int main() {
    std::cout << "Enter a radius: ";
    double radius{5};
    std::cin >> radius;

    std::cout << "The circumference is: " << 2 * radius * constants::pi << '\n';

    return 0;
}
// We can include constants.h into as many code files as we want, but these
// variables will only be instantiated once and shared across all code files.
// This method does retain the downside of requiring every file that includes
// the constants header be recompiled if any constant value is changed.
