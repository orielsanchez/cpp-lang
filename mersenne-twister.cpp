#include <chrono>
#include <iostream>
#include <random>
// Best practice: Only seed a given pseudo-random number generator once, and do
// not reseed it.

int main() {
    // Instantiate a 32-bit Mersenne Twister
    std::mt19937 mt{static_cast<std::mt19937::result_type>(
        std::chrono::steady_clock::now()
            .time_since_epoch()
            .count())}; // Seed MT using steady_clock

    std::mt19937 mt2{
        std::random_device{}()}; // Typically asks OS for random number

    // Print a bunch of random numbers
    for (int count{1}; count <= 100; ++count) {
        std::cout << mt() << '\t';

        if (count % 10 == 0) {
            std::cout << '\n';
        }
    }

    // Create a reusable random number generator that generates uniform numbers
    // between 1 and 6
    std::uniform_int_distribution die6{1, 6};

    // Print a bunch of random numbers
    for (int i{1}; i <= 40; ++i) {
        std::cout << die6(mt) << '\t'; // generate a roll of die here

        if (i % 10 == 0) {
            std::cout << '\n';
        }
    }
    return 0;
}
