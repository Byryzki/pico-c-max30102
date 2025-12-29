add_executable(hr_sensor_exe
    ${CMAKE_CURRENT_LIST_DIR}/basicRead/basicRead.cpp
)


target_link_libraries(hr_sensor_exe
    sensor_lib
    pico_stdlib
)

# Add the standard include files to the build
target_include_directories(hr_sensor_exe PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

# Add executable. Default name is the project name, version 0.1

pico_set_program_name(hr_sensor_exe "hr_sensor")
pico_set_program_version(hr_sensor_exe "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(hr_sensor_exe 0)
pico_enable_stdio_usb(hr_sensor_exe 1)

pico_add_extra_outputs(hr_sensor_exe)

target_link_libraries(hr_sensor_exe
    hardware_i2c
    hardware_timer
    hardware_watchdog
    hardware_clocks
)