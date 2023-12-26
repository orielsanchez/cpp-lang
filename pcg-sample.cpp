#include <cstdio>
#include <iostream>
#include <pcg/pcg_extras.hpp>
#include <pcg/pcg_random.hpp>
#include <random>

int main() {
    pcg32 rng(pcg_extras::seed_seq_from<std::random_device>{});
    std::clog << "RNG used: " << rng << "\n\n";

    for (int i{0}; i < 16; ++i) {
        for (int j{0}; j < 16; ++j) {
            printf("%03u", rng(1000));
        }
        printf("\n");
    }
}
