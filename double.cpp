#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";

    int num {};
    std::cin >> num;

    std::cout << "Double that integer is: " << 2 * num << '\n';

    return 0;
}
