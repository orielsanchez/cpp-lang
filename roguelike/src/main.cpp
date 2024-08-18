#include "Person.hpp"

int main() {
    Person joe;
    joe.setName("Joe");

    Person tommy;
    tommy.setName("Tommy");

    joe.kills(tommy);

    return 0;
}
