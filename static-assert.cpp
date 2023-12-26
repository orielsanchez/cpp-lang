static_assert(sizeof(long) == 8, "long must be 8 bytes");
static_assert(sizeof(int) >= 4, "int must be at least 4 bytes");

int main() { return 0; }

// A few useful notes about static_assert:
// - Because static_assert is evaluated by the compiler, the condition must be a
// constant expression.
// - static_assert can be placed anywhere in the code file (even in the global
// namespace).
// - static_assert is not compiled out in release builds.

// Prior to C++17, the diagnostic message must be supplied as the second
// parameter. Since C++17, providing a diagnostic message is optional.
