
add_executable(hid_host_serial_test
  ${CMAKE_CURRENT_LIST_DIR}/src/main.c
)

target_compile_definitions(hid_host_serial_test PRIVATE

)

target_link_libraries(hid_host_serial_test
  pico_stdlib
  pico_util
  pico_hid_host
  tinyusb_host
  tinyusb_board  
)

# create map/bin/hex file etc.
pico_add_extra_outputs(hid_host_serial_test)
