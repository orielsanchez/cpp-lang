// Best practice
//      Prefer int when the size of the integer doesn’t matter (e.g. the number will always fit within the range of a 2-byte signed integer).
//      For example, if you’re asking the user to enter their age, or counting from 1 to 10, it doesn’t matter whether int is 16 or 32 bits (the numbers will fit either way).
//      This will cover the vast majority of the cases you’re likely to run across.
//      Prefer std::int#_t when storing a quantity that needs a guaranteed range.
//      Prefer std::uint#_t when doing bit manipulation or where well-defined wrap-around behavior is required.
//
// Avoid the following when possible:
//      short and long integers -- use a fixed-width type instead.
//      Unsigned types for holding quantities.
//      The 8-bit fixed-width integer types.
//      The fast and least fixed-width types.
//      Any compiler-specific fixed-width integers -- for example, Visual Studio defines __int8, __int16, etc…
//
// The size of std::size_t imposes a strict mathematical upper limit to an object’s size.
// In practice, the largest creatable object may be smaller than this amount (perhaps significantly so).

#include <cstddef> // for std::size_t
#include <cstdint> // for fixed-width integers and least/fast types
#include <iostream>

int main()
{
    std::cout << "std::size_t: " << sizeof(std::size_t) * 8 << " bits\n";
    std::cout << '\n';
    std::cout << "std::int8_t: " << sizeof(std::int8_t) * 8 << " bits\n";
    std::cout << "std::uint8_t: " << sizeof(std::uint8_t) * 8 << " bits\n";
    std::cout << "std::int16_t: " << sizeof(std::int16_t) * 8 << " bits\n";
    std::cout << "std::uint16_t: " << sizeof(std::uint16_t) * 8 << " bits\n";
    std::cout << "std::int32_t: " << sizeof(std::int32_t) * 8 << " bits\n";
    std::cout << "std::uint32_t: " << sizeof(std::uint32_t) * 8 << " bits\n";
    std::cout << "std::int64_t: " << sizeof(std::int64_t) * 8 << " bits\n";
    std::cout << "std::uint64_t: " << sizeof(std::uint64_t) * 8 << " bits\n";
    std::cout << '\n';
    std::cout << "least 8: " << sizeof(std::int_least8_t) * 8 << " bits\n";
    std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
    std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
    std::cout << "least 64: " << sizeof(std::int_least64_t) * 8 << " bits\n";
    std::cout << '\n';
    std::cout << "fast 8: " << sizeof(std::int_least8_t) * 8 << " bits\n";
    std::cout << "fast 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
    std::cout << "fast 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
    std::cout << "fast 64: " << sizeof(std::int_least64_t) * 8 << " bits\n";

    return 0;
}
