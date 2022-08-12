#include <stdio.h>
#include "NUC1xx.h"
#include "DrvSYS.h"
#include "DrvGPIO.h"
#include "scankey.h"
#include "NUC1xx-LB_002\LCD_Driver.h"


int32_t main(void)
{
	int8_t number;
	char TEXT0[16]="smpl_lcd_keypad";
	char TEXT1[16]="keypad:        ";

  UNLOCKREG();
	DrvSYS_Open(48000000);
	LOCKREG();
	
	Initial_panel();
	clr_all_panel();
	
	OpenKeyPad();
	print_lcd(0,TEXT0);
	
	while(1)
	{
		number=Scankey();
    sprintf(TEXT1+8,"%d",number);
		print_lcd(1,TEXT1);
		print_lcd(2,"HEllo_World");
    DrvSYS_Delay(500);
	}
}










