add_executable(tests_B5task_B tests_task_B.cpp)
target_link_libraries(tests_B5task_B PRIVATE project_warnings project_options catch_main)

# automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
# to whatever you want, or use different for different binaries
catch_discover_tests(
  tests_B5task_B
  TEST_PREFIX
  "HW_5. "
  REPORTER
  xml
  OUTPUT_DIR
  .
  OUTPUT_PREFIX
  "HW_5. "
  OUTPUT_SUFFIX
  .xml)
