#include <format>
#include <iostream>
#include <string> // allows use of std::string
// Best practice:
// If using std::getline() to read strings, use std::cin >> std::ws input manipulator to ignore leading whitespace.
// This needs to be done for each std::getline() call, as std::ws is not preserved across calls.
//
// Key insight:
// Using the extraction operator (>>) with std::cin ignores leading whitespace.
// It stops extracting when encountering non-leading whitespace.
// std::getline() does not ignore leading whitespace unless you use input manipulator std::ws.
// It stops extracting when encountering a newline.

int main()
{
    std::string lastName { "Sanchez" };
    std::string firstName {};
    firstName = "Oriel";

    std::cout << "Pick 1 or 2: ";
    int choice {};
    std::cin >> choice;

    std::cout << "Enter your full name: ";
    std::string fullName {};
    std::getline(std::cin >> std::ws, fullName); // read a full line of text into name

    std::cout << "Hello, " << fullName << ", you picked " << choice << "\n";

    // std::string::length() returns an unsigned integral value (likely size_t).
    // static_Cast to avoid compiler warnings about signed/unsigned conversions
    int length { static_cast<int>(fullName.length()) };
    std::cout << std::format("length is {}\n", length);

    // C++20, can use std::ssize() function to get length of std::string as a signed integral value:
    long length2 { std::ssize(fullName) };
    std::cout << fullName << " has " << length2 << " characters\n";

    // Note: Initializing a std::string is expensive
    // Note:Do not pass std::string by value, as it makes an expensive copy
    //      - in most cases, use std::string_view parameter instead
    return 0;
}
