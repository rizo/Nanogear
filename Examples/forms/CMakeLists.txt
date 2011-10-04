include_directories(${CMAKE_SOURCE_DIR}/src/core ${CMAKE_SOURCE_DIR}/src/connectors)
add_executable(forms main.cpp)
target_link_libraries(forms Nanogear NanogearIHTTPConnector)
