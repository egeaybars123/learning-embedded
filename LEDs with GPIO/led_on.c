#include "stm32f4xx_hal.h"                  // Device header

void configureLEDpins(void);

int main(void) {
	
	__HAL_RCC_GPIOD_CLK_ENABLE();
	
	configureLEDpins();
	
	while(1) {
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_SET); // GPIO_PIN_SET = 1 (comes from the enum)
	}
}


void configureLEDpins(void) {
	GPIO_InitTypeDef LEDconfig;
	
	LEDconfig.Mode = GPIO_MODE_OUTPUT_PP;
	LEDconfig.Pin = GPIO_PIN_11;
	
	HAL_GPIO_Init(GPIOD, &LEDconfig);
	
	
}
