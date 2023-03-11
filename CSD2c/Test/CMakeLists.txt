cmake_minimum_required(VERSION 3.24.2) # Set minimum required CMake version
project(app) # Project name
set(CMAKE_CXX_STANDARD 17) # Set compiler version

include_directories(include)
include_directories(/usr/local/include)

file(GLOB SOURCES "src/*.cpp")
add_executable(app ${SOURCES})

find_library(JACK_LIB jack)
target_link_libraries(app ${JACK_LIB})


####
cmake_minimum_required(VERSION 3.24.2) # State what CMake version is required.

project(madPanner) # State the name of the project.
set(CMAKE_CXX_STANDARD 17) # State what compiler to use.

file(GLOB SOURCES "src/*.cpp") # Make a variable named SOURCES.

include_directories(/usr/local/include) # Include the jack directory path.
include_directories(include) # Include the header file directory.
include_directories(libs) # Include the library directory.

add_executable(madPanner ${SOURCES}) # Make the executable, name it madPanner and include the .cpp files.

find_library(JACK_LIB jack) # Find the jack library and put it in the variable JACK_LIB.
target_link_libraries(madPanner ${JACK_LIB}) # Link the jack library to the project.

