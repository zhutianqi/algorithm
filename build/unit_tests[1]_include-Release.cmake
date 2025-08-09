if(EXISTS "/Users/tianqizhu/algorithm/build/Release/unit_tests")
  if(NOT EXISTS "/Users/tianqizhu/algorithm/build/unit_tests[1]_tests-Release.cmake" OR
     NOT "/Users/tianqizhu/algorithm/build/unit_tests[1]_tests-Release.cmake" IS_NEWER_THAN "/Users/tianqizhu/algorithm/build/Release/unit_tests" OR
     NOT "/Users/tianqizhu/algorithm/build/unit_tests[1]_tests-Release.cmake" IS_NEWER_THAN "${CMAKE_CURRENT_LIST_FILE}")
    include("/opt/homebrew/share/cmake/Modules/GoogleTestAddTests.cmake")
    gtest_discover_tests_impl(
      TEST_EXECUTABLE [==[/Users/tianqizhu/algorithm/build/Release/unit_tests]==]
      TEST_EXECUTOR [==[]==]
      TEST_WORKING_DIR [==[/Users/tianqizhu/algorithm/build]==]
      TEST_EXTRA_ARGS [==[]==]
      TEST_PROPERTIES [==[]==]
      TEST_PREFIX [==[]==]
      TEST_SUFFIX [==[]==]
      TEST_FILTER [==[]==]
      NO_PRETTY_TYPES [==[FALSE]==]
      NO_PRETTY_VALUES [==[FALSE]==]
      TEST_LIST [==[unit_tests_TESTS]==]
      CTEST_FILE [==[/Users/tianqizhu/algorithm/build/unit_tests[1]_tests-Release.cmake]==]
      TEST_DISCOVERY_TIMEOUT [==[5]==]
      TEST_DISCOVERY_EXTRA_ARGS [==[]==]
      TEST_XML_OUTPUT_DIR [==[]==]
    )
  endif()
  include("/Users/tianqizhu/algorithm/build/unit_tests[1]_tests-Release.cmake")
else()
  add_test(unit_tests_NOT_BUILT unit_tests_NOT_BUILT)
endif()
