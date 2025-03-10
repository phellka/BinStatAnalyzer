cmake_minimum_required(VERSION 3.10)

project(MyProject C)

set(CMAKE_C_STANDARD 11)

# Определяем пути к исходникам
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(TEST_DIR "${CMAKE_SOURCE_DIR}/tests")

# Собираем исходники основной утилиты (без тестов)
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.c")
add_executable(main ${SOURCES})
target_include_directories(main PRIVATE ${SRC_DIR})


# Опционально: если есть файлы тестов, создаём test_runner
file(GLOB_RECURSE TEST_SOURCES "${TEST_DIR}/*.c")
list(LENGTH TEST_SOURCES TEST_COUNT)
if(TEST_COUNT GREATER 0)
    add_executable(test_runner ${TEST_SOURCES})
    target_include_directories(test_runner PRIVATE ${SRC_DIR})
endif()
