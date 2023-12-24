#include <iostream>

// Best Practice
// Any variable that should not be modifiable after initialization and whose initializer is known at compile-time should be declared as constexpr
// Any variable that should not be modifiable after initialization and whose initializer is not known at compile-time should be declared as const.

int four()
{
    return 4;
}

const int five()
{
    return 5;
}

constexpr int six()
{
    return 6;
}

int main()
{
    constexpr double gravity { 9.8 };
    constexpr int sum { 4 + 5 };
    constexpr int something { sum };

    std::cout << "Enter your age: ";
    int age {};
    std::cin >> age;

    constexpr int myAge { age };
    constexpr int f { four() };
    constexpr int g { five() };
    constexpr int h { six() };

    return 0;
}
