# pico-hid-host
Library to host HID devices on Pico Pi alongside TinyUSB



## Testing

Build and run the test suite from the repository root:
```sh
cd /path/to/pico
git clone https://github.com/throwtheswitch/unity Unity
cd pico-hid-host/test
mkdir -p build
cd build
cmake ..
cmake --build . -j2
./suite1/all_tests
```

To run the tests again later:
```sh
cd /path/to/pico/pico-hid-host/test/build
./suite1/all_tests
```

