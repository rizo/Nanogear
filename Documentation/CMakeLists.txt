configure_file("${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in" "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile" @ONLY)
add_custom_target(apidocs ${DOXYGEN_EXECUTABLE} "Doxyfile")