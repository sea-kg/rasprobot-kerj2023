cmake_minimum_required(VERSION 3.0)

set(target "rasprobot-kerj2023")
project(${target} C CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/src.wsjcpp/CMakeLists.txt)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${${target}_SOURCE_DIR})

# include header dirs
list (APPEND WSJCPP_INCLUDE_DIRS "src")
list (APPEND WSJCPP_INCLUDE_DIRS "include")

list (APPEND WSJCPP_SOURCES "src/main.cpp")
list (APPEND WSJCPP_SOURCES "src/controlserver.cpp")
list (APPEND WSJCPP_SOURCES "src/gpiopin.cpp")


#### BEGIN_WSJCPP_APPEND
#### END_WSJCPP_APPEND

include_directories(${WSJCPP_INCLUDE_DIRS})

add_executable (${target} ${WSJCPP_SOURCES})

target_link_libraries(${target} ${WSJCPP_LIBRARIES})

install(
    TARGETS
        ${target}
    RUNTIME DESTINATION
        /usr/bin
)

