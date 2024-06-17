#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "pins.hpp"

int main(){
    stdio_init_all();

    Led led;


    while (true)
    {
        led.toggle();
        sleep_ms(500);
    }

    return 1;
}