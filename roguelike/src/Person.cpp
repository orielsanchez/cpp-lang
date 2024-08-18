#include "Person.hpp"
#include <print>
void Person::kills(const Person &person) const {
    std::println("{} kills {}", m_name, person.m_name);
}

void Person::setName(std::string_view name) { m_name = name; }
