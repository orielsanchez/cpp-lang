#include <iostream>
// Best Practice
// Parenthesize the entire conditional operator when used in a compound expression
// For readability, parenthesize the condition if it contains any operators (other than the function call operator)
bool isAfternoon(int time)
{
    if (time >= 12)
        return true;
    else
        return false;
}

int main()
{
    int x { 2 };
    int y { 1 };
    int z { 10 - x > y ? x : y }; // evals to 2
    int q { 10 - (x > y ? x : y) }; // evals to 8
    std::cout << z + q << '\n';

    int r { (x > y) ? x : y }; // not used in compound expression, condition contains operators
    std::cout << r << '\n';
    std::cout << (isAfternoon(12) ? "PM" : "AM"); // used in compound expression, condition contains no operators (function call operator excluded)
    std::cout << ((x > y) ? x : y); // used in compound expression, condition contains operators

    // Type of the expression must match or be convertible
    std::cout << (true ? 1 : 2) << '\n'; // okay : both operands have matching type int
    std::cout << (false ? 1 : 2.2) << '\n'; // okay : int value 1 converted to double
    std::cout << (true ? -1 : 2u) << '\n'; // surprising result: -1 converted to unsigned int, result out of range

    bool isStunned = true;
    int movesLeft = 1;
    return isStunned ? 0 : movesLeft; // not used in compound expression, condition contains no operators => no need for parenthesis
}
