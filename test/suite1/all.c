#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    printf("Running all tests\n");
    int r = 0;
    if(system("suite1/hid_host_joy_tests") < 0) r = -1;
    if(system("suite1/hid_host_utils_tests") < 0) r = -1;
    if(system("suite1/hid_rip_tests") < 0) r = -1;
    if(system("suite1/hid_ri_tests") < 0) r = -1;
    if (r < 0) printf("\nTEST FAILED\n");
    else printf("\nALL TEST PASSED\n");
    return r;
}
