#include <cmath> // for std::sqrt
#include <iostream>

// Key insgiht: None-type template parameters are used primarily whwn we need to
// pass constexpr values to functions (or class types) so they can be used in
// contexts that require a constant expression.

template <double D> // requires C++20 for floating point non-type parameters
double getSqrt() {
    static_assert(D >= 0.0, "getSqrt(): D must be non-negative.");

    if constexpr (D >= 0)
        return std::sqrt(D);

    return 0.0;
}

// C++17
// Type deduction for non-type template parameters using auto

template <auto N> void print() { std::cout << N << '\n'; }

int main() {
    std::cout << getSqrt<5.0>() << '\n';
    std::cout << getSqrt<-5.0>() << '\n';
    print<5>();
    print<'c'>();

    return 0;
}
