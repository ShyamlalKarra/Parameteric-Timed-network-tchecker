/*
 * This file is a part of the TChecker project.
 *
 * See files AUTHORS and LICENSE for copyright details.
 *
 */

#include <fstream>
#include <getopt.h>
#include <iostream>
#include <map>
#include <memory>
#include <string>

#include "concur19.hh"
#include "tchecker/algorithms/reach/algorithm.hh"
#include "tchecker/parsing/parsing.hh"
#include "tchecker/utils/log.hh"
#include "zg-covreach.hh"
#include "zg-reach.hh"
//#include "TCheckerRunner.h"

//void count_locations(const tchecker::parsing::system_declaration_t & sysdecl);


/*!
 \file tck-reach.cc
 \brief Reachability analysis of timed automata
 */

static struct option long_options[] = {{"algorithm", required_argument, 0, 'a'},
                                       {"certificate", required_argument, 0, 'C'},
                                       {"output", required_argument, 0, 'o'},
                                       {"help", no_argument, 0, 'h'},
                                       {"labels", required_argument, 0, 'l'},
                                       {"search-order", no_argument, 0, 's'},
                                       {"block-size", required_argument, 0, 0},
                                       {"table-size", required_argument, 0, 0},
                                       {0, 0, 0, 0}};

static char const * const options = (char *)"a:C:hl:o:s:";

/*!
  \brief Display usage
  \param progname : programme name
*/
void usage(char * progname)
{
  std::cerr << "Usage: " << progname << " [options] [file]" << std::endl;
  std::cerr << "   -a algorithm  reachability algorithm" << std::endl;
  std::cerr << "          reach      standard reachability algorithm over the zone graph" << std::endl;
  std::cerr << "          concur19   reachability algorithm with covering over the local-time zone graph" << std::endl;
  std::cerr << "          covreach   reachability algorithm with covering over the zone graph" << std::endl;
  std::cerr << "   -C type       type of certificate" << std::endl;
  std::cerr << "          none       no certificate (default)" << std::endl;
  std::cerr << "          graph      graph of explored state-space" << std::endl;
  std::cerr << "          symbolic   symbolic run to a state with searched labels if any" << std::endl;
  std::cerr << "          concrete   concrete run to a state with searched labels if any (only for reach and covreach)"
            << std::endl;
  std::cerr << "   -h            help" << std::endl;
  std::cerr << "   -l l1,l2,...  comma-separated list of searched labels" << std::endl;
  std::cerr << "   -o out_file   output file for certificate (default is standard output)" << std::endl;
  std::cerr << "   -s bfs|dfs    search order" << std::endl;
  std::cerr << "   --block-size  size of allocation blocks" << std::endl;
  std::cerr << "   --table-size  size of hash tables" << std::endl;
  std::cerr << "reads from standard input if file is not provided" << std::endl;
}

enum algorithm_t {
  ALGO_REACH,    /*!< Reachability algorithm */
  ALGO_CONCUR19, /*!< Covering reachability algorithm over the local-time zone graph */
  ALGO_COVREACH, /*!< Covering reachability algorithm */
  ALGO_NONE,     /*!< No algorithm */
};

enum certificate_t {
  CERTIFICATE_GRAPH,    /*!< Graph of state-space */
  CERTIFICATE_SYMBOLIC, /*!< Symbolic counter-example */
  CERTIFICATE_CONCRETE, /*!< Concrete counter-example */
  CERTIFICATE_NONE,     /*!< No certificate */
};

static enum algorithm_t algorithm = ALGO_NONE;            /*!< Selected algorithm */
static bool help = false;                                 /*!< Help flag */
static enum certificate_t certificate = CERTIFICATE_NONE; /*!< Type of certificate */
static std::string search_order = "bfs";                  /*!< Search order */
static std::string labels = "";                           /*!< Searched labels */
static std::string output_file = "";                      /*!< Output file name (empty means standard output) */
static std::ostream * os = &std::cout;                    /*!< Default output stream */
static std::size_t block_size = 10000;                    /*!< Size of allocated blocks */
static std::size_t table_size = 65536;                    /*!< Size of hash tables */

/*!
 \brief Check if expected certificate is a path
 \param ctype : certificate type
 \return true if ctype is a path, false otherwise
 */
