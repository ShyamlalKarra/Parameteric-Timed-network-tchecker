/*
 * This file is a part of the TChecker project.
 *
 * See files AUTHORS and LICENSE for copyright details.
 *
 */

#ifndef TCHECKER_ALGORITHMS_REACH_ALGORITHM_HH
#define TCHECKER_ALGORITHMS_REACH_ALGORITHM_HH

#include <memory>

#include <boost/dynamic_bitset.hpp>

#include "tchecker/algorithms/reach/stats.hh"
#include "tchecker/basictypes.hh"
#include "tchecker/waiting/factory.hh"

/*!
 \file algorithm.hh
 \brief Reachability algorithm
 */

namespace tchecker {

namespace algorithms {

namespace reach {

/*!
 \class algorithm_t
 \brief Reachability algorithm
 \tparam TS : type of transition system, should implement tchecker::ts::fwd_t
 and tchecker::ts::inspector_t
 \tparam GRAPH : type of graph, should derive from
 tchecker::graph::reachability_graph_t, and nodes of type GRAPH::shared_node_t
 should have a method state_ptr() that yields a pointer to the corresponding
 state in TS
 */
template <class TS, class GRAPH> class algorithm_t {
public:
  using node_sptr_t = typename GRAPH::node_sptr_t;

  /*!
   \brief Build a reachability graph of a transition system from its initial
   states
   \param ts : a transition system
   \param graph : a graph
   \param labels : accepting labels
   \param policy : waiting list policy
   \post graph is built from a traversal of ts starting from its initial states,
   until a state that satisfies labels is reached (if any).
   A node is created for each reachable state in ts, and an edge is created for
   each transition in ts. The order in which the nodes of ts are visited depends
   on policy.
   \return statistics on the run
   \note if labels is empty, graph is the full reachability graph of ts
   */
  tchecker::algorithms::reach::stats_t run(TS & ts, GRAPH & graph, boost::dynamic_bitset<> const & labels,
                                           enum tchecker::waiting::policy_t policy)
  {
    std::unique_ptr<tchecker::waiting::waiting_t<node_sptr_t>> waiting{tchecker::waiting::factory<node_sptr_t>(policy)};

    tchecker::algorithms::reach::stats_t stats;

    stats.set_start_time();

    std::vector<typename TS::sst_t> sst;
    ts.initial(sst);
    for (auto && [status, s, t] : sst) {
      auto && [is_new_node, initial_node] = graph.add_node(s);
      initial_node->initial(true);
      if (is_new_node)
        waiting->insert(initial_node);
    }

    run_from_waiting(ts, graph, labels, *waiting, stats);

    stats.set_end_time();

    return stats;
  }

  /*!
  \brief Build a reachability graph of a transition system from a waiting
  container
  \param ts : a transition system
  \param graph : a graph
  \param labels : accepting labels
  \param waiting : a waiting container
  \post graph is built from a traversal of ts starting from the nodes in
  waiting, until a state that satisfies labels is reached (if any).
  A node is created for each reachable state in ts, and an edge is
  created for each transition is ts. The order in which the nodes of ts are
  visited depends on the policy implemented by waiting
  \return statistics on the run
  \note if labels is empty, graph is the full reachability graph of ts from the
  nodes in waiting
  */
  tchecker::algorithms::reach::stats_t run(TS & ts, GRAPH & graph, boost::dynamic_bitset<> const & labels,
                                           tchecker::waiting::waiting_t<typename GRAPH::node_sptr_t> & waiting)
  {
    tchecker::algorithms::reach::stats_t stats;

    stats.set_start_time();
    run_from_waiting(ts, graph, labels, waiting, stats);
    stats.set_end_time();

    return stats;
  }

private:
  /*!
  \brief Build a reachability graph of a transition system from a waiting
  container
  \param ts : a transition system
  \param graph : a graph
  \param labels : accepting labels
  \param waiting : a waiting container
  \param stats : statistics
  \post graph is built from a traversal of ts starting from the nodes in
  waiting, until a state that satisfies labels is reached (if any).
  A node is created for each reachable state in ts, and an edge is
  created for each transition is ts. The order in which the nodes of ts are
  visited depends on the policy implemented by waiting.
  The number of visited nodes and reachability of a satisfying node have been
  set in stats.
  */
 /* void run_from_waiting(TS & ts, GRAPH & graph, boost::dynamic_bitset<> const & labels,
                        tchecker::waiting::waiting_t<typename GRAPH::node_sptr_t> & waiting,
                        tchecker::algorithms::reach::stats_t & stats)
  {
    std::vector<typename TS::sst_t> sst;

    while (!waiting.empty()) {
      node_sptr_t node = waiting.first();
      waiting.remove_first();

      ++stats.visited_states();

      if (accepting(node, ts, labels)) {
        node->final(true);
        stats.reachable() = true;
        break;
      }

      ts.next(node->state_ptr(), sst);
      for (auto && [status, s, t] : sst) {
        auto && [is_new_node, next_node] = graph.add_node(s);
        if (is_new_node)
          waiting.insert(next_node);
        graph.add_edge(node, next_node, *t);

        ++stats.visited_transitions();
      }
      sst.clear();
    }

    waiting.clear();
  }
*/
/*!
\brief Build a reachability graph of a transition system from a waiting
container while avoiding specific zone paths
\param ts : a transition system
\param graph : a graph
\param labels : accepting labels
\param waiting : a waiting container
\param stats : statistics
\post graph is built from a traversal of ts starting from the nodes in
waiting, until a state that satisfies labels is reached (if any).
A node is created for each reachable state in ts, and an edge is
created for each transition in ts. The order in which the nodes of ts are
visited depends on the policy implemented by waiting.
The number of visited nodes and reachability of a satisfying node have been
set in stats.
*/
/*void run_from_waiting(TS & ts, GRAPH & graph, boost::dynamic_bitset<> const & labels,
                      tchecker::waiting::waiting_t<typename GRAPH::node_sptr_t> & waiting,
                      tchecker::algorithms::reach::stats_t & stats) {
    std::vector<typename TS::sst_t> sst;

    // Define paths to avoid
    std::vector<std::vector<std::pair<std::string, std::string>>> avoid_paths = {
        {{"locg1less", "(1<=x)"}, {"locg1", "(1<=x<2)"}},
        {{"a", "(0<=x)"}, {"b", "(0<=x)"}, {"c", "(0<=x)"}}
    };

    // Map to track active path progress for each node
    std::unordered_map<typename GRAPH::node_sptr_t, std::vector<size_t>> node_active_paths;

    while (!waiting.empty()) {
        auto node = waiting.first();
        waiting.remove_first();

        ++stats.visited_states();

        // Check if the node satisfies the accepting condition
        if (accepting(node, ts, labels)) {
            node->final(true);
            stats.reachable() = true;
            break;
        }

        // Generate successors
        ts.next(node->state_ptr(), sst);

        for (auto && [status, s, t] : sst) {
            // Access the vedge from the transition
            const auto &vedge = t->vedge();

            // Retrieve the event name for the first valid edge in vedge
            std::string event_name;
            for (auto edge_id : vedge) {
                if (edge_id != tchecker::NO_EDGE) {
                    auto edge = ts.system().edge(edge_id);
                    event_name = ts.system().event_name(edge->event_id());
                    break;  // Only need the first edge's event name
                }
            }

            // Get the zone string
            std::string zone_str = tchecker::to_string(s->zone(), ts.system().clock_variables().flattened().index());

            // Check if this transition should be avoided
            bool avoid = false;
            for (const auto &path : avoid_paths) {
                size_t progress = 0;

                // Check if the current transition matches the current progress in the path
                if (path[progress].first == event_name && path[progress].second == zone_str) {
                    ++progress;

                    // If we've matched the entire path, avoid the transition
                    if (progress == path.size()) {
                        avoid = true;
                        break;
                    }
                }
            }

            if (avoid) continue;

            // Add the successor node to the graph and waiting list
            auto && [is_new_node, next_node] = graph.add_node(s);
            if (is_new_node) {
                waiting.insert(next_node);
            }
            graph.add_edge(node, next_node, *t);

            ++stats.visited_transitions();
        }
        sst.clear();
    }

    waiting.clear();
}*/
//The following function avoids location paths that have an avoilocguard as its subsequnce. the avoidlocguards are hardcoded
void run_from_waiting(TS & ts, GRAPH & graph, boost::dynamic_bitset<> const & labels,
                      tchecker::waiting::waiting_t<typename GRAPH::node_sptr_t> & waiting,
                      tchecker::algorithms::reach::stats_t & stats) {
    std::vector<typename TS::sst_t> sst;

    // Hardcoded avoidance logic
    std::vector<std::vector<std::pair<std::string, std::string>>> avoid_paths = {
        {{"zone0", "event1"}, {"zone1", "event2"}, {"zone2", "event3"}},  // seq1
        {{"zone4", "event4"}, {"zone5", "event5"}}                       // seq2
    };

    std::vector<size_t> matched_indices(avoid_paths.size(), 0);

    while (!waiting.empty()) {
        auto node = waiting.first();
        waiting.remove_first();

        ++stats.visited_states();

        if (accepting(node, ts, labels)) {
            node->final(true);
            stats.reachable() = true;
            break;
        }

        ts.next(node->state_ptr(), sst);

        for (auto && [status, s, t] : sst) {
            const auto &vedge = t->vedge();
            std::string event_name;

            for (auto edge_id : vedge) {
                if (edge_id != tchecker::NO_EDGE) {
                    auto edge = ts.system().edge(edge_id);
                    event_name = ts.system().event_name(edge->event_id());
                    break;
                }
            }

            std::string pred_zone_str = tchecker::to_string(node->state_ptr()->zone(),
                                                            ts.system().clock_variables().flattened().index());

            bool avoid = false;

            for (size_t i = 0; i < avoid_paths.size(); ++i) {
                const auto &sequence = avoid_paths[i];
                size_t matched_idx = matched_indices[i];

                if (matched_idx < sequence.size() &&
                    sequence[matched_idx].first == pred_zone_str &&
                    sequence[matched_idx].second == event_name) {
                    matched_indices[i]++;
                } else {
                    matched_indices[i] = 0;  // Reset if mismatch
                }

                if (matched_indices[i] == sequence.size()) {
                    avoid = true;
                    break;  // Fully matched sequence
                }
            }

            if (avoid) {
                continue;
            }

            auto && [is_new_node, next_node] = graph.add_node(s);
            if (is_new_node) {
                waiting.insert(next_node);
            }
            graph.add_edge(node, next_node, *t);

            ++stats.visited_transitions();
        }
        sst.clear();
    }

    waiting.clear();
}


//generate a zone path: this function is a modification of run_from_Waiting of the tchecker original function and it outputs zone path to a speicfic locaiton
std::vector<std::pair<std::string, std::string>> generateTrace(
    TS & ts, GRAPH & graph, boost::dynamic_bitset<> const & labels,
    tchecker::waiting::waiting_t<typename GRAPH::node_sptr_t> & waiting,
    tchecker::algorithms::reach::stats_t & stats, 
    const std::string &target_location) 
{
    std::vector<typename TS::sst_t> sst;
    std::vector<std::pair<std::string, std::string>> zone_path; // To store the zone path

    while (!waiting.empty()) {
        node_sptr_t node = waiting.first();
        waiting.remove_first();

        ++stats.visited_states();

        // Check if the node satisfies the target location condition
        if (ts.system().location(node->state_ptr())->name() == target_location) {
            node->final(true);
            stats.reachable() = true;
            break; // Target location reached
        }

        // Generate successors
        ts.next(node->state_ptr(), sst);

        for (auto && [status, s, t] : sst) {
            // Access the vedge from the transition
            const auto &vedge = t->vedge();

            // Retrieve the event name for the first valid edge in vedge
            std::string event_name;
            for (auto edge_id : vedge) {
                if (edge_id != tchecker::NO_EDGE) {
                    auto edge = ts.system().edge(edge_id);
                    event_name = ts.system().event_name(edge->event_id());
                    break;  // Only need the first edge's event name
                }
            }

            // Get the zone string
            std::string zone_str = tchecker::to_string(s->zone(), ts.system().clock_variables().flattened().index());

            // Add the event and zone to the path
            zone_path.emplace_back(event_name, zone_str);

            // Add the successor node to the graph and waiting list
            auto && [is_new_node, next_node] = graph.add_node(s);
            if (is_new_node) {
                waiting.insert(next_node);
            }
            graph.add_edge(node, next_node, *t);

            ++stats.visited_transitions();
        }
        sst.clear();
    }

    waiting.clear();
    return zone_path; // Return the constructed zone path
}




/*FOLLOWING IS WORKING VERSION run_from_waiting that works WITH ONE hardcoded avoidlocguard path AND avoids EXACT MATCHing paths*

void run_from_waiting(TS & ts, GRAPH & graph, boost::dynamic_bitset<> const & labels,
                      tchecker::waiting::waiting_t<typename GRAPH::node_sptr_t> & waiting,
                      tchecker::algorithms::reach::stats_t & stats) {
    std::vector<typename TS::sst_t> sst;

    // Hardcoded avoidance logic for a specific path
    const std::string avoid_event = "locg1less";
    const std::string avoid_zone = "(1<=x)";

    while (!waiting.empty()) {
        auto node = waiting.first();
        waiting.remove_first();

        ++stats.visited_states();

        // Check if the node satisfies the accepting condition
        if (accepting(node, ts, labels)) {
            node->final(true);
            stats.reachable() = true;
            break;
        }

        // Generate successors
        ts.next(node->state_ptr(), sst);

        for (auto && [status, s, t] : sst) {
            // Access the vedge from the transition
            const auto &vedge = t->vedge();

            // Retrieve the event name for the first valid edge in vedge
            std::string event_name;
            for (auto edge_id : vedge) {
                if (edge_id != tchecker::NO_EDGE) {
                    auto edge = ts.system().edge(edge_id);
                    event_name = ts.system().event_name(edge->event_id());
                    break;  // Only need the first edge's event name
                }
            }

            // Get the zone string
            std::string zone_str = tchecker::to_string(s->zone(), ts.system().clock_variables().flattened().index());

            // Skip transitions that match the avoidance criteria
            if (event_name == avoid_event && zone_str == avoid_zone) {
                continue;
            }

            // Add the successor node to the graph and waiting list
            auto && [is_new_node, next_node] = graph.add_node(s);
            if (is_new_node) {
                waiting.insert(next_node);
            }
            graph.add_edge(node, next_node, *t);

            ++stats.visited_transitions();
        }
        sst.clear();
    }

    waiting.clear();
}
*/







  /*!
   \brief Check if a node is accepting
   \param n : a node
   \param ts : a transition system
   \param labels : a set of labels
   \return true if labels is not empty, and the set of labels in n contain
   labels, and n is a valid final state in ts, false otherwise
   */
  bool accepting(node_sptr_t const & n, TS & ts, boost::dynamic_bitset<> const & labels)
  {
    return !labels.none() && labels.is_subset_of(ts.labels(n->state_ptr())) && ts.is_valid_final(n->state_ptr());
  }
};

} // end of namespace reach

} // end of namespace algorithms

} // end of namespace tchecker

#endif // TCHECKER_ALGORITHMS_REACH_ALGORITHM_HH
