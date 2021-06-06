cmake_minimum_required(VERSION 3.0)

project(llama LANGUAGES C)

add_executable(llama main.c scanner.c)

install(TARGETS llama RUNTIME DESTINATION bin)
