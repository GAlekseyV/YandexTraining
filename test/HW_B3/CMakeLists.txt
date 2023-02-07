add_executable(tests_B3task_A tests_task_A.cpp)
target_link_libraries(tests_B3task_A PRIVATE project_warnings project_options catch_main)

# automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
# to whatever you want, or use different for different binaries
catch_discover_tests(
  tests_B3task_A
  TEST_PREFIX
  "HW_3. "
  REPORTER
  xml
  OUTPUT_DIR
  .
  OUTPUT_PREFIX
  "HW_3. "
  OUTPUT_SUFFIX
  .xml)
