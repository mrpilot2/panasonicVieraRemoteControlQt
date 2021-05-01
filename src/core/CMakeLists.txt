find_package(Qt5 COMPONENTS Network Xml)

set(CMAKE_AUTOMOC ON)

add_library(vieraRemoteCore)

target_sources(vieraRemoteCore
    PRIVATE connecttotv.cpp vieraprotocol.cpp)

target_link_libraries(vieraRemoteCore PUBLIC Qt5::Network PRIVATE Qt5::Xml Aide::AideLogger)

target_compile_features(vieraRemoteCore PUBLIC cxx_std_17)
