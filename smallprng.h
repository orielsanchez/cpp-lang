// Bob Jenkins small PRNG in C++ templates (all compile time)
// see original public domain implementation in C
// http://burtleburtle.net/bob/rand/smallprng.html
// http://burtleburtle.net/bob/rand/talksmall.html (for license)
//
// This is put in the public domain by me personally
// Dale Weiler <cube2killfield@gmail.com>
//
// to use: Rotate<seed, cycle>::value
// cycle is the call count, i.e using 0 as cycle is the same as calling the C
// version once 1 would be twice, 2 .. would be 3 times, etc, etc

template <unsigned long int x, unsigned long int y> struct Rotate {
    enum { value = ((x << y) | (x >> (32 - y))) };
};
template <int I, unsigned long int S> struct Context;
template <unsigned long int S> struct Context<0, S> {
    enum { a = 0xF1EA5EED, b = S, c = S, d = S };
};
template <int I, unsigned long int S> struct Context {
    enum {
        e = Context<I - 1, S>::a - Rotate<Context<I - 1, S>::b, 27>::value,
        a = Context<I - 1, S>::b ^ Rotate<Context<I - 1, S>::c, 17>::value,
        b = Context<I - 1, S>::c + Context<I - 1, S>::d,
        c = Context<I - 1, S>::d + e,
        d = e + a,
    };
};
template <unsigned long int S, unsigned int cycle> struct Random {
    enum { value = Context<21 + cycle, S>::d };
};
