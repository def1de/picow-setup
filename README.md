# Raspberry Pi Pico W Setup
Helps you to start with developing for raspberry pi pico (W) using pico-sdk and C/C++
---
### Quick setup guide
- Clone pico-sdk repository `git clone https://github.com/raspberrypi/pico-sdk.git`
- Clone this repository `git clone https://github.com/def1de/picow-setup.git`
- Open CMakeLists.txt and set `PICO_SDK_PATH=/path/to/your/sdk/folder`
- make and enter build directory `mkdir build && cd build`
- run cmake using `cmake .. -DPICO_BOARD=pico_w`
- Build the file using `make`
- Copy over `mainexec.uf2` to your pico board
- Enjoy your first pico W project

**Note that this repository includes pre-designed classes to further assist and simplify development process. Read wiki to learn more**
