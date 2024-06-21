#include "pico/stdlib.h"
#include "pins.hpp"
#include <cmath>
#include <cstdio>

int main() {
    stdio_init_all();

    int i = 0;

    while (true) {
        printf("Hello, world! %d\n", i++);
        sleep_ms(1000);
    }

    return 1;
}