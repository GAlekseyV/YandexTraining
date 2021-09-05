find_package(Catch2 REQUIRED)

include(CTest)
include(Catch)

add_library(catch_main STATIC catch_main.cpp)
target_link_libraries(catch_main PUBLIC Catch2::Catch2)
target_link_libraries(catch_main PRIVATE project_options)

add_executable(tests_task_A tests_task_A.cpp)
target_link_libraries(tests_task_A PRIVATE project_warnings project_options catch_main)

# automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
# to whatever you want, or use different for different binaries
catch_discover_tests(
  tests_task_A
  TEST_PREFIX
  "unittests."
  REPORTER
  xml
  OUTPUT_DIR
  .
  OUTPUT_PREFIX
  "unittests."
  OUTPUT_SUFFIX
  .xml)

add_executable(tests_task_B tests_task_B.cpp)
target_link_libraries(tests_task_B PRIVATE project_warnings project_options catch_main)

# automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
# to whatever you want, or use different for different binaries
catch_discover_tests(
  tests_task_B
  TEST_PREFIX
  "tests_."
  REPORTER
  xml
  OUTPUT_DIR
  .
  OUTPUT_PREFIX
  "tests_."
  OUTPUT_SUFFIX
  .xml)

  add_executable(tests_task_C tests_task_C.cpp)
  target_link_libraries(tests_task_C PRIVATE project_warnings project_options catch_main)
  
  # automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
  # to whatever you want, or use different for different binaries
  catch_discover_tests(
    tests_task_C
    TEST_PREFIX
    "tests_."
    REPORTER
    xml
    OUTPUT_DIR
    .
    OUTPUT_PREFIX
    "tests_."
    OUTPUT_SUFFIX
    .xml)

add_executable(tests_task_D tests_task_D.cpp)
target_link_libraries(tests_task_D PRIVATE project_warnings project_options catch_main)

# automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
# to whatever you want, or use different for different binaries
catch_discover_tests(
  tests_task_D
  TEST_PREFIX
  "tests_."
  REPORTER
  xml
  OUTPUT_DIR
  .
  OUTPUT_PREFIX
  "tests_."
  OUTPUT_SUFFIX
  .xml)