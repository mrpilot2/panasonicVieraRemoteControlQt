find_package(Aide CONFIG QUIET)

if (NOT TARGET Aide::AideApplication)
    include(FetchContent)
    FetchContent_Declare(aide
        GIT_REPOSITORY https://github.com/mrpilot2/aide.git
        GIT_TAG develop
        SOURCE_SUBDIR aide  #Build the library only
        )

    FetchContent_MakeAvailable(aide)
else()
    set_target_properties(Aide::AideApplication PROPERTIES IMPORTED_GLOBAL TRUE)
endif()
