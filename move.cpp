#include <iostream>
#include <iterator>
#include <string>

int main()
{
    std::string myString = "copy construct me";
    std::string newValue;

    std::cout << "myString: " << myString << std::endl;
    std::cout << "newValue: " << newValue << std::endl;

    // std::move allows us to 'steal' the value
    newValue = std::move(myString);

    std::println("myString: {}", myString);
    std::println("newValue: {}", newValue);

    // Could more explicitly call the static cast here to
    // move the value.
    myString = static_cast<std::string&&>(newValue);

    std::println("myString: {}", myString);
    std::println("newValue: {}", newValue);

    std::vector<char> path = {'a', 'b', 'c'};
    for (char c : path) {
        std::println("{}", c);
    }

    std::ranges::copy(path, std::ostream_iterator<char>(std::cout, ""));
    std::println("");

    return 0;
}
