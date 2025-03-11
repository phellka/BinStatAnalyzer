cmake_minimum_required(VERSION 3.10)

project(MyProject C)

set(CMAKE_C_STANDARD 11)

# Определяем пути к исходникам
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(TEST_DIR "${CMAKE_SOURCE_DIR}/tests")

# Собираем исходники основной утилиты (без тестов)
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.c")
add_executable(data_processor ${SOURCES})
target_include_directories(data_processor PRIVATE ${SRC_DIR})


# Опционально: если есть файлы тестов, создаём test_runner
file(GLOB_RECURSE TEST_SOURCES "${TEST_DIR}/*.c")
list(FILTER SOURCES EXCLUDE REGEX ".*main.c") 
list(LENGTH TEST_SOURCES TEST_COUNT)
if(TEST_COUNT GREATER 0)
    add_executable(test_runner ${TEST_SOURCES} ${SOURCES})
endif()
