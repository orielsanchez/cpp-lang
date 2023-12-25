#include <iostream>
#include <string>
#include <string_view>

// std::string_View is best used as a read-only paramter
void printSV(std::string_view str)
{
    std::cout << str << '\n';
}

std::string getName()
{
    std::string s { "Alex" };
    return s;
}

// std::string_view can be used as return value, but is often dangerous.
std::string_view getBoolName(bool b)
{
    std::string t { "true" }; // local variable
    std::string f { "false" }; // local variable

    if (b)
        return t;
    return f;
} // t and f are destroyed at the end of the function

// C-style string literals okay because they exist for the entire program
std::string_view getBoolName2(bool b)
{
    if (b)
        return "true";
    return "false";
}

// okay because arguments passed in still exist inside scope of caller
std::string_view firstAlphabetical(std::string_view s1, std::string_view s2)
{
    return s1 < s2 ? s1 : s2;
}
int main()
{
    std::string s { "Hello, world!" };
    printSV(s);

    // Improperly using std::string_view
    std::string_view sv {};

    { // create a nested block
        std::string s { "Hello, world!" }; // create a std::string local to this nested block
        sv = s; // sv is now viewing s
    } // s is destroyed here, so sv is now viewing an invalid string

    std::cout << sv << '\n'; // undefined behavior
    printSV(sv); // undefined behavior

    // The getName() function is returning a std::string containing the string “Alex”.
    // Return values are temporary objects that are destroyed at the end of the full expression containing the function call.
    // We must either use this return value immediately, or copy it to use later.
    std::string_view name { getName() };
    std::cout << name << '\n'; // undefined behavior

    // Warning:
    // Do not initialize a std::string_view with a std::string literal, as this will leave the std::string_view dangling.
    // It is okay to initialize a std::string_view with a C-style string literal or a std::string_view literal.
    // It’s also okay to initialize a std::string_view with a C-style string object, a std::string object,
    // or a std::string_view object, as long as that string object outlives the view.

    std::string_view sv1 { s }; // sv1 is now viewing s

    s = "Hello, universe!"; // modifies s, which invalidates sv (s is still valid)
    std::cout << sv1 << '\n'; // undefined behavior

    sv1 = s; // revalidates sv1: sv1 is now viewing s again
    std::cout << sv1 << '\n';

    std::cout << getBoolName(true) << ' ' << getBoolName(false) << '\n'; // undefined behavior

    std::string a { "World" };
    std::string b { "Hello" };

    std::cout << firstAlphabetical(a, b) << '\n';
    // Warning:
    // If an argument is a temporary that is destroyed at the end of the full expression containing the function call,
    // the returned std::string_view must be used immediately, as it will be left dangling after the temporary is destroyed.

    // Key Insight
    // A C-style string literal and a std::string are always null-terminated.
    // A std::string_view may or may not be null-terminated.

    std::string_view str { "Peach" };
    std::cout << str << '\n'; // Peach

    // Remove 1 character from the left side of the view
    str.remove_prefix(1);
    std::cout << str << '\n'; // each

    // Remove 2 characters from the right side of the view
    str.remove_suffix(2);
    std::cout << str << '\n'; // ea

    str = "Peach"; // reset the view
    std::cout << str << '\n'; // Peach
    return 0;
}
