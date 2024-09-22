foreach(target
    hid_host_utils
    hid_ri
    hid_rip
    hid_host_joy
)
    add_executable(${target}_tests
        ${PICO_PROJECT_FOLDER}/src/hid_host_utils.c
        ${PICO_PROJECT_FOLDER}/src/hid_ri.c
        ${PICO_PROJECT_FOLDER}/src/hid_rip.c
        ${PICO_PROJECT_FOLDER}/src/hid_host_common.c
        ${PICO_PROJECT_FOLDER}/src/hid_host_joy.c
        stuff.c
        test_${target}.c    
    )

    target_compile_definitions(${target}_tests PRIVATE
        CFG_TUSB_MCU=rp2040
        HID_MAX_JOYSTICKS=4
    )

    target_link_libraries(${target}_tests
        Unity
    )

    add_test(${target}_suite ${target}_tests)
endforeach()

add_executable(all_tests
    all.c
)
