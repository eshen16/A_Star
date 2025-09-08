cmake_minimum_required(VERSION 3.30)
project(A_Star LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

set(SOURCE_FILES 
"src/Application.cpp"
"src/Application.h"
"src/Astar.cpp"
"src/Astar.h"
"src/Constants.h"
"src/Grid.cpp"
"src/Grid.h"
"src/Main.cpp"
"src/Node.cpp"
"src/Node.h"
"src/Render.h"
)

add_executable(main ${SOURCE_FILES})
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE sfml-graphics)
target_include_directories(main PRIVATE src)