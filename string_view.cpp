#include <iostream>
#include <string_view> // C++17
// Best practice:
// Prefer std::string_view over std::string when you need a read-only string, especially for function parameters

// str provides read-only access to whatever argument is passed in.
void printSV(std::string_view str)
{
    std::cout << str << "\n";
}

void printString(std::string str)
{
    std::cout << str << "\n";
}

int main()
{

    std::string_view sv { "Hello, world!" }; // now a std::string_view
    printSV(sv);

    // std::string_view parameters will accept many different types of string arguments
    printSV("Hello, world!"); // call with C-style string literal

    std::string s2 { "Evening, world!" };
    printSV(s2); // call with std::string

    std::string_view sv2 { s2 };
    printSV(sv2); // call with std::string_view

    // std::string_view will not implicitly convert to std::string
    printString(sv); // compile error

    std::string s { sv }; // okay: we can create std::string using std::string_view initializer
    printString(s);

    printString(static_cast<std::string>(sv)); // okay:: we can explicitly cast a std::string_View to a std::string

    // Assignment changes what the std::string_view is viewing
    std::string name { "Alex" };
    std::string_view sv3 { name }; // sv3 viewing name
    std::cout << sv3 << '\n'; // prints Alex

    sv3 = "John"; // sv now viewing "John" (does NOT change name)
    std::cout << sv << '\n'; // prints John
    std::cout << name << '\n'; // prints Alex

    // Unlike std::string, std::string_view has full support for constexpr
    constexpr std::string_view sv4 { "Goodbye, world!" }; // s is a string symbolic constant

    std::cout << sv4 << '\n'; // sv4 will be replaced with "Goodbye, world!" at compile-time
    return 0;
}
