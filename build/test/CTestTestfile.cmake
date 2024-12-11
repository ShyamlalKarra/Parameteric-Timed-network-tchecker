# CMake generated Testfile for 
# Source directory: /Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/test
# Build directory: /Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(build-tck-reach "/opt/homebrew/Cellar/cmake/3.30.5/bin/cmake" "--build" "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build" "--config" "" "--target" "tck-reach")
set_tests_properties(build-tck-reach PROPERTIES  FIXTURES_SETUP "BUILD_TCK_REACH" _BACKTRACE_TRIPLES "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/test/CMakeLists.txt;57;add_test;/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/test/CMakeLists.txt;0;")
subdirs("testutils")
subdirs("unit-tests")
subdirs("bugfixes")
subdirs("simple-nr")
subdirs("algos")
