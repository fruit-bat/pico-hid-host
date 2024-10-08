/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2024 Fruit-Bat
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * 
 * This module contains an example of mapping a HID report to a simplified 
 * local joystick definition. This simple model has:
 *        2x XY axes (X, Y and Z, Rz)
 *        1x HAT control
 * up to 32x Buttons (but have to be defined in one range in the HID description)
 * 
 * Applications will still need to allow mapping of axis and buttons to 
 * particlar functions.
 * 
 * There are many ways a HID report can describe a joystick and this code
 * only copes with a few of them. 
 */

#ifndef _TUSB_HID_HOST_JOY_H_
#define _TUSB_HID_HOST_JOY_H_

#include "hid_host_common.h"

#ifdef __cplusplus
 extern "C" {
#endif

#ifndef HID_MAX_JOYSTICKS
#define HID_MAX_JOYSTICKS 2
#endif

// Very simple representation of a joystick to try and map to
// (and this will be quite tricky enough).
typedef struct {
  int32_t x1;
  int32_t y1;
  int32_t x2;
  int32_t y2;
  int32_t hat;
  uint32_t buttons;
} tusb_hid_simple_joystick_values_t;

typedef union TU_ATTR_PACKED
{
  uint32_t combined;
  struct TU_ATTR_PACKED
  {
    uint8_t instance     :8;
    uint8_t dev_addr     :8;
    uint8_t report_id    :8;
    uint8_t in_use       :8;
  } elements;
} tusb_hid_simple_joystick_key_t;

// Simple joystick definitions and values
typedef struct {
  tusb_hid_simple_joystick_key_t key;
  uint8_t report_length; // requied report length in bytes
  bool has_values;
  tusb_hid_simple_axis_t axis_x1;
  tusb_hid_simple_axis_t axis_y1;
  tusb_hid_simple_axis_t axis_x2;
  tusb_hid_simple_axis_t axis_y2;
  tusb_hid_simple_axis_t hat;
  tusb_hid_simple_buttons_t buttons;
  tusb_hid_simple_joystick_values_t values;
  uint32_t updated;
} tusb_hid_simple_joystick_t;

// Process the HID descriptor usages
// These are handled when an 'input' item is encountered.
void tuh_hid_joystick_process_usages(
  tuh_hid_rip_state_t *pstate,
  tuh_hid_simple_input_data_t* jdata,
  uint32_t bitpos,
  uint8_t dev_addr,
  uint8_t instance
);

// Parse a HID report description for a joystick
void tuh_hid_joystick_parse_report_descriptor(uint8_t const* desc_report, uint16_t desc_len, uint8_t dev_addr, uint8_t instance);

// Fetch a previously allocated simple joystick
tusb_hid_simple_joystick_t* tuh_hid_get_simple_joystick(uint8_t dev_addr, uint8_t instance, uint8_t report_id);

// Free a previously allocated simple joystick
void tuh_hid_free_simple_joysticks_for_instance(uint8_t dev_addr, uint8_t instance);

// Free all previously allocated simple joysticks
void tuh_hid_free_simple_joysticks(void);

// Allocate a new simple joystick
tusb_hid_simple_joystick_t* tuh_hid_allocate_simple_joystick(uint8_t dev_addr, uint8_t instance, uint8_t report_id);

// If it exists, return an exisiting simple joystick, else allocate a new one
tusb_hid_simple_joystick_t* tuh_hid_obtain_simple_joystick(uint8_t dev_addr, uint8_t instance, uint8_t report_id);

// Process a HID report
// The report pointer should be advanced beyond the report ID byte.
// The length should not include the report ID byte.
// The length should be in bytes.
void tusb_hid_simple_joystick_process_report(tusb_hid_simple_joystick_t* simple_joystick, const uint8_t* report, uint8_t report_length);

// Send an axis and button report to stdout
//
// e.g.
//  dev_addr=  1, instance=  0, report_id=  0, x1= 127, y1= 127, x2= 127, y2= 127, hat=F, buttons=0000
//
void tusb_hid_print_simple_joystick_report(tusb_hid_simple_joystick_t* simple_joystick);

// Populate an array of the attached joysticks
uint8_t tuh_hid_get_simple_joysticks(tusb_hid_simple_joystick_t** simple_joysticks, uint8_t max_simple_joysticks);

#ifdef __cplusplus
}
#endif

#endif /* _TUSB_HID_HOST_JOY_H_ */
