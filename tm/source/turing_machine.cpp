#include "turing_machine.h"

// Constructor
TuringMachine::TuringMachine(const std::string& input)
    : head_position(0), current_state("q0") {
    tape = std::vector<char>(input.begin(), input.end());
}

// Destructor
TuringMachine::~TuringMachine() = default;

// Copy Constructor
TuringMachine::TuringMachine(const TuringMachine& other)
    : tape(other.tape),
      head_position(other.head_position),
      current_state(other.current_state),
      transition_function(other.transition_function) {}

// Copy assignment operator
TuringMachine& TuringMachine::operator=(const TuringMachine& other) {
    if (this != &other) {
        tape = other.tape;
        head_position = other.head_position;
        current_state = other.current_state;
        transition_function = other.transition_function;
    }
    return *this;
}

// Move Constructor
TuringMachine::TuringMachine(TuringMachine&& other) noexcept
    : tape(std::move(other.tape)),
      head_position(other.head_position),
      current_state(std::move(other.current_state)),
      transition_function(std::move(other.transition_function)) {
    other.head_position = 0;
}

// Move assignment operator
TuringMachine& TuringMachine::operator=(TuringMachine&& other) noexcept {
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

void TuringMachine::add_transition(const std::string& state, char read,
                                   char write, int move,
                                   const std::string& next_state) {
    // somethingf
}
