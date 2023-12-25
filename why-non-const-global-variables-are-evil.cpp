// Best practice
// Use local variables instead of global variables whenever possible.
#include <iostream>

int g_mode; // declare global variable (will be zero-initialized by default)

namespace constants {
constexpr double gravity{9.8};
}

// This function can calculate the instant velocity for any gravity value (more
// useful)
double instantVelocity(int time, double gravity) { return gravity * time; }

void doSomething() {
    g_mode = 2; // set the global g_mode variable to 2
}

int main() {
    g_mode = 1; // note: this sets the global g_mode variable to 1.  It does not
                // declare a local g_mode variable!

    doSomething();

    // Programmer still expects g_mode to be 1
    // But doSomething changed it to 2!

    if (g_mode == 1) {
        std::cout << "No threat detected.\n";
    } else {
        std::cout << "Launching nuclear missiles...\n";
    }

    std::cout << instantVelocity(5, constants::gravity)
              << '\n'; // pass our constant to the function as a parameter

    return 0;
}
