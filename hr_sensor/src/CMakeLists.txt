add_subdirectory(PBA)
add_subdirectory(SPO2)

add_library(sensor_lib
    DFRobot_MAX30102.cpp
    PBA/heartRate.cpp
    SPO2/algorithm.cpp  
)

link_directories(${PROJECT_SOURCE_DIR}/example)