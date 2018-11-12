# CMake generated Testfile for 
# Source directory: /home/ifq/develop/CXX/Thirds/Catch2/projects
# Build directory: /home/ifq/develop/CXX/Thirds/Catch2/build/projects
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(RunTests "/home/ifq/develop/CXX/Thirds/Catch2/build/projects/SelfTest")
add_test(ListTests "/home/ifq/develop/CXX/Thirds/Catch2/build/projects/SelfTest" "--list-tests" "--verbosity" "high")
set_tests_properties(ListTests PROPERTIES  FAIL_REGULAR_EXPRESSION "Hidden Test" PASS_REGULAR_EXPRESSION "[0-9]+ test cases")
add_test(ListTags "/home/ifq/develop/CXX/Thirds/Catch2/build/projects/SelfTest" "--list-tags")
set_tests_properties(ListTags PROPERTIES  FAIL_REGULAR_EXPRESSION "\\[\\.\\]" PASS_REGULAR_EXPRESSION "[0-9]+ tags")
add_test(ListReporters "/home/ifq/develop/CXX/Thirds/Catch2/build/projects/SelfTest" "--list-reporters")
set_tests_properties(ListReporters PROPERTIES  PASS_REGULAR_EXPRESSION "Available reporters:")
add_test(ListTestNamesOnly "/home/ifq/develop/CXX/Thirds/Catch2/build/projects/SelfTest" "--list-test-names-only")
set_tests_properties(ListTestNamesOnly PROPERTIES  FAIL_REGULAR_EXPRESSION "Hidden Test" PASS_REGULAR_EXPRESSION "Regex string matcher")
add_test(NoAssertions "/home/ifq/develop/CXX/Thirds/Catch2/build/projects/SelfTest" "-w" "NoAssertions")
set_tests_properties(NoAssertions PROPERTIES  PASS_REGULAR_EXPRESSION "No assertions in test case")
add_test(NoTest "/home/ifq/develop/CXX/Thirds/Catch2/build/projects/SelfTest" "-w" "NoTests" "___nonexistent_test___")
set_tests_properties(NoTest PROPERTIES  PASS_REGULAR_EXPRESSION "No test cases matched")
add_test(ApprovalTests "/home/ifq/anaconda2/bin/python" "/home/ifq/develop/CXX/Thirds/Catch2/scripts/approvalTests.py" "/home/ifq/develop/CXX/Thirds/Catch2/build/projects/SelfTest")
set_tests_properties(ApprovalTests PROPERTIES  FAIL_REGULAR_EXPRESSION "Results differed")
