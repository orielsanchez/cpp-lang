// My solution
#include <string>

std::string countSheep(int number) {

    std::string output{""};
    for (int i = 1; i <= number; ++i) {
        output = output.append(std::to_string(i)).append(" sheep...");
    }
    return output;
}

// Best Practice
#include <string>

std::string countSheep(int number) {
    std::string res{""};
    for (int i{1}; i <= number; ++i) {
        res += std::to_string(i) + " sheep...";
    }
    return res;
}
