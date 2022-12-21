set(PDSLIB_DOCTEST_VERSION 2.3.4)
set(PDSLIB_DOCTEST_REPOSITORY https://github.com/doctest/doctest.git)

find_package(doctest ${PDSLIB_DOCTEST_VERSION})

if (doctest_FOUND)
    message(STATUS "Found doctest ${doctest_VERSION}: ${doctest_DIR}")
else()
    message(STATUS
        "doctest ${PDSLIB_DOCTEST_VERSION} fetching from github: ${PDSLIB_DOCTEST_REPOSITORY}")

    include(FetchContent)
    FetchContent_Declare(doctest
        GIT_REPOSITORY
            ${PDSLIB_DOCTEST_REPOSITORY}
        GIT_TAG
            ${PDSLIB_DOCTEST_VERSION}
    )
    FetchContent_MakeAvailable(doctest)
endif()

#----------#----------#----------#----------#----------#

add_executable(pdsLib-unit-tests test_main.cpp)

target_sources(pdsLib-unit-tests PRIVATE pdsLib/test_all.cpp)

#target_sources(pdsLib-unit-tests PRIVATE test_main.cpp)

target_link_libraries(pdsLib-unit-tests
    PRIVATE
        doctest::doctest
)