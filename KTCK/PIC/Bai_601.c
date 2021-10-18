#include<tv_pickit2_shift_1.c>
#include<tv_pickit2_shift_lcd.c>
/******************************************************************/
void main()
{
   set_up_port_ic_chot();
   setup_lcd();
   lcd_command(0xd4);                           
   lcd_data("Le Van Tho"); 
   
}                   
