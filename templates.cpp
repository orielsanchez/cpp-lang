#include <iostream>

namespace Random {
int add(int x, int y) { return x + y; }
}  // namespace Random

template <typename T>
T max(T x, T y)
{
    std::cout << "called max<int>(int, int)\n";
    return (x < y) ? y : x;
}

int max(int x, int y)
{
    std::cout << "called max(int, int)\n";
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max<int>(1, 2) << '\n';  // calls max<int>(int, int)
    std::cout << max<>(1, 2)
              << '\n';               // deduces max<int>(int, int)
                                     // (non-template functions NOT considered)
    std::cout << max(1, 2) << '\n';  // calls max(int, int)
}
