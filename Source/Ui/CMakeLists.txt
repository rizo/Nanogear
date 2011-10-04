
# Implementation and declaration files
file(GLOB NANOGEAR_UI_SOURCE_FILES ${NANOGEAR_SOURCE_PATTERN})
file(GLOB NANOGEAR_UI_HEADER_FILES ${NANOGEAR_HEADER_PATTERN})


# Create Nanogear shared library
add_library(nanogear-ui SHARED
    ${NANOGEAR_UI_SOURCE_FILES}
    ${NANOGEAR_UI_HEADER_FILES})

set_target_properties(nanogear-ui PROPERTIES
    VERSION ${NANOGEAR_MAJOR}.${NANOGEAR_MINOR}.${NANOGEAR_PATCH}
    SOVERSION ${NANOGEAR_MAJOR})

# FIXME: Find the nanogear-http first
target_link_libraries(nanogear-ui ${QT_LIBRARIES})

# Install Nanogear library
install(TARGETS nanogear-ui
    LIBRARY DESTINATION ${NANOGEAR_LIBRARY_DIR})

# Install WDI headers
install(FILES ${NANOGEAR_UI_HEADER_FILES}
    DESTINATION ${NANOGEAR_INCLUDE_DIR})

