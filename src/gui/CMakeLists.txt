find_package(Qt5 COMPONENTS Widgets Core)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_LIST_DIR}/res/forms)
set(CMAKE_AUTOMOC ON)

add_library(vieraRemoteGui STATIC)

target_sources(vieraRemoteGui
    PRIVATE mainwidget.cpp mainwidgetcontroller.cpp
    )

target_link_libraries(vieraRemoteGui PRIVATE Aide::AideLogger Qt5::Widgets)

target_include_directories(vieraRemoteGui PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    )

target_compile_features(vieraRemoteGui PUBLIC cxx_std_17)
