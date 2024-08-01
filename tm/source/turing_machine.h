#ifndef TURING_MACHINE_H
#define TURING_MACHINE H

#include <string>
#include <unordered_map>
#include <vector>

class TuringMachine {
   private:
    std::vector<char> tape;
    int head_position;
    std::string current_state;
    std::unordered_map<
        std::string,
        std::unordered_map<char, std::tuple<char, int, std::string>>>
        transition_function;

   public:
    // Constructor
    TuringMachine(const std::string& input);

    // Destructor
    ~TuringMachine();

    // Copy Constructor
    TuringMachine(const TuringMachine& other);

    // Copy assignment operator
    TuringMachine& operator=(const TuringMachine& other);

    // Move constructor
    TuringMachine(TuringMachine&& other) noexcept;

    // Move assignment operator
    TuringMachine& operator=(TuringMachine&& other) noexcept;

    // Add a transition rule to the machine
    void add_transition(const std::string& state, char read, char write,
                        int move, const std::string& next_state);

    // Run the Turing Machine
    void run();

    // Print the current state of the tape
    void print_tape() const;
};

#endif  // TURING_MACHINE_H