static bool is_certificate_path(enum certificate_t ctype)
{
  return (ctype == CERTIFICATE_SYMBOLIC || ctype == CERTIFICATE_CONCRETE);
}

/*!
 \brief Parse command-line arguments
 \param argc : number of arguments
 \param argv : array of arguments
 \pre argv[0] up to argv[argc-1] are valid accesses
 \post global variables help, output_file, search_order and labels have been set
 from argv
*/
int parse_command_line(int argc, char * argv[])
{
  while (true) {
    int long_option_index = -1;
    int c = getopt_long(argc, argv, options, long_options, &long_option_index);

    if (c == -1)
      break;

    if (c == ':')
      throw std::runtime_error("Missing option parameter");
    else if (c == '?')
      throw std::runtime_error("Unknown command-line option");
    else if (c != 0) {
      switch (c) {
      case 'a':
        if (strcmp(optarg, "reach") == 0)
          algorithm = ALGO_REACH;
        else if (strcmp(optarg, "concur19") == 0)
          algorithm = ALGO_CONCUR19;
        else if (strcmp(optarg, "covreach") == 0)
          algorithm = ALGO_COVREACH;
        else
          throw std::runtime_error("Unknown algorithm: " + std::string(optarg));
        break;
      case 'C':
        if (strcmp(optarg, "none") == 0)
          certificate = CERTIFICATE_NONE;
        else if (strcmp(optarg, "graph") == 0)
          certificate = CERTIFICATE_GRAPH;
        else if (strcmp(optarg, "concrete") == 0)
          certificate = CERTIFICATE_CONCRETE;
        else if (strcmp(optarg, "symbolic") == 0)
          certificate = CERTIFICATE_SYMBOLIC;
        else
          throw std::runtime_error("Unknown type of certificate: " + std::string(optarg));
        break;
      case 'o':
        output_file = optarg;
        break;
      case 'h':
        help = true;
        break;
      case 'l':
        labels = optarg;
        break;
      case 's':
        search_order = optarg;
        break;
      default:
        throw std::runtime_error("This should never be executed");
        break;
      }
    }
    else {
      if (strcmp(long_options[long_option_index].name, "block-size") == 0)
        block_size = std::strtoull(optarg, nullptr, 10);
      else if (strcmp(long_options[long_option_index].name, "table-size") == 0)
        table_size = std::strtoull(optarg, nullptr, 10);
      else
        throw std::runtime_error("This also should never be executed");
    }
  }

  return optind;
}

/*!
 \brief Load a system declaration from a file
 \param filename : file name
 \return pointer to a system declaration loaded from filename, nullptr in case
 of errors
 \post all errors have been reported to std::cerr
*/
std::shared_ptr<tchecker::parsing::system_declaration_t> load_system_declaration(std::string const & filename)
{
  std::shared_ptr<tchecker::parsing::system_declaration_t> sysdecl{nullptr};
  try {
    sysdecl = tchecker::parsing::parse_system_declaration(filename);
    if (sysdecl == nullptr)
      throw std::runtime_error("nullptr system declaration");
  }
  catch (std::exception const & e) {
    std::cerr << tchecker::log_error << e.what() << std::endl;
  }
  return sysdecl;
}

/*!
 \brief Perform reachability analysis
 \param sysdecl : system declaration
 \post statistics on reachability analysis of command-line specified labels in
 the system declared by sysdecl have been output to standard output.
 A certification has been output if required.
*/
void reach(tchecker::parsing::system_declaration_t const & sysdecl)
{
  auto && [stats, graph] = tchecker::tck_reach::zg_reach::run(sysdecl, labels, search_order, block_size, table_size);

  // stats
  std::map<std::string, std::string> m;
  stats.attributes(m);
  for (auto && [key, value] : m)
    std::cout << key << " " << value << std::endl;

  // certificate
  if (certificate == CERTIFICATE_GRAPH)
    tchecker::tck_reach::zg_reach::dot_output(*os, *graph, sysdecl.name());
  else if ((certificate == CERTIFICATE_CONCRETE) && stats.reachable()) {
    std::unique_ptr<tchecker::tck_reach::zg_reach::cex::concrete_cex_t> cex{
        tchecker::tck_reach::zg_reach::cex::concrete_counter_example(*graph)};
    if (cex->empty())
      throw std::runtime_error("Unable to compute a concrete counter example");
    tchecker::tck_reach::zg_reach::cex::dot_output(*os, *cex, sysdecl.name());
  }
  else if ((certificate == CERTIFICATE_SYMBOLIC) && stats.reachable()) {
    std::unique_ptr<tchecker::tck_reach::zg_reach::cex::symbolic_cex_t> cex{
        tchecker::tck_reach::zg_reach::cex::symbolic_counter_example(*graph)};
    if (cex->empty())
      throw std::runtime_error("Unable to compute a symbolic counter example");
    tchecker::tck_reach::zg_reach::cex::dot_output(*os, *cex, sysdecl.name());
  }
}

