#include <bitset> // for std::bitset
#include <format> // C++20
#include <iostream>
// #include <print> // C++23

int main()
{
    // C++14 adds support for binary literals using the 0b prefix:
    int bin {}; // assume 16-bit ints
    bin = 0b1; // assign binary 0000 0000 0000 0001 to the variable
    bin = 0b11; // assign binary 0000 0000 0000 0011 to the variable
    bin = 0b1010; // assign binary 0000 0000 0000 1010 to the variable
    bin = 0b1111000; // assign binary 0000 0000 1111 0000 to the variable
    std::cout << bin << '\n';

    // C++14 also adds ability to use quotation mark (') as a digit separator:
    int value { 0b1001'0010 };
    long value1 { 2'432'332 };
    std::cout << value + value1 << '\n';

    // Outputting values in decimal, octal, or hexidecimal:
    int x = { 12 };
    std::cout << x << '\n';
    std::cout << std::hex << x << '\n';
    std::cout << x << '\n';
    std::cout << std::oct << x << '\n';
    std::cout << x << '\n';
    std::cout << std::dec << x << '\n';
    std::cout << x << '\n';

    // Outputting values in binary
    // std::bitset<8> means we want to store 8 bits (number of bits must be a compile-time constant)
    // can be initialized with an integral value of any format (dec, oct, hex, bin)
    std::bitset<8> bin1 { 0b1100'0101 };
    std::bitset<8> bin2 { 0xC5 };
    std::bitset<8> bin3 { 16 };
    std::bitset<8> bin4 { 012 };

    std::cout << bin1 << '\n'
              << bin2 << '\n'
              << bin3 << '\n'
              << bin4 << '\n';

    std::cout << std::bitset<4> { 0b1010 } << '\n'; // create a temp std::bitset and print it

    std::cout << std::format("{:b}\n", 0b1010); // C++20
    std::cout << std::format("{:#b}\n", 0b1010); // C++20

    // std::print("{:b} {:#b}\n", 0b1010, 0b1010);
    return 0;
}
