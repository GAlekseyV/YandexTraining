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

add_executable(tests_task_E tests_task_E.cpp)
target_link_libraries(tests_task_E PRIVATE project_warnings project_options catch_main)

# automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
# to whatever you want, or use different for different binaries
catch_discover_tests(
  tests_task_E
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