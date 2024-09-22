project (pico-hid-host-tests)

cmake_minimum_required(VERSION 3.12)

add_compile_options(-Wall)

get_filename_component(PICO_FOLDER ${CMAKE_CURRENT_LIST_DIR}/../.. ABSOLUTE)

set(TINYUSB_TARGET tusb)
set(CFG_TUSB_MCU x86)

add_subdirectory(${PICO_FOLDER}/pico-hid-host "${CMAKE_CURRENT_BINARY_DIR}/pico-hid-host")

# Unity testing - start
include(CTest)

add_library(Unity STATIC
  ${PICO_FOLDER}/Unity/src/unity.c
)

target_include_directories(Unity PUBLIC
  ${PICO_FOLDER}/Unity/src
  ${PICO_FOLDER}/pico-sdk/lib/tinyusb/src
  ${PICO_FOLDER}/pico-sdk/src/rp2_common/tinyusb/include/
  ${PICO_FOLDER}/pico-sdk/lib/tinyusb/hw/
)

add_subdirectory(suite1)
