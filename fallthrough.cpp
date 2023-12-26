// C++17 adds a new attribute called [[fallthrough]].

// Attributes are a modern C++ feature that allows the programmer to provide the
// compiler with some additional data about the code. To specify an attribute,
// the attribute name is placed between double brackets. Attributes are not
// statements -- rather, they can be used almost anywhere where they are
// contextually relevant.

// The [[fallthrough]] attribute modifies a null statement to indicate that
// fallthrough is intentional (and no warnings should be triggered):
#include <iostream>

int main() {
    switch (2) {
    case 1:
        std::cout << 1 << '\n';
        break;
    case 2:
        std::cout << 2 << '\n';
        [[fallthrough]]; // intentional fallthrough -- note the semicolon to
                         // indicate the null statement
    case 3:
        std::cout << 3 << '\n';
        break;
    }

    return 0;
}
