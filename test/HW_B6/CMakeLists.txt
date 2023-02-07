add_executable(tests_B6task_A tests_task_A.cpp)
target_link_libraries(tests_B6task_A PRIVATE project_warnings project_options catch_main)

# automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
# to whatever you want, or use different for different binaries
catch_discover_tests(
  tests_B6task_A
  TEST_PREFIX
  "HW_6. "
  REPORTER
  xml
  OUTPUT_DIR
  .
  OUTPUT_PREFIX
  "HW_6. "
  OUTPUT_SUFFIX
  .xml)
