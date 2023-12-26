#include <cmath>
#include <iostream>

// Statement labels have function scope.
// The label is visible throughout the function even before its point of
// declaration. The goto statement and its corresponding statement label must
// appear in the same function.

void printCats(bool skip) {
    if (skip)
        goto end; // jump forward; statement label 'end' is visible here due to
                  // it having function scope.
    std::cout << "cats\n";

end:; // statement labels must be associated with a statement (null statement in
      // this case)
}

int main() {
    double x{};
tryAgain: // this is a statement label
    std::cout << "Enter a non-negative number: ";
    std::cin >> x;

    if (x < 0.0) {
        goto tryAgain; // this is the goto statement
    }

    std::cout << "The square root of " << x << " is " << std::sqrt(x) << '\n';

    return 0;
}

// Best Practice: Avoid goto statements (unless the alternatives are
// significantly worse for code readability)
