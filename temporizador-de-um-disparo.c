#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

#define RED_PIN 13
#define GREEN_PIN 11
#define BLUE_PIN 12
#define BUTTON_A 5
#define INTERVAL 3000 // 3 segundos de intervalo entre as ações
#define DEBOUNCE_MS 50

uint last_interruption = 0;
bool is_button_enabled = true;

void setup_pin(uint gpio)
{
    gpio_init(gpio);
    gpio_set_dir(gpio, GPIO_OUT);
}

void setup_pushbutton(uint gpio)
{
    gpio_init(gpio);
    gpio_set_dir(gpio, GPIO_IN);
    gpio_pull_up(gpio); // configura em pull-up
}

// função para testar com a interrupção na placa
void interruption_handler(uint gpio, uint32_t event_mask)
{
    uint32_t current_time = to_ms_since_boot(get_absolute_time());
    // debounce do pushbutton
    if (current_time - last_interruption > DEBOUNCE_MS)
    {
        last_interruption = current_time;
        // aciona leds se o ciclo anterior tiver finalizado
        if (is_button_enabled)
        {
            gpio_put(BLUE_PIN, true);
            gpio_put(RED_PIN, true);
            gpio_put(GREEN_PIN, true);
            is_button_enabled = false;
        }
    }
}

// função para testar no simulador sem a interrupção
// void pushbutton_handler()
// {
//     uint32_t current_time = to_ms_since_boot(get_absolute_time());
//     // debounce do pushbutton
//     if (current_time - last_interruption > DEBOUNCE_MS)
//     {
//         last_interruption = current_time;
//         // aciona leds se o ciclo anterior tiver finalizado
//         if (is_button_enabled)
//         {
//             gpio_put(BLUE_PIN, true);
//             gpio_put(RED_PIN, true);
//             gpio_put(GREEN_PIN, true);
//         }
//     }
// }

int64_t alarm_callback(alarm_id_t id, void *user_data)
{
    // apaga o led azul caso aceso
    if (gpio_get(BLUE_PIN))
    {
        gpio_put(BLUE_PIN, false);
    }
    // apaga o led vermelho caso aceso
    else if (gpio_get(RED_PIN))
    {
        gpio_put(RED_PIN, false);
    }
    // apaga o led verde caso aceso
    else if (gpio_get(GREEN_PIN))
    {
        gpio_put(GREEN_PIN, false);
        // sinaliza que todos os leds já se apagaram
        is_button_enabled = true;
    }
    return INTERVAL * 1000;
}

int main()
{
    stdio_init_all();

    // configurando pinos dos leds
    setup_pin(RED_PIN);
    setup_pin(BLUE_PIN);
    setup_pin(GREEN_PIN);
    // configurando o pushbutton
    setup_pushbutton(BUTTON_A);
    // configurando o disparo
    add_alarm_in_ms(INTERVAL, alarm_callback, NULL, false);
    // habilitando a interrupção pelo pushbutton
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &interruption_handler);

    while (true)
    {
        // if (!gpio_get(BUTTON_A))
        // {
        //     pushbutton_handler();
        // }
        sleep_ms(10);
    }
}
