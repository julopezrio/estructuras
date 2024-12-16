#include <stdint.h>
#include <stm32l4xx_my_rcc.h>
#include <stm32l4xx_my_systick.h>
#include <stm32l4xx_my_gpio.h>

// Habilita interrupciones globales
void EnableGlobalInterrupts(void)
{
    __asm volatile("CPSIE i" ::: "memory");
}

// Definiciones para el botón y el LED
#define LED_PORT GPIOA_BASE
#define LED_PIN 5

#define BUTTON_PORT GPIOC_BASE
#define BUTTON_PIN 13

// Definir los estados de la FSM
typedef enum {
    BUTTON_RELEASED,
    BUTTON_PRESSED
} Button_State_t;

// Variables globales
Button_State_t button_state = BUTTON_RELEASED;

int main(void)
{
    // Habilitar relojes necesarios
    RCC_EnableAPB2(0x1); // Ejemplo: habilitar periféricos de APB2

    // Inicializa el reloj del sistema 1ms para clk = 4MHz
    SysTick_Init(3999);

    // Habilita interrupciones globales
    EnableGlobalInterrupts();

    // Habilita el reloj de los puertos GPIO
    RCC_EnableAHB2(RCC_GPIOA_ENABLE | RCC_GPIOB_ENABLE | RCC_GPIOC_ENABLE);

    // Configurar GPIOA (pin 5 como salida para el LED)
    GPIO_SetPinAsOutput(LED_PORT, LED_PIN);

    // Configurar GPIOC (pin 13 como entrada para el botón)
    GPIO_SetPinAsInput(BUTTON_PORT, BUTTON_PIN);
    GPIO_EnablePullUp(BUTTON_PORT, BUTTON_PIN); // Activar pull-up interno

    // Apagar LED inicialmente
    GPIO_ClearPin(LED_PORT, LED_PIN);

    uint8_t coupling_flag = 0;
    uint32_t last_tick = 0;

    // Bucle infinito
    while (1)
    {


        if ((SysTick_GetTick() - last_tick) >= 100)
        {
            last_tick = SysTick_GetTick();
            // Lectura del estado del botón
            uint8_t button_input = !GPIO_ReadPin(BUTTON_PORT, BUTTON_PIN); // Botón presionado (0 -> activo)

            // Actualización de la máquina de estados
            switch (button_state)
            {
                case BUTTON_RELEASED:
                    if (button_input)
                    {
                        button_state = BUTTON_PRESSED;
                        // GPIO_SetPin(LED_PORT, LED_PIN); // Encender LED
                    }
                    break;
                case BUTTON_PRESSED:
                    if (!button_input)
                    {
                        button_state = BUTTON_RELEASED;
                        coupling_flag=1;
                        // GPIO_ClearPin(LED_PORT, LED_PIN); // Apagar LED
                    }
                    break;

                default:
                    // Estado inválido, reiniciar al estado inicial
                    button_state = BUTTON_RELEASED;
                    break;
            }
        }
    }

    return 0;
}

//on/off led con parapdeo