/*!
 \brief Perform covering reachability analysis over the local-time zone graph
 \param sysdecl : system declaration
 \post statistics on covering reachability analysis of command-line specified
 labels in the system declared by sysdecl have been output to standard output.
 A certification has been output if required.
 \note This is the algorithm presented in R. Govind, Frédéric Herbreteau, B.
 Srivathsan, Igor Walukiewicz: "Revisiting Local Time Semantics for Networks of
 Timed Automata". CONCUR 2019: 16:1-16:15
*/
void concur19(tchecker::parsing::system_declaration_t const & sysdecl)
{
  tchecker::algorithms::covreach::stats_t stats;
  std::shared_ptr<tchecker::tck_reach::concur19::graph_t> graph;

  if (certificate == CERTIFICATE_CONCRETE)
    throw std::runtime_error("Concrete counter-example is not available for concur19 algorithm");

  tchecker::algorithms::covreach::covering_t covering =
      (is_certificate_path(certificate) ? tchecker::algorithms::covreach::COVERING_LEAF_NODES
                                        : tchecker::algorithms::covreach::COVERING_FULL);

  std::tie(stats, graph) = tchecker::tck_reach::concur19::run(sysdecl, labels, search_order, covering, block_size, table_size);

  // stats
  std::map<std::string, std::string> m;
  stats.attributes(m);
  for (auto && [key, value] : m)
    std::cout << key << " " << value << std::endl;

  // certificate
  if (certificate == CERTIFICATE_GRAPH)
    tchecker::tck_reach::concur19::dot_output(*os, *graph, sysdecl.name());
  else if ((certificate == CERTIFICATE_SYMBOLIC) && stats.reachable()) {
    std::unique_ptr<tchecker::tck_reach::concur19::cex::symbolic::cex_t> cex{
        tchecker::tck_reach::concur19::cex::symbolic::counter_example(*graph)};
    if (cex->empty())
      throw std::runtime_error("Unable to compute a symbolic counter example");
    tchecker::tck_reach::concur19::cex::symbolic::dot_output(*os, *cex, sysdecl.name());
  }
}

/*!
 \brief Perform covering reachability analysis
 \param sysdecl : system declaration
 \post statistics on covering reachability analysis of command-line specified
 labels in the system declared by sysdecl have been output to standard output.
 A certification has been output if required.
*/
void covreach(tchecker::parsing::system_declaration_t const & sysdecl)
{
  tchecker::algorithms::covreach::stats_t stats;
  std::shared_ptr<tchecker::tck_reach::zg_covreach::graph_t> graph;

  tchecker::algorithms::covreach::covering_t covering =
      (is_certificate_path(certificate) ? tchecker::algorithms::covreach::COVERING_LEAF_NODES
                                        : tchecker::algorithms::covreach::COVERING_FULL);

  std::tie(stats, graph) =
      tchecker::tck_reach::zg_covreach::run(sysdecl, labels, search_order, covering, block_size, table_size);

  // stats
  std::map<std::string, std::string> m;
  stats.attributes(m);
  for (auto && [key, value] : m)
    std::cout << key << " " << value << std::endl;

  // certificate
  if (certificate == CERTIFICATE_GRAPH)
    tchecker::tck_reach::zg_covreach::dot_output(*os, *graph, sysdecl.name());
  else if ((certificate == CERTIFICATE_CONCRETE) && stats.reachable()) {
    std::unique_ptr<tchecker::tck_reach::zg_covreach::cex::concrete_cex_t> cex{
        tchecker::tck_reach::zg_covreach::cex::concrete_counter_example(*graph)};
    if (cex->empty())
      throw std::runtime_error("Unable to compute a concrete counter example");
    tchecker::tck_reach::zg_covreach::cex::dot_output(*os, *cex, sysdecl.name());
  }
  else if ((certificate == CERTIFICATE_SYMBOLIC) && stats.reachable()) {
    std::unique_ptr<tchecker::tck_reach::zg_covreach::cex::symbolic_cex_t> cex{
        tchecker::tck_reach::zg_covreach::cex::symbolic_counter_example(*graph)};
    if (cex->empty())
      throw std::runtime_error("Unable to compute a symbolic counter example");
    tchecker::tck_reach::zg_covreach::cex::dot_output(*os, *cex, sysdecl.name());
  }
}

