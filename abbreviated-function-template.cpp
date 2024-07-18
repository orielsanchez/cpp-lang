#include <iostream>

// C++20
// Best Pracice:
// Feel free to use abbreviated function templates with a single auto parameter,
// or where each auto parameter should be an indepenedent type.
auto max(auto x, auto y) { return (x < y) ? y : x; }

// Warning: There isn't a concise way to use abbreviated function templates when
// you want more than one auto parameter of the same type. i.e. auto max(T x, T,
// y) (two parameters of the same type)

int main() {
    std::cout << max(2, 3.5) << '\n';

    return 0;
}
