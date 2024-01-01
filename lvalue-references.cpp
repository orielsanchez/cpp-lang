#include <iostream>

int main()
{
    int x{5};  // x is a regular int variable

    // Note: ampersand in this context doesn't mean "address of", it means
    // "lvaue reference to"
    int& ref{x};  // ref is an lvalue reference variable that can now be used as
                  // an alias for the variable x

    std::cout << x << ref << '\n';  // prints 55

    x = 6;

    std::cout << x << ref << '\n';  // prints 66

    ref = 7;

    std::cout << x << ref << '\n';  // prints 77

    // Lvalue references must be bound to a modifiable lvalue.
    // Lvalue references can't be bound to non-modifiable lvalue or rvalues.
    // Thus, lvalue refs sometimes called 'lvalue references to non-const' or
    // 'non-const reference'
    int y{5};
    int& validRef{y};

    const int z{5};
    int& invalidRef{z};   // invalid, can't bind to a non-modifiable lvalue
    int& invalidRef2{0};  // invalid, can't bind to an rvalue

    // In most cases, type of reference must match type of referent
    double foo{6.0};
    int& invalidRef3{foo};

    // lvalue reference to void are disallowed
    void& g{x};

    // References can't be reseated (changed to refer to another object)
    int p{5};
    int q{6};

    int& bar{p};  // bar is now an alias for p

    bar = q;  // assigns 6 (the value of q) to p (the obhect being referenced by
              // bar)
    // the above line does NOT change bar into a reference to variable q

    // References and referents have independent lifetimes
    // - a reference can be destroyed before the object it is referencing.
    // - the object being referenced can be destroyed before the reference.
    // i.e. when a reference is destroyed before the referent, the referent is
    // not impacted

    // Dangling references - object destroyed before reference? reference is now
    // a dangling reference, and accessing it leads to undefined behavior

    // Reference aren't objects
    // can't have reference to a reference since an lvalue reference must
    // reference an identifiable object
    int var{};
    int& ref1{var};   // an lvalue reference bound to var
    int& ref2{ref1};  // an lvalue reference bound to var

    std::cout << p << '\n';  // user is expecting this to print 5
}  // reference variables follow the same scope and duration rules that normal
   // variable do (they die here)
