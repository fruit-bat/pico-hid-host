add_library(pico_hid_host INTERFACE)

target_sources(pico_hid_host INTERFACE
  ${CMAKE_CURRENT_LIST_DIR}/src/hid_app.c
  ${CMAKE_CURRENT_LIST_DIR}/src/hid_host_common.c
  ${CMAKE_CURRENT_LIST_DIR}/src/hid_host_info.c
  ${CMAKE_CURRENT_LIST_DIR}/src/hid_host_joy.c
  ${CMAKE_CURRENT_LIST_DIR}/src/hid_host_mouse.c
  ${CMAKE_CURRENT_LIST_DIR}/src/hid_host_utils.c
  ${CMAKE_CURRENT_LIST_DIR}/src/hid_ri.c
  ${CMAKE_CURRENT_LIST_DIR}/src/hid_rip.c
  ${CMAKE_CURRENT_LIST_DIR}/src/xinput_host.c
)

target_include_directories(pico_hid_host INTERFACE
    src
)
