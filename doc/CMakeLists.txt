set(PDSLIB_DOXYGEN_VERSION 1.9.0)
set(PDSLIB_DOXYGEN_REPOSITORY https://github.com/doxygen/doxygen.git)

find_package(Doxygen)

if (Doxygen_FOUND)
    message("Doxygen found")
    configure_file(Doxyfile.in Doxyfile.out)
    message("Doxygen build started")
    add_custom_target(doc COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.out)
endif ()