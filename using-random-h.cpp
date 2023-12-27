#include "Random.h"
#include <iostream>

int main() {
    // We can use Random::get() to generate random numbers
    std::cout << Random::get(1, 6) << '\n';
    std::cout << Random::get(1u, 6u) << '\n';

    std::cout << Random::get<std::size_t>(1, 6u) << '\n';

    // Can access Random::mt directly if we have our own distribution
    std::uniform_int_distribution<> die6{1, 6};
    for (int i{0}; i <= 10; ++i) {
        std::cout << die6(Random::mt) << '\t';
    }

    std::cout << '\n';
}
