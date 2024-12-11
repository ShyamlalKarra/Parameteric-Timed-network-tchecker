#include <iostream>     // For std::cerr and std::endl
#include <exception>    // For std::exception
#include "TCheckerRunner.h"  // Include the TCheckerRunner class declaration

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    try {
        TCheckerRunner runner(argv[1]); // Pass input file to TCheckerRunner
        runner.output_number_of_states(); // Call the function to output states
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
