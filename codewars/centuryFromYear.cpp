int centuryFromYear(int year) {
    int century = 1;
    while (year > 100) {
        year -= 100;
        century++;
    }
    return century;
}

// Best Practice
constexpr int centuryFromYear(int year) { return (year + 99) / 100; }
