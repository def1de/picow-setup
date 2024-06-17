#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#define LED_PIN CYW43_WL_GPIO_LED_PIN

class Led{
    public:
        static bool isPanic;

        Led(){
            cyw43_arch_init();
        }

        void high(){
            cyw43_arch_gpio_put(LED_PIN, 1);
        }

        void low(){
            cyw43_arch_gpio_put(LED_PIN, 0);
        }

        void set(bool value){
            cyw43_arch_gpio_put(LED_PIN, value);
        }

        void toggle(){
            cyw43_arch_gpio_put(LED_PIN, !cyw43_arch_gpio_get(LED_PIN));
        }

        void panic(){
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
        PinOut(uint pin){
            this->pin = pin;
            gpio_init(pin);
            gpio_set_dir(pin, GPIO_OUT);
        }

        void high(){
            gpio_put(pin, 1);
        }

        void low(){
            gpio_put(pin, 0);
        }

        void set(bool value){
            gpio_put(pin, value);
        }

        void toggle(){
            gpio_put(pin, !gpio_get(pin));
        }
};


class PinIn{
    private:
        uint pin;
    public:
        PinIn(uint pin){
            this->pin = pin;
            gpio_init(pin);
            gpio_set_dir(pin, GPIO_IN);
        }

        bool get(){
            return gpio_get(pin);
        }
};