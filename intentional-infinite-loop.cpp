#include <iostream>

// Best practice: Favor while(true) for intential infinite loops
int main() {
    while (true) {
        std::cout << "Loop again? (Y/n)?: ";
        char c{};
        std::cin >> c;

        if (c == 'n' || c == 'N') {
            return 0;
        }
    }
}
