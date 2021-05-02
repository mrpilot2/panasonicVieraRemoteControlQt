# automatically enable catch2 to generate ctest targets
if (CONAN_CATCH2_ROOT_DEBUG)
  include(${CONAN_CATCH2_ROOT_DEBUG}/lib/cmake/Catch2/Catch.cmake)
else ()
  include(${CONAN_CATCH2_ROOT}/lib/cmake/Catch2/Catch.cmake)
endif ()

option(UNIT_TESTS_RUN_ON_CI
    "Specify if unit tests are executed on CI - changes reporter"
    )

add_library(viera_catch_main STATIC catch_main.cpp)
target_link_libraries(viera_catch_main PUBLIC CONAN_PKG::catch2)
target_compile_features(viera_catch_main PUBLIC cxx_std_11)

add_executable(ut.vieraRemoteControlQt)

target_sources(ut.vieraRemoteControlQt
    PRIVATE vieraprotocoltest.cpp)

target_link_libraries(
    ut.vieraRemoteControlQt
    PRIVATE viera_catch_main
    vieraRemoteCore
)

enable_testing()

if (UNIT_TESTS_RUN_ON_CI)
  catch_discover_tests(
      ut.vieraRemoteControlQt
      REPORTER
      junit
      OUTPUT_DIR
      ${CMAKE_CURRENT_BINARY_DIR}
      OUTPUT_SUFFIX
      .xml
  )
else ()
  catch_discover_tests(ut.vieraRemoteControlQt REPORTER console)
endif ()
