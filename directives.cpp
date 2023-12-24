#include <iostream>
// Once the preprocessor has finished, all defined identifiers from that file are discarded. This means that directives are only valid from the point of definition to the end of the file in which they are defined. Directives defined in one code file do not have impact on other code files in the same project.
#define PRINT_JOE

// Directives are resolved before compilation, from top to bottom on a file-by-file basis
// For readability, generally want to #define identifiers outside of functions
void foo()
{
#define MY_NAME "Oriel"
}

int main()
{
#ifdef PRINT_JOE
    std::cout << "Joe\n";
#endif

#ifdef PRINT_TIM
    std::cout << "Tim\n";
#endif

#ifndef PRINT_BOB
    std::cout << "Bob\n";
#endif

#if defined(PRINT_MIKE)
    std::cout << "Mike\n";
#endif

#if !defined(PRINT_ZACH)
    std::cout << "Zach\n";
#endif

#if 0
    std::cout << "Hello, world!";
#endif

#if 1
    std::cout << "Hello, world!";
#endif

    // Object-like macros don't affect other preprocessor directives
#define FOO 9
#ifdef FOO // This FOO doesn't get replaced
    std::cout << FOO << "\n"; // This FOO gets replaced with a 9
#endif

    std::cout << "My name is: " << MY_NAME << '\n';

    return 0;
}