/*!
 \brief Main function
*/
/*

int main(int argc, char * argv[])
{
  try {
    int optindex = parse_command_line(argc, argv);

    if (argc - optindex > 1) {
      std::cerr << "Too many input files" << std::endl;
      usage(argv[0]);
      return EXIT_FAILURE;
    }

    if ((certificate == CERTIFICATE_CONCRETE) && (algorithm != ALGO_COVREACH) && (algorithm != ALGO_REACH)) {
      std::cerr << "Concrete counter-example is only available for algorithms covreach and reach" << std::endl;
      return EXIT_FAILURE;
    }

    if (help) {
      usage(argv[0]);
      return EXIT_SUCCESS;
    }

    std::string input_file = (optindex == argc ? "" : argv[optindex]);

    std::shared_ptr<tchecker::parsing::system_declaration_t> sysdecl{load_system_declaration(input_file)};

    if (tchecker::log_error_count() > 0)
      return EXIT_FAILURE;

    std::shared_ptr<std::ofstream> os_ptr{nullptr};

    if (certificate != CERTIFICATE_NONE && output_file != "") {
      try {
        os_ptr = std::make_shared<std::ofstream>(output_file);
        os = os_ptr.get();
      }
      catch (std::exception & e) {
        std::cerr << tchecker::log_error << e.what() << std::endl;
        return EXIT_FAILURE;
      }
    }

    switch (algorithm) {
    case ALGO_REACH:
      reach(*sysdecl);
      break;
    case ALGO_CONCUR19:
      concur19(*sysdecl);
      break;
    case ALGO_COVREACH:
      covreach(*sysdecl);
      break;
    default:
      throw std::runtime_error("No algorithm specified");
    }
  }
  catch (std::exception & e) {
    std::cerr << tchecker::log_error << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
*/


int main(int argc, char * argv[])
{
    try {
        int optindex = parse_command_line(argc, argv);

        if (argc - optindex > 1) {
            std::cerr << "Too many input files" << std::endl;
            usage(argv[0]);
            return EXIT_FAILURE;
        }

        if ((certificate == CERTIFICATE_CONCRETE) && (algorithm != ALGO_COVREACH) && (algorithm != ALGO_REACH)) {
            std::cerr << "Concrete counter-example is only available for algorithms covreach and reach" << std::endl;
            return EXIT_FAILURE;
        }

        if (help) {
            usage(argv[0]);
            return EXIT_SUCCESS;
        }

        std::string input_file = (optindex == argc ? "" : argv[optindex]);

        // Parse the system declaration
        std::shared_ptr<tchecker::parsing::system_declaration_t> sysdecl{load_system_declaration(input_file)};

        if (tchecker::log_error_count() > 0)
            return EXIT_FAILURE;

        std::shared_ptr<std::ofstream> os_ptr{nullptr};

        if (certificate != CERTIFICATE_NONE && output_file != "") {
            try {
                os_ptr = std::make_shared<std::ofstream>(output_file);
                os = os_ptr.get();
            }
            catch (std::exception & e) {
                std::cerr << tchecker::log_error << e.what() << std::endl;
                return EXIT_FAILURE;
            }
        }

        switch (algorithm) {
    case ALGO_REACH: {
      // Initialize components for generateTrace
      tchecker::zg::zg_t ts(*sysdecl);  // Transition system
      tchecker::zg::graph_t graph(ts.system().locations_count());  // Graph
      boost::dynamic_bitset<> labels(ts.system().locations_count());
      tchecker::algorithms::reach::stats_t stats;

      // Specify the target location
      std::string target_location = "ql";  // Replace with your target location name

      // Create an algorithm instance
      tchecker::algorithms::reach::algorithm_t<tchecker::zg::zg_t, tchecker::zg::graph_t> algorithm;

      // Call generateTrace
      auto trace = algorithm.generateTrace(ts, graph, labels, *tchecker::waiting::factory<tchecker::zg::graph_t::node_sptr_t>(
                                                                 tchecker::waiting::policy_t::FIFO),
                                            stats, target_location);

      // Output the generated trace
      std::cout << "Generated trace to location " << target_location << ":\n";
      for (const auto & [event, zone] : trace) {
        std::cout << "Event: " << event << ", Zone: " << zone << std::endl;
      }
      break;
    }
    case ALGO_CONCUR19:
      concur19(*sysdecl);
      break;
    case ALGO_COVREACH:
      covreach(*sysdecl);
      break;
    default:
      throw std::runtime_error("No algorithm specified");
    }
  }
  catch (std::exception & e) {
    std::cerr << tchecker::log_error << e.what() << std::endl;
    return EXIT_FAILURE;
  }

    return EXIT_SUCCESS;
}



