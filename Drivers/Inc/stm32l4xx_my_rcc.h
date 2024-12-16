#include<stdint.h>
// Macros para RCC
#define RCC_BASE 0x40021000U
#define RCC_AHB2ENR (*(volatile uint32_t *)(RCC_BASE + 0x4C))
#define RCC_APB2ENR (*(volatile uint32_t *)(RCC_BASE + 0x60))

// Macros para habilitar periféricos
#define RCC_GPIOA_ENABLE (1U << 0)
#define RCC_GPIOB_ENABLE (1U << 1)
#define RCC_GPIOC_ENABLE (1U << 2)

// Prototipos de funciones
void RCC_EnableAHB2(uint32_t peripherals);
void RCC_EnableAPB2(uint32_t peripherals);