#include <iostream>

int g_x{5};

int main()
{
    int x{5};           // x is a modfiable lvalue
    const int& ref{x};  // okay: we can bind a const reference to a modifiable lvalue

    std::cout << ref << '\n';  // okay: we can access the object through our const reference
    ref = 7;                   // error: we cannot modify an object through a const reference

    x = 6;  // okay: x is a modifiable lvalue, we can still modify it through the original identifier

    const int& refOfTemporaryObject{5};         // temporary object golding value 5 has its lifetime extended to match refOfTemporaryObject
    std::cout << refOfTemporaryObject << '\n';  // Thus, we can safely use it here

    [[maybe_unused]] constexpr int& ref1{g_x};  // okay: can bind to global

    static int s_x{6};
    [[maybe_unused]] constexpr int& ref2{s_x};  // okay: can bind to static local
    int y{6};

    [[maybe_unused]] constexpr int& ref3{y};  // compile error: can't bind to non-static object

    // When defining a constexpr reference to a const variable, we need to apply both constexpr (which applies to the reference) and const (which applies to the type being referenced)
    static const int s_y{6};
    [[maybe_unused]] constexpr int& ref4{s_x};

    return 0;
}
