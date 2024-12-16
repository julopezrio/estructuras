#include<stdint.h>

// Base addresses para GPIO
#define GPIOA_BASE 0x48000000U
#define GPIOB_BASE 0x48000400U
#define GPIOC_BASE 0x48000800U

// Registros GPIO
#define GPIO_MODER_OFFSET 0x00U   // Modo de los pines

#define GPIO_PUPDR_OFFSET 0x0CU   // Pull-up/pull-down
#define GPIO_IDR_OFFSET 0x10U     // Entrada de datos
#define GPIO_ODR_OFFSET 0x14U     // Salida de datos

#define GPIO_MODER(gpio) (*(volatile uint32_t *)((gpio) + GPIO_MODER_OFFSET))
#define GPIO_PUPDR(gpio) (*(volatile uint32_t *)((gpio) + GPIO_PUPDR_OFFSET))
#define GPIO_IDR(gpio) (*(volatile uint32_t *)((gpio) + GPIO_IDR_OFFSET))
#define GPIO_ODR(gpio) (*(volatile uint32_t *)((gpio) + GPIO_ODR_OFFSET))

// Prototipos de funciones
void GPIO_SetPinAsOutput(uint32_t gpio_base, uint32_t pin);
void GPIO_SetPin(uint32_t gpio_base, uint32_t pin);
void GPIO_ClearPin(uint32_t gpio_base, uint32_t pin);
void GPIO_TogglePin(uint32_t gpio_base, uint32_t pin);

void GPIO_SetPinAsInput(uint32_t gpio_base, uint32_t pin);
void GPIO_EnablePullUp(uint32_t gpio_base, uint32_t pin);
uint8_t GPIO_ReadPin(uint32_t gpio_base, uint32_t pin);
