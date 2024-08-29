#include "turing_machine.h"
#include <iostream>
int main(int argc, char *argv[]) {
    // https://en.wikipedia.org/wiki/Turing_machine_examples#A_copy_subroutine
    // TuringMachine tm1{"111"};

    if (argc != 2) {
        std::cerr << "Error: Needs initial tape string e.g. 101110"
                  << std::endl;
        return -1;
    }

    std::string input = argv[1];

    // M_2 that decides A = \{ 0^{2^n} \mid n \ge 0 \}
    TuringMachine tm{input};

    tm.add_transition("q1", ' ', ' ', 1, "reject");
    tm.add_transition("q1", 'x', 'x', 1, "reject");
    tm.add_transition("q1", '0', ' ', 1, "q2");
    tm.add_transition("q2", 'x', 'x', 1, "q2");
    tm.add_transition("q2", ' ', ' ', 1, "accept");
    tm.add_transition("q2", '0', 'x', 1, "q3");
    tm.add_transition("q3", 'x', 'x', 1, "q3");
    tm.add_transition("q3", ' ', ' ', -1, "q5");
    tm.add_transition("q3", '0', '0', 1, "q4");
    tm.add_transition("q5", '0', '0', -1, "q5");
    tm.add_transition("q5", 'x', 'x', -1, "q5");
    tm.add_transition("q5", ' ', ' ', 1, "q2");
    tm.add_transition("q4", '0', 'x', 1, "q3");
    tm.add_transition("q4", 'x', 'x', 1, "q4");
    tm.add_transition("q4", ' ', ' ', 1, "reject");

    tm.run();
    tm.print_tape();
    std::cout << "Result: " << tm.get_result() << std::endl;

    return 0;
}
