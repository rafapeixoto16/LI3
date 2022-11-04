cmake_minimum_required(VERSION 3.23)
project(li3 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(li3
        code/main.c
        code/parser.c
        code/parser.h
        code/rides.c
        code/rides.h
        code/drivers.c
        code/drivers.h
        code/users.c
        code/users.h
        )

target_link_libraries(li3 m)