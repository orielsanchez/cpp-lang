#include <iostream>

int add(int x, int y);

int main()
{
    std::cout << "Adding two integers!\n";

    std::cout << "Enter first integer: ";

    int x {};
    std::cin >> x;

    std::cout << "Enter second integer: ";

    int y {};
    std::cin >> y;

    int sum { add(x, y) };

    std::cout << "Sum: " << sum << '\n';
    return 0;
}
