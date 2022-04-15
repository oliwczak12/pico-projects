cmake_minimum_required(VERSION 3.23)

include(pico_sdk_import.cmake)

project(pico-transistors)

pico_sdk_init()

add_executable(blink_led 
blink_led.c
)

target_link_libraries(blink_led pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(blink_led 1)
pico_enable_stdio_uart(blink_led 0)

pico_add_extra_outputs(blink_led)