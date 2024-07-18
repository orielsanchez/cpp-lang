#include <iostream>

// Key insight: Each template type parameter will resolve its type
// independently. This means a template with two type parameters T and U could
// have T and U resolve to distinct types, or they could resolve to the same
// type.
template <typename T, typename U> auto max(T x, U y) { return (x < y) ? y : x; }

int main() {
    std::cout << max(2, 3.5) << '\n';
    return 0;
}
