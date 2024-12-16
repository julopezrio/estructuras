#include<stm32l4xx_my_rcc.h>


/*
 * @brief Habilita periféricos en el bus AHB2.
 * @param peripherals: Máscara de los periféricos a habilitar.
 */
void RCC_EnableAHB2(uint32_t peripherals)
{
    RCC_AHB2ENR |= peripherals;
}

/*
 * @brief Habilita periféricos en el bus APB2.
 * @param peripherals: Máscara de los periféricos a habilitar.
 */
void RCC_EnableAPB2(uint32_t peripherals)
{
    RCC_APB2ENR |= peripherals;
}