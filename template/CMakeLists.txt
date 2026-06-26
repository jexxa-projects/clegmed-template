cmake_minimum_required(VERSION 4.1)
project({{ project_name }} VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        clegmed
        URL https://github.com/jexxa-projects/CLegMed/archive/refs/tags/v0.1.1.tar.gz
)
FetchContent_MakeAvailable(clegmed)

# Anwendung definieren
add_executable({{ project_name }} src/main.cpp)
target_link_libraries({{ project_name }} PRIVATE clegmed::core)

# Voll-statisches Linken für das schlanke Docker Scratch-Image
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_link_options({{ project_name }} PRIVATE -static)
endif()


# GoogleTest via FetchContent einbinden (wird oft im Hauptprojekt oder im Template geregelt)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com
)
FetchContent_MakeAvailable(googletest)

# Test-Executable erstellen
add_executable(clegmed_template_tests tests/main_test.cpp)

# Verlinke gegen GoogleTest und deine CLegMed-Targets
target_link_libraries(clegmed_template_tests
        PRIVATE
        gtest_main
        clegmed::core::base
        clegmed::plugins
        clegmed::utils
)

# Registriere die Tests für CTest
include(CTest)
add_test(NAME TemplateUnitTests COMMAND clegmed_template_tests)
