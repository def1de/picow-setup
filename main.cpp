#include "pico/stdlib.h"
#include "pins.hpp"
#include <cmath>
#include <cstdio>

int main() {
    stdio_init_all();

    auto xAxis = AnalogIn(27, 1);
    auto yAxis = AnalogIn(26, 0);
    auto button = PinIn(0);

    int xOffsetStationary = (int)xAxis.read();
    int yOffsetStationary = (int)yAxis.read();

    int iter = 2;

    while (true) {
        // Subtract the offset from the readings
        double xInput = ((xAxis.read()-xOffsetStationary)/2047.5);
        double yInput = ((yAxis.read()-yOffsetStationary)/2047.5);
        printf("Iteration: %d\n"
               "xAxis: %f,"
                "xRaw: %d\n"
                "yAxis: %f,"
                "yRaw: %d\n"
                "button: %d\n\n"
                ,iter , xInput, xAxis.read(), yInput, yAxis.read(), button.get());
        sleep_ms(100);
    }
    return 1;
}