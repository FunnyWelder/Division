cmake_minimum_required(VERSION 3.15)
project(lab_5)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_definitions(-std=gnu++17 -U__STRICT_ANSI__)

set(LINKER_FLAGS1 -lcygwin)
set(LINKER_FLAGS2 -lSDL2main)
set(LINKER_FLAGS3 -lSDL2)
set(LINKER_FLAGS4 -mwindows)

add_subdirectory(googletest)

include_directories(src)
include_directories(googletest/googletest/include)

set(SOURCE_FILES src/lib.cpp)

add_executable(main main.cpp ${SOURCE_FILES})
add_executable(tests tests.cpp ${SOURCE_FILES})

add_executable(lab_5 main.cpp tests.cpp src/lib.h  ${SOURCE_FILES} tests.cpp)

target_link_libraries(tests gtest)