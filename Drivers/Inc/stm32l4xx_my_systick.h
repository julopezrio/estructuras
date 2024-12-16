#include<stdint.h>

// Base de SysTick y registros
#define SYSTICK_BASE 0xE000E010U
#define SYSTICK_CTRL (*(volatile uint32_t *)(SYSTICK_BASE + 0x0))
#define SYSTICK_LOAD (*(volatile uint32_t *)(SYSTICK_BASE + 0x4))
#define SYSTICK_VAL (*(volatile uint32_t *)(SYSTICK_BASE + 0x8))
#define SYSTICK_CALIB (*(volatile uint32_t *)(SYSTICK_BASE + 0xC))

// Bits de control en el registro SysTick_CTRL
#define SYSTICK_CTRL_ENABLE (1U << 0)  // Bit de habilitación
#define SYSTICK_CTRL_TICKINT (1U << 1) // Bit de interrupción
#define SYSTICK_CTRL_CLKSRC (1U << 2)  // Fuente de reloj (1: procesador)

// Prototipos de funciones
void SysTick_Init(uint32_t ticks);
void SysTick_DelayMs(uint32_t delay_ms);
void SysTick_Handler(void); // Manejador de interrupciones (debe enlazarse con el vector)

uint32_t SysTick_GetTick(void);


// Variable estática para almacenar los ticks del sistema
static volatile uint32_t system_ticks = 0;