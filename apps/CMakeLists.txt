cmake_minimum_required(VERSION 3.12)

# Determine the MCU type and configure accordingly
set(PICO_MCU "rp2040" CACHE STRING "Specify Pico MCU type")

if ((${PICO_MCU} STREQUAL "rp2350"))
    set(PICO_PLATFORM "rp2350-arm-s")
else()
    set(PICO_PLATFORM "rp2040")
endif()

# Look for board file in local board directory
set(PICO_BOARD_HEADER_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/boards)

# Pico SDC on Raspberry Pi 4
cmake_policy(VERSION 3.12)

# Pico SDC Toolchai on Windows 10
# cmake_policy(SET CMP0115 OLD)

# Pull in PICO SDK (must be before project)
include(pico_sdk_import.cmake)

# We also need PICO EXTRAS
include(pico_extras_import.cmake)

project(hid-host C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (PICO_SDK_VERSION_STRING VERSION_LESS "2.0.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 2.0.0 (or later) required. Current version is ${PICO_SDK_VERSION_STRING}")
endif()

pico_sdk_init()

add_compile_options(-Wall)

get_filename_component(PICO_FOLDER ${CMAKE_CURRENT_LIST_DIR}/../.. ABSOLUTE)

add_subdirectory(${PICO_FOLDER}/pico-hid-host "${CMAKE_CURRENT_BINARY_DIR}/pico-hid-host")

add_subdirectory(hid_host_serial_test  "${CMAKE_CURRENT_BINARY_DIR}/hid_host_serial_test")

