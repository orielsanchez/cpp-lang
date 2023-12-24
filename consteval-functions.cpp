#include <functional>
#include <iostream>
// C++20 introduces the keyword consteval, which is used to indicate that a function must evaluate at compile-time,
// otherwise a compile error will result. Such functions are called immediate functions.

// Best Practice: Use consteval if you have a function that must run at compile-time for some reason (e.g. performance)
consteval int greater(int x, int y)
{
    return (x > y ? x : y);
}

// The following works because consteval functions require constant expressions as arguments --
// therefore, if we use the return value of a constexpr function as an argument to a consteval function,
// the constexpr function must be evaluated at compile-time!
// The consteval function just returns this argument as its own return value, so the caller can still use it.

// Note that the consteval function returns by value.
// While this might be inefficient to do at runtime
// (if the value was some type that is expensive to copy, e.g. std::string),
// in a compile-time context, it doesn’t matter because the entire call to the consteval function will simply be replaced with the calculated return value.

consteval auto compileTime(auto foo)
{
    return foo;
}
constexpr int lesser(int x, int y)
{
    return (x < y ? x : y);
}
int main()
{
    constexpr int g { greater(5, 6) }; // ok: will eval at compile-time
    std::cout << g << '\n';

    std::cout << greater(5, 6) << " is greater!\n"; // ok: will eval at compile-time
    int x { 5 }; // not constexpr
    std::cout << greater(x, 6) << " is greater!\n"; // error: consteval functions must eval at compile-time

    std::cout << lesser(5, 6) << '\n'; // may or may not execute at compile-time
    std::cout << compileTime(greater(5, 6)) << '\n'; // will execute at compile-time

    int p { 5 };
    std::cout << lesser(p, 6) << '\n'; // we can still call the constexpr version at runtime if we wish
}

// Rule:
//      - The compiler must be able to see the full definition of a constexpr or consteval function, not just a forward declaration

// Best Practice:
//      - Constexpr/consteval function used in a single source file (.cpp) can be defined in the source file above where they are used.
//      - Constexpr/consteval function used in multiple source files should be defined in a header file so they can be included into each source file

// For best results, avoid calling non-constexpr functions from within a constexpr function if possible.
// If your constexpr function requires different behavior for constant and non-constant contexts, conditionalize the behavior with if (std::is_constant_evaluated())
// Always test your constexpr functions in a constant context, as they may work when called in a non-constant context but fail in a constant context.
