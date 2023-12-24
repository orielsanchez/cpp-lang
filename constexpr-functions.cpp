#include <iostream>
#include <type_traits> // for std::is_constatnt_evaluated

// To be eligible for compile-time evaluation, a function must have a constexpr return type and not call any non-constexpr functions when evaluated at compile-time.
// Additionally, a call to the function must have constexpr arguments (e.g. constexpr variables or literals).
//
// Key Insight
// A constexpr function that is eligible to be evaluated at compile-time will only be evaluated at compile-time if the return value is used where a constant expression is required.
// Otherwise, compile-time evaluation is not guaranteed.
//
// Thus, a constexpr function is better thought of as "can be used in a constant expression", not "will be evaluated at compile-time"
//
// Best Practice
// Unless you have a specific reason not to, a function that can be made constexpr generally should be made constexpr
constexpr int greater(int x, int y)
{
    return (x > y ? x : y);
}

constexpr int someFunction()
{
    if (std::is_constant_evaluated()) // if compile-time evaluation
        // do something
        return 0;
    else // runtime evaluation
         // do something else
        return 1;
}

int main()
{
    constexpr int g { greater(5, 6) }; // case 1: evaluated at compile-time
    std::cout << g << " is greater!\n";

    int x { 5 }; // not constexpr
    std::cout << greater(x, 6) << " is greater!\n"; // case 2: evaulated at runtime

    std::cout << greater(5, 6) << " is greater!\n"; // case 3: may be evaluated at either runtime or compile-time

    return 0;

    // There is no way to tell the compiler that a constexpr function should prefer to evaluate at compile-time whenever it can.
    // we can force a constexpr function that is eligible to be evaluated at compile-time to actually evaluate at compile-time by
    // ensuring the return value is used where a constant expression is required. This needs to be done on a per-call basis.
    // The most common way to do this is to use the return value to initialize a constexpr variable (this is why we’ve been using variable ‘g’ above).
}
