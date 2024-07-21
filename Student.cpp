#include "Student.hpp"

#include <print>

Student::Student() { std::println("Object constructed"); }
Student::~Student() { std::println("Object destroyed"); }
void Student::printName() { std::println("Name is: {}", m_name); }
void Student::setName(std::string name) { this->m_name = name; }
