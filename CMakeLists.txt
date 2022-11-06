cmake_minimum_required(VERSION 3.23)
project(li3 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(li3
        src/main.c
        src/rides.c
        src/rides.h
        src/drivers.c
        src/drivers.h
        src/users.c
        src/users.h
        src/parsing.c
        src/parsing.h
        )

target_link_libraries(li3 m)