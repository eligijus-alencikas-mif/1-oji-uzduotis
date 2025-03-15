# filepath: /home/eli/Projects/1-oji-uzduotis/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(1-oji-uzduotis)

set(CMAKE_CXX_STANDARD 17)

# Add the executable
add_executable(1-oji-uzduotis
    main.cpp
    cl_students.cpp
    file_gen.cpp
    generator.cpp
    output_students.cpp
    read_students.cpp
    students_calc.cpp
    timer.cpp
)

# Include directories
target_include_directories(1-oji-uzduotis PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)