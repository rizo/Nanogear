include_directories(${CMAKE_SOURCE_DIR}/src/core ${CMAKE_SOURCE_DIR}/src/connectors)
add_executable(directory main.cpp)
target_link_libraries(directory Nanogear NanogearIHTTPConnector)

