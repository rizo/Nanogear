
# Implementation and declaration files
file(GLOB NANOGEAR_HTTP_SOURCE_FILES ${NANOGEAR_SOURCE_PATTERN})
file(GLOB NANOGEAR_HTTP_HEADER_FILES ${NANOGEAR_HEADER_PATTERN})


# Create Nanogear shared library
add_library(nanogear-http SHARED
    ${NANOGEAR_HTTP_SOURCE_FILES}
    ${NANOGEAR_HTTP_HEADER_FILES})

set_target_properties(nanogear-http PROPERTIES
    VERSION ${NANOGEAR_MAJOR}.${NANOGEAR_MINOR}.${NANOGEAR_PATCH}
    SOVERSION ${NANOGEAR_MAJOR})

target_link_libraries(nanogear-http ${Libmagic_LIBRARY} ${QT_LIBRARIES})


# Install Nanogear library
install(TARGETS nanogear-http
    LIBRARY DESTINATION ${NANOGEAR_LIBRARY_DIR})

# Install WDI headers
install(FILES ${NANOGEAR_HTTP_HEADER_FILES}
    DESTINATION ${NANOGEAR_INCLUDE_DIR})

