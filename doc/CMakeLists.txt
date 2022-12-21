find_package(Doxygen)

if (Doxygen_FOUND)    
    configure_file(Doxyfile.in Doxyfile.out)
    message("Doxygen build started")
    add_custom_target(doc COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.out)
endif ()