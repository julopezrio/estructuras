#include <stm32l4xx_my_systick.h>


/*
 * @brief Inicializa el temporizador SysTick.
 * @param ticks: Número de ticks antes de que ocurra la interrupción.
 *               Este valor se usa para generar un intervalo de tiempo fijo.
 */
void SysTick_Init(uint32_t ticks)
{
    // Configurar el valor de recarga
    SYSTICK_LOAD = ticks - 1;

    // Reiniciar el valor del contador actual
    SYSTICK_VAL = 0;

    // Configurar y habilitar SysTick con interrupciones
    SYSTICK_CTRL = SYSTICK_CTRL_ENABLE | SYSTICK_CTRL_TICKINT | SYSTICK_CTRL_CLKSRC;
}

/*
 * @brief Genera un retardo en milisegundos utilizando el contador SysTick.
 * @param delay_ms: Tiempo en milisegundos a esperar.
 */
void SysTick_DelayMs(uint32_t delay_ms)
{
    uint32_t start_tick = SysTick_GetTick();
    while ((SysTick_GetTick() - start_tick) < delay_ms)
    {
        // Esperar el tiempo especificado
    }
}

/*
 * @brief Devuelve el número de ticks desde el inicio del sistema.
 * @return Número de ticks del sistema.
 */
uint32_t SysTick_GetTick(void)
{
    return system_ticks;
}

/*
 * @brief Manejador de interrupción del temporizador SysTick.
 *        Esta función se ejecuta cada vez que ocurre una interrupción de SysTick.
 */
void SysTick_Handler(void)
{
    system_ticks++;
}
