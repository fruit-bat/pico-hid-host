foreach(target
    hid_host_utils
    hid_ri
)
    add_executable(${target}_tests
    ${PICO_PROJECT_FOLDER}/src/hid_host_utils.c
    ${PICO_PROJECT_FOLDER}/src/hid_ri.c
    test_${target}.c    
    )

    target_compile_definitions(${target}_tests PRIVATE
        CFG_TUSB_MCU rp2040
    )

    target_link_libraries(${target}_tests
        Unity
    )

    add_test(${target}_suite ${target}_tests)
endforeach()
