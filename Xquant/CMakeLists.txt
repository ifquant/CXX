cmake_minimum_required(VERSION 3.10.0)
project(Xquant)

file(GLOB SRC_FILES *.cc)

add_executable(${PROJECT_NAME} ${SRC_FILES})

#target_link_libraries(${PROJECT_NAME})