/* MAIN FUNCTION EDITED*/

/*
int main(int argc, char * argv[])
{
  try {
    int optindex = parse_command_line(argc, argv);

    if (argc - optindex > 1) {
      std::cerr << "Too many input files" << std::endl;
      usage(argv[0]);
      return EXIT_FAILURE;
    }

    if ((certificate == CERTIFICATE_CONCRETE) && (algorithm != ALGO_COVREACH) && (algorithm != ALGO_REACH)) {
      std::cerr << "Concrete counter-example is only available for algorithms covreach and reach" << std::endl;
      return EXIT_FAILURE;
    }

    if (help) {
      usage(argv[0]);
      return EXIT_SUCCESS;
    }

    std::string input_file = (optindex == argc ? "" : argv[optindex]);

    std::shared_ptr<tchecker::parsing::system_declaration_t> sysdecl{load_system_declaration(input_file)};

    if (tchecker::log_error_count() > 0)
      return EXIT_FAILURE;

    std::shared_ptr<std::ofstream> os_ptr{nullptr};

    if (certificate != CERTIFICATE_NONE && output_file != "") {
      try {
        os_ptr = std::make_shared<std::ofstream>(output_file);
        os = os_ptr.get();
      }
      catch (std::exception & e) {
        std::cerr << tchecker::log_error << e.what() << std::endl;
        return EXIT_FAILURE;
      }
    }

    switch (algorithm) {
    case ALGO_REACH: {
      // Initialize components for generateTrace
      tchecker::zg::zg_t ts(*sysdecl);  // Transition system
      tchecker::zg::graph_t graph(ts.system().locations_count());  // Graph
      boost::dynamic_bitset<> labels(ts.system().locations_count());
      tchecker::algorithms::reach::stats_t stats;

      // Specify the target location
      std::string target_location = "ql";  // Replace with your target location name

      // Create an algorithm instance
      tchecker::algorithms::reach::algorithm_t<tchecker::zg::zg_t, tchecker::zg::graph_t> algorithm;

      // Call generateTrace
      auto trace = algorithm.generateTrace(ts, graph, labels, *tchecker::waiting::factory<tchecker::zg::graph_t::node_sptr_t>(
                                                                 tchecker::waiting::policy_t::FIFO),
                                            stats, target_location);

      // Output the generated trace
      std::cout << "Generated trace to location " << target_location << ":\n";
      for (const auto & [event, zone] : trace) {
        std::cout << "Event: " << event << ", Zone: " << zone << std::endl;
      }
      break;
    }
    case ALGO_CONCUR19:
      concur19(*sysdecl);
      break;
    case ALGO_COVREACH:
      covreach(*sysdecl);
      break;
    default:
      throw std::runtime_error("No algorithm specified");
    }
  }
  catch (std::exception & e) {
    std::cerr << tchecker::log_error << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
*/




