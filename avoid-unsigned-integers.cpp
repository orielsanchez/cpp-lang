#include <iostream>

int main()
{
    signed int x { 2 };
    unsigned int y { 3 };
    std::cout << (x - y) << '\n'; // 2 - 3 = 4294967295

    signed int s { -1 };
    unsigned int t { 1 };

    if (s < t) {
        std::cout << "-1 is less than 1\n";
    } else {
        std::cout << "1 is less than -1\n";
    }

    return 0;
}
