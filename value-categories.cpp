int return5() { return 5; }

// Key insight
// A rule of thumb to identify lvalue and rvalue expressions:
// Lvalue expressions are those that evaluate to variables or other identifiable
// objects that persist beyond the end of the expression. Rvalue expressions are
// those that evaluate to literals or values returned by functions/operators
// that are discarded at the end of the expression.

int main() {
    int x{5};            // 5 is an rvalue expression
    const double d{1.2}; // 1.2 is an rvalue expression

    int y{x};          // x is a modifiable lvalue expression
    const double e{d}; // d is a non-modifiable lvalue expression
    int z{return5()};  // return5() is an rvalue expression (since the result is
                       // returned by value)
    int w{x + 1};      // x +1 is an rvalue expression
    int q{static_cast<int>(
        d)}; // the result of static casting d to an int is an rvalue expresion.

    // Key insight:
    // Lvalue expresions evaluate to an identifiable object (has address)
    // Rvalue expressions evaluate to a value.
    //
    // lvalue expressions will implicitly convert to rvalue expressions in
    // contexts where an rvalue is expected but an lvalue is provided
}
