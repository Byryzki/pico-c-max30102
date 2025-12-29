link_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(test basicRead/basicRead.cpp)

target_link_libraries(test sensor_lib)