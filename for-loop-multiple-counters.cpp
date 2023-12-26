#include <iostream>

// Best practice
// Defining multiple variables (in the init-statement) and using the comma
// operator (in the end-expression) is acceptable inside a for statement.
int main() {
    for (int x{0}, y{9}; x < 10; ++x, --y) {
        std::cout << x << ' ' << y << '\n';
    }

    return 0;
}
