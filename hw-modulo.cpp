#include <cmath>
#include <iostream>
#include <print>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Needs mod!" << std::endl;
    }
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }

    int m = *argv[1];
    std::println("{}", m);
    for (int i = 0; i < m; i++) {
        int x = pow(i, 2) - i - 2;
        int r = (int)fmod(x, m);
        std::println("{}: ({}, {})", i, x, r);
    }
    return 0;
}
