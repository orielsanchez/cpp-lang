#include <iostream>

unsigned int LCG16() {
    static unsigned int s_state{5323};
    // Generate next number
    s_state = 8253729 * s_state + 2396403; // first modify the state
    return s_state % 32769; // then we use the new state to generate the next
                            // number in the sequence.
}

int main() {
    // Print 100 random numbers
    for (int count{1}; count <= 100; ++count) {
        std::cout << LCG16() << '\t';

        if (count % 10 == 0) {
            std::cout << '\n';
        }
    }

    return 0;
}
