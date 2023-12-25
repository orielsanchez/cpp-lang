// Best Practice:
// Give identifiers internal linkage when you have an explicit reason to
// disallow access from other files Consider giving all identifiers you don't
// want accessible to other files internal linkage (use an unnamed namespace for
// this).

// Internal global variable definitions:
static int g_x;    // defines non-initialized internal global variable (zero
                   // initialized by default)
static int g_x{1}; // defines initialized internal global variable

const int g_y{2};     // defines initialized internal global const variable
constexpr int g_y{3}; // defines initialized internal global constexpr variable

// Internal function definitions:
static int foo(){}; // defines internal function
