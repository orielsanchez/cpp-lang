#include <cassert> // for assert
#include <cstdint> // for std::int64_t
#include <format>
#include <iostream>
#include <limits> // for std::numeric_limits
#include <sstream> // for std::stringstream

// Prefer to compare the result of the remainder operator (operator%) against 0 if possible
bool isOdd(int x)
{
    return (x % 2) != 0; // could also write return (x % 2)
}

// A safer (but slower) version of powint() that checks for overflow
// note: exp must be non-negative
// Returns std::numeric_limits<std::int64_t>::max() if overflow occurs
constexpr std::int64_t powint_safe(std::int64_t base, int exp)
{
    assert(exp >= 0 && "powint_safe: exp parameter has negative value");

    // Handle 0 case
    if (base == 0)
        return (exp == 0) ? 1 : 0;

    std::int64_t result { 1 };

    // To make the range checks easier, we'll ensure base is positive
    // We'll flip the result at the end if needed
    bool negativeResult { false };

    if (base < 0) {
        base = -base;
        negativeResult = (exp & 1);
    }

    while (exp > 0) {
        if (exp & 1) // if exp is odd
        {
            if (result > std::numeric_limits<std::int64_t>::max() / base) {
                std::cerr << "powint_safe(): result overflowed\n";
                return std::numeric_limits<std::int64_t>::max();
            }
            result *= base;
        }

        exp /= 2;
        if (exp <= 0)
            break;

        if (base > std::numeric_limits<std::int64_t>::max() / base) {
            std::cerr << "powint_safe(): base overflowed\n";
            return std::numeric_limits<std::int64_t>::max();
        }

        base *= base;
    }

    if (negativeResult)
        return -result;

    return result;
}

int main(int argc, char* argv[])
{
    if (argc <= 2) {
        // On some OSs, argv[0] can end up as an empty string instead of program's name.
        // We'll conditionalize our response on whether argv[0] is empty or not.
        if (argv[0])
            std::cout << "Usage: " << argv[0] << " <base> <exp>" << '\n';
        else
            std::cout << "Usage: <program name> <base> <exp>" << '\n';

        return 1;
    }

    std::stringstream baseArg { argv[1] }; // set up a stringstream variable initialized with input from argv[1]
    std::stringstream expArg { argv[2] }; // set up a stringstream variable initialized with input from argv[2]
    std::int64_t base {};
    int exp {};

    if (!(baseArg >> base)) { // conversion happening here
        std::cerr << "Unable to convert baseArg to int64_t\n"; // if conversion fails
        return -1;
    }

    if (!(expArg >> exp)) { // conversion happening here
        std::cerr << "Unable to convert expArg to int\n";
        return -1;
    }

    std::int64_t result { powint_safe(base, exp) };
    std::cout << std::format("{}^{} = {}", base, exp, result) << '\n';

    return 0;
}
