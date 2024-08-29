#include "turing_machine.h"
#include <iostream>

// Constructor
TuringMachine::TuringMachine(const std::string &input)
    : head_position(0), current_state("q1") {
    tape = std::vector<char>(input.begin(), input.end());
}

// Destructor
TuringMachine::~TuringMachine() = default;

// Copy Constructor
TuringMachine::TuringMachine(const TuringMachine &other)
    : tape(other.tape), head_position(other.head_position),
      current_state(other.current_state),
      transition_function(other.transition_function) {}

// Copy assignment operator
TuringMachine &TuringMachine::operator=(const TuringMachine &other) {
    if (this != &other) {
        tape = other.tape;
        head_position = other.head_position;
        current_state = other.current_state;
        transition_function = other.transition_function;
    }
    return *this;
}

// Move Constructor
TuringMachine::TuringMachine(TuringMachine &&other) noexcept
    : tape(std::move(other.tape)), head_position(other.head_position),
      current_state(std::move(other.current_state)),
      transition_function(std::move(other.transition_function)) {
    other.head_position = 0;
}

// Move assignment operator
TuringMachine &TuringMachine::operator=(TuringMachine &&other) noexcept {
    if (this != &other) {
        tape = std::move(other.tape);
        head_position = other.head_position;
        current_state = std::move(other.current_state);
        transition_function = std::move(other.transition_function);

        // Reset other's state
        other.head_position = 0;
    }
    return *this;
}

void TuringMachine::add_transition(const std::string &state, char read,
                                   char write, int move,
                                   const std::string &next_state) {
    transition_function[state][read] = std::make_tuple(write, move, next_state);
}

void TuringMachine::run() {
    while (true) {
        if (current_state == "accept" || current_state == "reject") {
            break;
        }
        char current_symbol = tape[head_position];
        if (transition_function.count(current_state) &&
            transition_function[current_state].count(current_symbol)) {
            auto [write, move, next_state] =
                transition_function[current_state][current_symbol];

            tape[head_position] = write;
            head_position += move;
            current_state = next_state;

            if (head_position < 0) {
                head_position = 0;
            } else if (head_position >= (int)tape.size()) {
                tape.push_back(' ');
            }
        } else {
            current_state = "reject";
        }
    }
}

void TuringMachine::print_tape() const {
    for (auto c : tape) {
        std::cout << c;
    }

    std::cout << std::endl;
}

std::string TuringMachine::get_result() const {
    if (current_state == "accept") {
        return "Accepted";
    } else if (current_state == "reject") {
        return "Rejected";
    } else {
        return "Still running";
    }
}
