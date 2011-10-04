include_directories(${CMAKE_SOURCE_DIR}/src/core ${CMAKE_SOURCE_DIR}/src/connectors)
add_executable(simple main.cpp)
target_link_libraries(simple NanogearIHTTPConnector Nanogear)
