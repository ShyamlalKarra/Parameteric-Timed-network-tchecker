#ifndef TCHECKER_RUNNER_H
#define TCHECKER_RUNNER_H

#include <string>
#include <stdexcept>
#include "tchecker/parsing/parsing.hh"

class TCheckerRunner {
public:
    /**
     * Constructor
     * Initializes the runner with a system declaration parsed from the input file.
     * 
     * @param input_file Path to the tchecker input file describing the system
     */
    TCheckerRunner(const std::string &input_file);

    /**
     * Outputs the number of states in the system declaration.
     */
    void output_number_of_states() const;

private:
    tchecker::parsing::system_declaration_t *sysdecl; // Pointer to the system declaration object
};

#endif
