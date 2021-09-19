add_executable(tests_B2task_A tests_task_A.cpp)
target_link_libraries(tests_B2task_A PRIVATE project_warnings project_options catch_main)

# automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
# to whatever you want, or use different for different binaries
catch_discover_tests(
  tests_B2task_A
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

add_executable(tests_B2task_B tests_task_B.cpp)
target_link_libraries(tests_B2task_B PRIVATE project_warnings project_options catch_main)

catch_discover_tests(
  tests_B2task_B
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

add_executable(tests_B2task_C tests_task_C.cpp)
target_link_libraries(tests_B2task_C PRIVATE project_warnings project_options catch_main)

catch_discover_tests(
  tests_B2task_C
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

add_executable(tests_B2task_D tests_task_D.cpp)
target_link_libraries(tests_B2task_D PRIVATE project_warnings project_options catch_main)

catch_discover_tests(
  tests_B2task_D
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