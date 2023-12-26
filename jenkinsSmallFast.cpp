/*! \class small_prng
\brief From http://burtleburtle.net/bob/rand/smallprng.html, a not awful fast
random number source.
*/
class small_prng {
  protected:
    uint32_t a;
    uint32_t b;
    uint32_t c;
    uint32_t d;

    static inline uint32_t rot(uint32_t x, uint32_t k) noexcept {
        return (((x) << (k)) | ((x) >> (32 - (k))));
    }

  public:
    //! The type produced by the small prng
    using value_type = uint32_t;

    //! Construct an instance with `seed`
    explicit small_prng(uint32_t seed = 0xdeadbeef) noexcept {
        a = 0xf1ea5eed;
        b = c = d = seed;
        for (size_t i = 0; i < 20; ++i)
            (*this)();
    }

    //! Return `value_type` of pseudo-randomness
    inline uint32_t operator()() noexcept {
        uint32_t e = a - rot(b, 27);
        a = b ^ rot(c, 17);
        b = c + d;
        c = d + e;
        d = e + a;
        return d;
    }
};
