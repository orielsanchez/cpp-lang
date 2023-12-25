// A reminder
// Constexpr functions are implicitly inline,
// but constexpr variables not implicitly inline.
#ifndef CONSTANTS_H
#define CONSTANTS_H

// define your own namespace to hold constants
namespace constants {
inline constexpr double pi{3.14159};
inline constexpr double avagadro{6.0221413e23};
inline constexpr double myGravity{9.8};
} // namespace constants

#endif // !CONSTANTS_H
