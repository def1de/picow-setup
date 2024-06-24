#ifndef PINS_HPP
#define PINS_HPP

#include "pico/cyw43_arch.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"

#endif // PINS_HPP

#define LED_PIN CYW43_WL_GPIO_LED_PIN

class Led{
    public:
        static bool isPanic;

        Led(){
            cyw43_arch_init();
        }

        static void high(){
            cyw43_arch_gpio_put(LED_PIN, true);
        }

        static void low(){
            cyw43_arch_gpio_put(LED_PIN, false);
        }

        static void set(bool value){
            cyw43_arch_gpio_put(LED_PIN, value);
        }

        static void toggle(){
            cyw43_arch_gpio_put(LED_PIN, !cyw43_arch_gpio_get(LED_PIN));
        }

        static void panic(){
            if(isPanic){
                return;
            }
            isPanic = true;
            while (true)
            {
                toggle();
                sleep_ms(100);
            }
        }
};

bool Led::isPanic = false;

class PinOut{
    private:
        uint pin;
    public:
        explicit PinOut(uint pin){
            this->pin = pin;
            gpio_init(pin);
            gpio_set_dir(pin, GPIO_OUT);
        }

        void high() const{
            gpio_put(pin, true);
        }

        void low() const{
            gpio_put(pin, false);
        }

        void set(bool value) const{
            gpio_put(pin, value);
        }

        void toggle() const{
            gpio_put(pin, !gpio_get(pin));
        }
};


class PinIn{
    private:
        uint pin;
    public:
        explicit PinIn(uint pin){
            this->pin = pin;
            gpio_init(pin);
            gpio_set_dir(pin, GPIO_IN);
        }

        [[nodiscard]] bool get() const{
            return gpio_get(pin);
        }
};

class AnalogOut{
    private:
        uint pin;
    public:
        explicit AnalogOut(uint pin){
            this->pin = pin;
            adc_init();
            adc_gpio_init(pin);
        }

        void write(uint value) const{
                // Get a free PWM slice
                uint slice_num = pwm_gpio_to_slice_num(this->pin);

                // Set the frequency
                pwm_set_clkdiv(slice_num, 1.f);

                // Set the wrap value to 255 (like Arduino's analogWrite)
                pwm_set_wrap(slice_num, 255);

                // Set the PWM level
                pwm_set_chan_level(slice_num, PWM_CHAN_A, value);

                // Set the GPIO to be controlled by the PWM
                gpio_set_function(pin, GPIO_FUNC_PWM);

                // Enable the PWM
                pwm_set_enabled(slice_num, true);
        }
};

class AnalogIn{
    private:
        uint pin;
        uint channel; // 0 for GP26, 1 for GP27, 2 for GP28, 3 for GP29
    public:
        AnalogIn(uint pin, uint channel){
            this->pin = pin;
            this->channel = channel;
            adc_init();
            adc_gpio_init(pin);
        }

        [[nodiscard]] uint read() const{
            adc_select_input(this->channel);
            return adc_read();
        }
};