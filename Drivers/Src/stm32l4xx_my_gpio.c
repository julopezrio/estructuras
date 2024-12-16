#include <stm32l4xx_my_gpio.h>

/*
 * @brief Configura un pin GPIO como salida.
 * @param gpio_base: Dirección base del puerto GPIO.
 * @param pin: Número de pin (0-15).
 */
void GPIO_SetPinAsOutput(uint32_t gpio_base, uint32_t pin)
{
    GPIO_MODER(gpio_base) &= ~(0x3U << (pin * 2)); // Limpiar bits
    GPIO_MODER(gpio_base) |= (0x1U << (pin * 2));  // Configurar como salida
}

/*
 * @brief Establece un pin GPIO a nivel alto.
 * @param gpio_base: Dirección base del puerto GPIO.
 * @param pin: Número de pin (0-15).
 */
void GPIO_SetPin(uint32_t gpio_base, uint32_t pin)
{
    GPIO_ODR(gpio_base) |= (1U << pin);
}

/*
 * @brief Establece un pin GPIO a nivel bajo.
 * @param gpio_base: Dirección base del puerto GPIO.
 * @param pin: Número de pin (0-15).
 */
void GPIO_ClearPin(uint32_t gpio_base, uint32_t pin)
{
    GPIO_ODR(gpio_base) &= ~(1U << pin);
}

/*
 * @brief Cambia el estado de un pin GPIO.
 * @param gpio_base: Dirección base del puerto GPIO.
 * @param pin: Número de pin (0-15).
 */
void GPIO_TogglePin(uint32_t gpio_base, uint32_t pin)
{
    GPIO_ODR(gpio_base) ^= (1U << pin);
}

/*
 * @brief Configura un pin GPIO como entrada.
 * @param gpio_base: Dirección base del puerto GPIO.
 * @param pin: Número de pin (0-15).
 */
void GPIO_SetPinAsInput(uint32_t gpio_base, uint32_t pin)
{
    GPIO_MODER(gpio_base) &= ~(0x3U << (pin * 2)); // Limpiar bits (00 -> Modo entrada)
}

/*
 * @brief Habilita la resistencia de pull-up en un pin GPIO.
 * @param gpio_base: Dirección base del puerto GPIO.
 * @param pin: Número de pin (0-15).
 */
void GPIO_EnablePullUp(uint32_t gpio_base, uint32_t pin)
{
    GPIO_PUPDR(gpio_base) &= ~(0x3U << (pin * 2)); // Limpiar configuración actual
    GPIO_PUPDR(gpio_base) |= (0x1U << (pin * 2));  // Configurar pull-up (01 -> Pull-up)
}

/*
 * @brief Lee el estado de un pin GPIO.
 * @param gpio_base: Dirección base del puerto GPIO.
 * @param pin: Número de pin (0-15).
 * @return 1 si el pin está en alto, 0 si está en bajo.
 */
uint8_t GPIO_ReadPin(uint32_t gpio_base, uint32_t pin)
{
    // Leer el registro IDR del puerto GPIO
    uint32_t idr_value = GPIO_IDR(gpio_base);

    // Extraer el estado del pin especificado
    return (idr_value & (1U << pin)) ? 1 : 0;
}
