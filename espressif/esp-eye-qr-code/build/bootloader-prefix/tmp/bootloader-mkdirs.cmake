# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/francesco/esp/esp-idf/components/bootloader/subproject"
  "/home/francesco/Documents/examples/espressif/esp-eye-qr-code/build/bootloader"
  "/home/francesco/Documents/examples/espressif/esp-eye-qr-code/build/bootloader-prefix"
  "/home/francesco/Documents/examples/espressif/esp-eye-qr-code/build/bootloader-prefix/tmp"
  "/home/francesco/Documents/examples/espressif/esp-eye-qr-code/build/bootloader-prefix/src/bootloader-stamp"
  "/home/francesco/Documents/examples/espressif/esp-eye-qr-code/build/bootloader-prefix/src"
  "/home/francesco/Documents/examples/espressif/esp-eye-qr-code/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/francesco/Documents/examples/espressif/esp-eye-qr-code/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
