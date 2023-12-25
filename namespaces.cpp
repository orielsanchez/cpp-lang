#include "add.h"
#include "circle.h"
#include "growth.h"
#include <iostream>

// It’s legal to declare namespace blocks in multiple locations (either across
// multiple files, or multiple places within the same file). All declarations
// within the namespace are considered part of the namespace.

// For identifiers inside a namespace, those forward declarations also need to
// be inside the same namespace, as in the case for add.h and add.cpp

namespace Foo {
int doSomething(int x, int y) {
    std::cout << "Hello" << '\n';
    return x + y;
}
} // namespace Foo

namespace Goo {
int doSomething(int x, int y) { return x - y; }
} // namespace Goo

int main() {
    std::cout << Foo::doSomething(4, 3) << '\n';
    std::cout << Goo::doSomething(4, 3) << '\n';

    std::cout << BasicMath::add(4, 5) << '\n';
    std::cout << BasicMath::e << '\n';
    std::cout << BasicMath::pi << '\n';
    return 0;
}
