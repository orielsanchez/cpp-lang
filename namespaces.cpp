#include <iostream>

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
    return 0;
}