/*
int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    try {
        //tchecker::log_t log;
        //auto sysdecl = tchecker::parsing::parse_system_declaration("model.tck", log);
        auto sysdecl = tchecker::parsing::parse_system_declaration( argv[1]);
       
        if (!sysdecl) {
          std::cerr << "Failed to parse system.\n";
          return -1;
        }

       // TCheckerRunner runner(argv[1]); // Pass input file to TCheckerRunner
       //count_locations(*sysdecl);// Call the function to output states
       size_t location_count = 0;

    for (const auto &decl : *sysdecl) {

      if (auto location = dynamic_cast<const tchecker::parsing::location_declaration_t *>(decl)) {
        std::cout << "Location Name: " << location->name() << "\n";
    }
        //if (auto location = dynamic_cast<const tchecker::parsing::location_declaration_t *>(decl)) {
          //  std::cout << "Location Name: " << location->name() << "\n";

            // Use the print function
            //print_location_attributes(location->attributes());

            //++location_count;
        //}
    }

    std::cout << "Total Locations: " << location_count << "\n";
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}


void count_locations(const tchecker::parsing::system_declaration_t & sysdecl) {
    size_t location_count = 0;

    // Iterate over locations in the system declaration
    for (const auto & decl : sysdecl.locations()) {
        const auto & location = dynamic_cast<const tchecker::parsing::location_declaration_t &>(*decl);
        std::cout << "Location Name: " << location.name() << "\n";
        ++location_count;
    }

    std::cout << "Total Locations: " << location_count << "\n";
}


// Function to count and display locations
void count_locations(const tchecker::parsing::system_declaration_t &sysdecl) {
    size_t location_count = 0;
    //std::cout << "AM INSIDE " ;
          
    // Iterate over declarations
    for (const auto &decl : sysdecl.declarations()) { 
        // Check if this declaration is a location
        if (auto location = dynamic_cast<const tchecker::parsing::location_declaration_t *>(decl.get())) {
            std::cout << "Parsing Locations:Location Name: " << location->name() << "\n";
            ++location_count;
        }
    }

    std::cout << "Total Locations: " << location_count << "\n";
}

void explore_zone_graph(std::shared_ptr<tchecker::ta::system_t const> system) {
    // Create the zone graph
    std::shared_ptr<tchecker::zg::zg_t> zone_graph(tchecker::zg::factory(
        system, tchecker::ts::SHARING, tchecker::zg::ELAPSED_SEMANTICS, tchecker::zg::NO_EXTRAPOLATION, 1024, 1024));

    // Initialize and explore the zone graph
    std::vector<tchecker::zg::zg_t::sst_t> initial_states;
    zone_graph->initial(initial_states);

    std::cout << "Initial States:\n";
    for (const auto &[status, state, trans] : initial_states) {
        std::cout << "State: " << state->vloc()
                  << ", Zone: " << tchecker::to_string(state->zone(), system->clock_variables().flattened().index()) << std::endl;
    }

    // Explore the zone graph
    std::cout << "\nZone Graph Exploration:\n";
    for (const auto &[status, state, trans] : initial_states) {
        std::vector<tchecker::zg::zg_t::sst_t> successors;
        zone_graph->next(tchecker::zg::const_state_sptr_t{state}, successors, tchecker::STATE_OK);

        for (const auto &[s_status, succ_state, succ_trans] : successors) {
            std::cout << "From State: " << state->vloc() << " -> To State: " << succ_state->vloc()
                      << ", Zone: " << tchecker::to_string(succ_state->zone(), system->clock_variables().flattened().index()) << std::endl;
        }
    }
}

void explore_zone_graph(const std::string &input_file, const std::string &labels = "") {
    // Parse the system
    auto system = parse_system(input_file);

    // Create the zone graph
    std::shared_ptr<tchecker::zg::zg_t> zone_graph = tchecker::zg::factory(
        system, tchecker::ts::SHARING, tchecker::zg::ELAPSED_SEMANTICS, tchecker::zg::NO_EXTRAPOLATION, 1024, 1024);

    // Create the reachability graph
    std::shared_ptr<tchecker::tck_reach::zg_reach::graph_t> graph =
        std::make_shared<tchecker::tck_reach::zg_reach::graph_t>(zone_graph, 1024, 1024);

    // Run the reachability algorithm
    tchecker::tck_reach::zg_reach::algorithm_t algorithm;
    boost::dynamic_bitset<> accepting_labels = system->as_syncprod_system().labels(labels);

    tchecker::algorithms::reach::stats_t stats = algorithm.run(*zone_graph, *graph, accepting_labels, tchecker::waiting::DFS);

    // Print the results
    std::cout << "Zone Graph Exploration:\n";
    for (auto const &node : graph->nodes()) {
        std::cout << "State: " << node->state()->vloc() << ", Zone: "
                  << tchecker::to_string(node->state()->zone(), system->clock_variables().flattened().index()) << "\n";

        for (auto const &edge : graph->outgoing_edges(node)) {
            auto const &target_node = graph->target(edge);
            std::cout << "  Transition to State: " << target_node->state()->vloc() << ", Zone: "
                      << tchecker::to_string(target_node->state()->zone(), system->clock_variables().flattened().index())
                      << "\n";
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <system_file>\n";
        return 1;
    }

    std::string input_file = argv[1];
      // Open the file
    //std::FILE * f = std::fopen(input_file.c_str(), "r");
    std::FILE * f = std::fopen("/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/examples/MyExamples/Toyexamples/toyexample3.txt", "r");
    if (f == nullptr) {
        std::cerr << "Failed to open the file: " << input_file << "\n";
        return 1;
    }

    // Parse the system declaration
    auto sysdecl = tchecker::parsing::parse_system_declaration(f, "toyexample1.txt");
    //std::fclose(f);


    if (!sysdecl) {
        std::cerr << "Failed to parse system declaration. Check logs.\n";
        return 1;
    }

    // Count and display locations
    count_locations(*sysdecl);
    try {
        // Convert the system declaration to a system object
        std::shared_ptr<tchecker::ta::system_t const> system = std::make_shared<tchecker::ta::system_t>(*sysdecl);

        // Explore the zone graph
        explore_zone_graph(system);

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

      tchecker::clock_id_t dim = 3; // Example dimension (2 clocks + 1)

    // Allocate the DBM (difference bound matrix)
    tchecker::dbm::db_t dbm[dim * dim];

    // Initialize the zone as universal (no constraints)
    tchecker::dbm::universal_positive(dbm, dim);

    std::cout << "Universal Zone (DBM):" << std::endl;
    for (tchecker::clock_id_t i = 0; i < dim; ++i) {
        for (tchecker::clock_id_t j = 0; j < dim; ++j) {
            // Access the DBM element
            tchecker::dbm::db_t entry = dbm[i * dim + j];

            // Print based on the type of entry
            
            std::cout << tchecker::dbm::value(entry) << "\t"; // Print numeric constraint
            
        }
        std::cout << std::endl;
    }
    //auto system = tchecker::system::parse_system_declaration("input_file.txt");
  //  std::shared_ptr<tchecker::ta::system_t const> system = std::make_shared<tchecker::ta::system_t>(*sysdecl);
//if (!system) {
//    std::cerr << "Failed to construct system_t from sysdecl." << std::endl;
 //   return 1;
//}
tchecker::zg::zg_t * zone_graph = tchecker::zg::factory(
        system,                              // Parsed system
        tchecker::ts::SHARING,              // Sharing type
        tchecker::zg::STANDARD_SEMANTICS,   // Semantics type
        tchecker::zg::NO_EXTRAPOLATION,     // Extrapolation type
        1024,                               // Block size
        1024                                // Table size
    );

    if (zone_graph == nullptr) {
        std::cerr << "Failed to create zone graph." << std::endl;
        return 1;
    }

    std::cout << "Zone graph successfully created!" << std::endl;

    // Log zone graph initial states (as an example)
   std::vector<tchecker::zg::zg_t::sst_t> initial_states;
zone_graph->initial(initial_states, tchecker::STATE_OK);

// Iterate over states
for (auto const & [status, state, transition] : initial_states) {
    std::cout << "State ID: " << state->vloc() << ", Zone: " << std::endl;

    // Access and print the DBM
    tchecker::dbm::db_t const * my_dbm = state->zone().dbm();
    tchecker::clock_id_t dim = state->zone().dim();

    for (tchecker::clock_id_t i = 0; i < dim; ++i) {
        for (tchecker::clock_id_t j = 0; j < dim; ++j) {
            std::cout << tchecker::dbm::value(my_dbm[i * dim + j]) << "\t";
        }
        std::cout << std::endl;
    }
}
    return 0;
}
*/