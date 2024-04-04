
#include "Serial.h"

int main(void)
{
	// printNum=0;
	// delay_init();
	// LED_Init();
	// LED0_ON();
	Serial_Init();

	// uart_init(9600);
	//  LCD_Init();
	//  POINT_COLOR=RED;
	//  LCD_Clear(WHITE);
	//  POINT_COLOR=RED;

	Serial_SendByte(114514);
	// Serial_SendByte('A');
	// printf("Num=%d\r\n", 666);

	while (1)
	{
	}
}
