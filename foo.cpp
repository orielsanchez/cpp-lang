#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

int main()
{
    std::array<int, 10> w;
    std::vector<int> v{8, 4, 5, 9};

    v.push_back(6);
    v.push_back(9);

    v[2] = -1;

    for (int n : v) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    for (const int n : {3, 5}) {
        (std::find(v.begin(), v.end(), n) == std::end(v))
            ? std::cout << "v does not contain" << n << '\n'
            : std::cout << "v contains " << n << '\n';
    }

    auto is_even = [](int i) { return i % 2 == 0; };
}
