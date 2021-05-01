find_package(Qt5 COMPONENTS Network Xml)

set(CMAKE_AUTOMOC ON)

add_library(vieraRemoteCore)

target_sources(vieraRemoteCore
    PRIVATE connecttotv.cpp)

target_link_libraries(vieraRemoteCore PRIVATE Qt5::Network Qt5::Xml Aide::AideLogger)

target_compile_features(vieraRemoteCore PUBLIC cxx_std_17)
