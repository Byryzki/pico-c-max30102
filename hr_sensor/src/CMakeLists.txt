add_library(sensor_lib)

target_sources(sensor_lib PRIVATE
    DFRobot_MAX30102.cpp
    PBA/heartRate.cpp
    SPO2/algorithm.cpp 
)

target_include_directories(sensor_lib PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/PBA
    ${CMAKE_CURRENT_LIST_DIR}/SPO2
)

target_link_libraries(sensor_lib
    pico_stdlib
    hardware_i2c
    hardware_timer
    hardware_clocks
)