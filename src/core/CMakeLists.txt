find_package(Qt5 COMPONENTS Network Xml)

set(CMAKE_AUTOMOC ON)

add_library(vieraRemoteCore)

target_sources(vieraRemoteCore PRIVATE connecttotv.cpp vieraprotocol.cpp)

target_link_libraries(
  vieraRemoteCore
  PUBLIC Qt5::Network
  PRIVATE Qt5::Xml Aide::AideLogger project_coverage project_sanitizers
          project_warnings
)

target_include_directories(vieraRemoteCore PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_compile_features(vieraRemoteCore PUBLIC cxx_std_17)
