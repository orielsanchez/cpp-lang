#include <iostream>

inline namespace V1 {
void doSomething() { std::cout << "V1\n"; }
} // namespace V1

namespace V2 {
void doSomething() { std::cout << "V2\n"; }
} // namespace V2

int main() {
    V1::doSomething();
    V2::doSomething();

    doSomething(); // prints V1 version b/c inline

    return 0;
}
