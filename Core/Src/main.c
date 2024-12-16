#include <stdint.h>
#include <stm32l4xx_my_rcc.h>
#include <stm32l4xx_my_systick.h>
#include <stm32l4xx_my_gpio.h>

// Habilita interrupciones globales
void EnableGlobalInterrupts(void)
{
    __asm volatile("CPSIE i" ::: "memory");
}

void delay_ms(volatile uint32_t delay) {
    for (volatile uint32_t i = 0; i < delay * 1000; i++) {
        __asm__("nop");
    }
}

// Definiciones para el botón y el LED
#define LED_PORT GPIOA_BASE
#define LED_PIN 5
#define LED_PORT_1 GPIOB_BASE
#define LED_PIN_1 12


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
    //RCC_EnableAPB2(0x1); // Ejemplo: habilitar periféricos de APB2

    // Inicializa el reloj del sistema 1ms para clk = 4MHz
    //SysTick_Init(3999);

    // Habilita interrupciones globales
    //EnableGlobalInterrupts();

    // Habilita el reloj de los puertos GPIO
    RCC_EnableAHB2(RCC_GPIOA_ENABLE | RCC_GPIOB_ENABLE | RCC_GPIOC_ENABLE);

    // Configurar GPIOA (pin 5 como salida para el LED)
    GPIO_SetPinAsOutput(LED_PORT, LED_PIN);
    GPIO_SetPinAsOutput(LED_PORT_1, LED_PIN_1);

    // Configurar GPIOC (pin 13 como entrada para el botón)
    GPIO_SetPinAsInput(BUTTON_PORT, BUTTON_PIN);
    GPIO_EnablePullUp(BUTTON_PORT, BUTTON_PIN); // Activar pull-up interno

    // Apagar LED inicialmente
    //GPIO_ClearPin(LED_PORT, LED_PIN);
    //GPIO_ClearPin(LED_PORT_1, LED_PIN_1);
    GPIO_SetPin(LED_PORT_1,LED_PIN_1);

    
    


    //uint8_t led_state = 0;
    // Bucle infinito

    while (1){
        GPIO_SetPin(LED_PORT,LED_PIN);
        delay_ms(100);
        GPIO_SetPin(LED_PORT_1,LED_PIN_1);
        GPIO_ClearPin(LED_PORT, LED_PIN);
        delay_ms(100);
        GPIO_ClearPin(LED_PORT_1, LED_PIN_1);
        GPIO_SetPin(LED_PORT,LED_PIN);
        delay_ms(100);
    }
    return 0;
}

/*uint8_t led_state = 0;
    // Bucle infinito

    while (1){
        if(GPIO_ReadPin(BUTTON_PORT,BUTTON_PIN)==0){
            delay_ms(5);
            if ((GPIO_ReadPin(BUTTON_PORT,BUTTON_PIN))==0){
                led_state=!led_state;
                delay_ms(50);
                }
        }
        if(led_state){
            GPIO_TogglePin(LED_PORT,LED_PIN);
            delay_ms(50);
            }else{
                    GPIO_ClearPin(LED_PORT,LED_PIN);
                }
    }
    return 0;
}*/
