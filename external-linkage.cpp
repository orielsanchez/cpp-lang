// An identifier with external linkage can be seen and used both from the file
// in which it is defined, and from other code files (via a forward
// declaration). In this sense, identifiers with external linkage are truly
// “global” in that they can be used anywhere in your program!

// Warning: If you want to define an uninitialized non-const global variable, do
// not use the extern keyword, otherwise C++ will think you’re trying to make a
// forward declaration for the variable.

// External global variable definitions:
int g_x; // defines non-initialized external global variable (zero initialized
         // by default)
extern const int g_x{1}; // defines initialized const external global variable
extern constexpr int g_x{
    2}; // defines initialized constexpr external global variable

// Forward declarations
extern int g_y;       // forward declaration for non-constant global variable
extern const int g_y; // forward declaration for const global variable
extern constexpr int
    g_y; // not allowed: constexpr variables can't be forward declared
