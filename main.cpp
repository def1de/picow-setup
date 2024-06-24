#include "pico/stdlib.h"
#include "pins.hpp"
#include <cmath>
#include <cstdio>

int main() {
    stdio_init_all();

    while (true) {
        Led::toggle();
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
    return 1;
}