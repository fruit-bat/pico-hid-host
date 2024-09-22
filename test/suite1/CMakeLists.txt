


add_executable(hid_host_utils_tests
    test_hid_host_utils.c
)

target_compile_definitions(hid_host_utils_tests PRIVATE
    CFG_TUSB_MCU rp2040
)

target_link_libraries(hid_host_utils_tests
    pico_hid_host
    Unity
)

add_test(suite_1_test hid_host_utils_tests)
