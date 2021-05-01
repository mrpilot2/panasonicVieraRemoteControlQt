# automatically enable catch2 to generate ctest targets
if (CONAN_CATCH2_ROOT_DEBUG)
  include(${CONAN_CATCH2_ROOT_DEBUG}/lib/cmake/Catch2/Catch.cmake)
else ()
  include(${CONAN_CATCH2_ROOT}/lib/cmake/Catch2/Catch.cmake)
endif ()

option(UNIT_TESTS_RUN_ON_CI
    "Specify if unit tests are executed on CI - changes reporter"
    )

add_library(catch_main OBJECT catch_main.cpp)
target_link_libraries(catch_main PUBLIC CONAN_PKG::catch2)
target_compile_features(catch_main PUBLIC cxx_std_11)

add_executable(ut.aide)

target_sources(ut.aide
    PRIVATE $<TARGET_OBJECTS:catch_main>)

target_link_libraries(
    ut.aide
    PRIVATE catch_main
)

enable_testing()

if (UNIT_TESTS_RUN_ON_CI)
  catch_discover_tests(
      ut.aide
      REPORTER
      junit
      OUTPUT_DIR
      ${CMAKE_CURRENT_BINARY_DIR}
      OUTPUT_SUFFIX
      .xml
  )
else ()
  catch_discover_tests(ut.aide REPORTER console)
endif ()
