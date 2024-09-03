

cmake_minimum_required(VERSION 3.25)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_C_COMPILER_FORCED TRUE)
set(CMAKE_CXX_COMPILER_FORCED TRUE)

project(FreeRTOS_Demo)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostdlib -mcpu=cortex-m4 -mfloat-abi=hard  -g")
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/CMSIS/STM32F407)
include_directories($ENV{FREERTOS_INCLUDES})
include_directories($ENV{CMSIS_INCLUDES})

set(CMAKE_EXE_LINKER_FLAGS "-mcpu=cortex-m4 -T ${CMAKE_SOURCE_DIR}/link.ld")
add_executable(demo.elf src/main.c src/port.c src/tasks.c src/list.c src/queue.c src/mem.c src/heap_4.c src/log.c src/peripheral.c src/common.c)
add_custom_command(TARGET demo.elf POST_BUILD
                    COMMAND ${CMAKE_OBJCOPY} -O binary demo.elf demo.bin
)