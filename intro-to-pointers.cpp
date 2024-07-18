#include <iostream>

int main()
{
    int x{5};
    std::cout << x << '\n';  // print value of variable x

    std::cout << &x << '\n';  // print the memory address of variable x

    std::cout << *(&x) << '\n';  // print the value at the memory address of variable x (which is value of x).

    // Recall
    // int;   a normal int
    // int&;  an lvalue reference to an int value
    // int*;  a pointer to an int value

    int y{6};      // a normal variable
    int& ref{y};   // a reference to an int bound to y
    int* ptr{&y};  // a pointer to an integer initialized with the address of variable y
    int& ref2{ref};

    // all these print value of y
    std::cout << ref << '\n';
    std::cout << *ptr << '\n';  // use dereference operator to print the value at the address that ptr is holding (which is y's address)
    std::cout << ref2 << '\n';

    std::cout << "Address of ptr: " << &ptr << '\n';
    return 0;
}
