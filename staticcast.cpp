#include <iostream>

void print(int x)
{
    std::cout << x << '\n';
}

int main()
{
    print(static_cast<int>(5.5));

    char ch { 97 }; // 97 is ASCII code for 'a'
    std::cout << ch << " has value " << static_cast<int>(ch) << '\n';
    // Note: argument to static_cast evals as an expression. variable itself is ot affected.
    // variable ch is still a char, still holds same value even after we cast its value to int

    return 0;
}
