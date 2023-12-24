#include <cstdint>
#include <iostream>

int main()
{
    std::int8_t myInt { 65 };
    std::cout << myInt << '\n'; // prints A on some systems

    std::cout << static_cast<int>(myInt) << '\n'; // always prints 65

    // fixed-width types will always print and input as integral values.
    std::cout << "Enter a number between 0 and 127 (int16_t): ";
    std::int16_t myInt2 {};
    std::cin >> myInt2;

    std::cout << "You've entered: " << static_cast<int>(myInt2) << '\n';

    std::cout << "Enter a number between 0 and 127 (int8_t): ";
    std::int8_t myInt3 {};
    std::cin >> myInt3;

    std::cout << "You've entered: " << static_cast<int>(myInt3) << '\n';
    // When std::int8_t is treated as a char, the input routines interpret our input as a sequence of characters, not as an integer.
    // So when we enter 35, we’re actually entering two chars, '3' and '5'.
    // Because a char object can only hold one character, the '3' is extracted (the '5' is left in the input stream for possible extraction later).
    // Because the char '3' has ASCII code point 51, the value 51 is stored in myInt, which we then print later as an int.

    return 0;
}
