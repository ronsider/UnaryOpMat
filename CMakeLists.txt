cmake_minimum_required(VERSION 3.10)
project(YourProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set paths to raylib and raygui
set(RAYLIB_DIR "${CMAKE_SOURCE_DIR}/libs/raylib")
set(RAYGUI_DIR "${CMAKE_SOURCE_DIR}/libs/raygui")

set(RESOURCE_DIR "${CMAKE_SOURCE_DIR}/resources")

# Define the output directory for the resources in the build directory
set(RESOURCE_OUTPUT_DIR "${CMAKE_BINARY_DIR}/resources")

# Add include directories
include_directories(${RAYLIB_DIR}/include)
include_directories(${RAYGUI_DIR}/include)

link_directories(${RAYLIB_DIR}/lib)

# Add library directories
#link_directories(${RAYLIB_DIR}/libs)

if (MSVC)
    add_compile_options(/W3 /permissive- /analyze /wd4996)
else()
    add_compile_options(-Wall -Wextra -Werror -pedantic -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wconversion -Wsign-conversion -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast -Wdouble-promotion)
endif()


# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")


add_executable(${PROJECT_NAME} ${SOURCES})

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${RESOURCE_OUTPUT_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${RESOURCE_DIR} ${RESOURCE_OUTPUT_DIR}
)

# Link libraries
#target_link_libraries(${PROJECT_NAME} raylib)

# Link libraries for compilation on windows machine
target_link_libraries(${PROJECT_NAME} raylib winmm)




# Required for some systems (Linux, macOS)
if (UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} m)
endif()