project(FreeRTOS_Demo)
cmake_minimum_required(VERSION 3.25)
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_C_COMPILER_FORCED TRUE)
set(CMAKE_CXX_COMPILER_FORCED TRUE)
set(CMAKE_EXE_LINKER_FLAGS "-mcpu=cortex-m4 -nostdlib -T ${CMAKE_SOURCE_DIR}/link.ld")
add_executable(demo.elf src/main.c )
add_custom_command(TARGET demo.elf POST_BUILD
                    COMMAND ${CMAKE_OBJCOPY} -O binary demo.elf demo.bin
)