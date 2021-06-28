void SysTick_with_LCD()
{
 int index = 0;
 gExNum = (unsigned int) SysTick_with_LCD;

 MyLedInit();
 LCD_Setup();
 STM3210B_LCD_Init();

 LCD_Clear(White);

 LCD_SetTextColor(Blue);
 LCD_SetBackColor(White);

 *(unsigned int *) 0xE000E010 &= ~(0x1<<0);
 *(unsigned int *) 0xE000E010 &= ~(1<<2);
 *(unsigned int *) 0xE000E010 &= ~(1<<4);
 *(unsigned int *) 0xE000E014 = 900000;
 *(unsigned int *) 0xE000E010 |= (1<<1);
 *(unsigned int *) 0xE000E010 |= (1<<0);

 while(1)
 {
 Delay(10);

 if(Uart_GetKey())
 break;
 }

 *(unsigned int *) 0xE000E010 &= ~(0x1<<0);

 gExNum = 0;
}
