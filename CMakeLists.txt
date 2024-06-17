cmake_minimum_required(VERSION 3.13) # Set the minimum version of CMake

set(PICO_SDK_PATH "$ENV{HOME}/Documents/pico/pico-sdk") # Change this to the path to your pico-sdk

include(pico_sdk_import.cmake) # Include the pico-sdk

project(project C CXX ASM) # Define the project
set(CMAKE_C_STANDARD 11) # Set the C standard
set(CMAKE_CXX_STANDARD 17) # Set the C++ standard

pico_sdk_init() # Initialize the pico-sdk

add_executable(mainexec # Create an executable
    main.cpp # Add the source files
)

pico_enable_stdio_usb(mainexec 1) # Enable USB output
pico_enable_stdio_uart(mainexec 0) # Disable UART output

pico_add_extra_outputs(mainexec) # Add extra outputs

# Include the current directory
target_include_directories(mainexec PRIVATE ${CMAKE_CURRENT_LIST_DIR})

# Link the libraries
target_link_libraries(mainexec pico_cyw43_arch_lwip_threadsafe_background pico_stdlib)