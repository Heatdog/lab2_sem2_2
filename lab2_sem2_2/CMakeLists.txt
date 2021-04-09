# CMakeList.txt: проект CMake для lab2_sem2_2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

add_definitions(-DUSE_VECTOR)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (lab2_sem2_2 "main.cpp" "vector.h" "vector.cpp" "input.h" "input.cpp" "list.h" "list.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
