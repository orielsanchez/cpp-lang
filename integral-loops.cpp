#include <iostream>

int main() {
    unsigned int count{10}; // note: unsigned

    while (count >= 0) {
        if (count == 0) {
            std::cout << "blastoff";
        } else {
            std::cout << count << ' ';
        }
        --count;
    }

    std::cout << '\n';
    return 0;
}

// It turns out, this program is an infinite loop. It starts out by printing 10
// 9 8 7 6 5 4 3 2 1 blastoff! as desired, but then loop variable count
// overflows, and starts counting down from 4294967295 (assuming 32-bit
// integers). Why? Because the loop condition count >= 0 will never be false!
// When count is 0, 0 >= 0 is true. Then --count is executed, and count wraps
// around back to 4294967295. And since 4294967295 >= 0 is true, the program
// continues. Because count is unsigned, it can never be negative, and because
// it can never be negative, the loop won’t terminate.

// Best practice
// Integral loop variables should generally be a signed integral type.
