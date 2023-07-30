cmake_minimum_required (VERSION 3.5)

set(PROJECT_NAME "a2xConv")
set(main_SRC ${PROJECT_RESOURCE_DIR}/main.c)
set(converter_SRC ${PROJECT_RESOURCE_DIR}/converter.c)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wno-unused-parameter")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic -Wshadow -Wundef -Wno-missing-field-initializers")

#define UT
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DUT=1")

#undefine UT
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -UUT=0")


project(${PROJECT_NAME} VERSION 0.0.0.1 LANGUAGES C)
#project(myprogram C)

add_executable (main ${main_SRC})

target_link_libraries (main converter)