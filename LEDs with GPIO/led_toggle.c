#include "stm32f4xx_hal.h"                  // Device header

void configureLEDpins(void);

int main(void) {
	
	__HAL_RCC_GPIOD_CLK_ENABLE();
	
	
	configureLEDpins();
	
	while(1) {
			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_11);
			for(uint32_t i = 0; i < 2000000; i++) {} //Timer would be more accurate, but this is fine for now.
	}
}


void configureLEDpins(void) {
	GPIO_InitTypeDef LEDconfig;
	
	LEDconfig.Mode = GPIO_MODE_OUTPUT_PP;
	LEDconfig.Pin = GPIO_PIN_11;
	
	HAL_GPIO_Init(GPIOD, &LEDconfig);
	
	
}
