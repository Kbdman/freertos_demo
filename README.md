# freertos_demo

Build a freertos demo for my STM32F407 dev board. 
This demo is based on FreeRTOSv202212.01    
Now it can be built and flashed to the dev board, but its Task Scheduler do not works well.     
The reason seems to be that I havn't setup the heap.        

## Build
1. Download and unzip source code of FreeRTOSv202212.01
2. Setup an environment variable **FREERTOS_INCLUDES** which points to the include folder of FreeRTOSv202212.01
3. Download and unzip toolchain arm-none-eabi from https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads
4. Add ${toolchain}/bin to enviroment variable **PATH**
5. build with cmake

## How to get here
1. Create a dummy program which can be built and execute on your target
2. Find **portmacro.h** and **port.c** which are suitable for your device in portable folder of FreeRTOSv202212.01 and move them to your project.
3. Copy a **FreeRTOSConfig.h** to your project and do some customization.
4. Copy **list.c** **tasks.c** **queue.c** to you project
5. Seems some functions in **tasks.c** are using memset and memcpy,so implement them
6. Call **vTaskStartScheduler** in your main function.