
#include "TCheckerRunner.h"  // Include the header file that declares the class
//#include "tchecker/build/src/parsing/parsing.hh"  // Include tchecker system declaration header
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <getopt.h>
#include <iostream>
#include <map>
#include <memory>
#include <string>

//#include "concur19.hh"
//#include "tchecker/algorithms/reach/algorithm.hh"
#include "tchecker/parsing/parsing.hh"
#include "tchecker/utils/log.hh"
//#include "zg-covreach.hh"
//#include "zg-reach.hh"

TCheckerRunner::TCheckerRunner(const std::string &input_file) {
    // Parse the system declaration from the input file
    std::shared_ptr<tchecker::parsing::system_declaration_t> sysdecl;
    //sysdecl = tchecker::parsing::parse_system_declaration(input_file);
    sysdecl = tchecker::parsing::parse_system_declaration(input_file);
    if (sysdecl == nullptr) {
        throw std::runtime_error("Failed to parse system declaration from file: " + input_file);
    }
    //tchecker::log_t log;
    //auto sysdecl = tchecker::parsing::parse_system_declaration("model.tck", log);
    //if (!sysdecl) {
    //    std::cerr << "Failed to parse system.\n";
    //    return;
    //}
 
    
}


// Function to count and display locations

