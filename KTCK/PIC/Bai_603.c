#include<tv_pickit2_shift_1.c>
#include<tv_pickit2_shift_lcd.c>
/*******************************************************/ 
void HienThi4Goc();
/*******************************************************/
void main()
{
   set_up_port_ic_chot();
   setup_lcd();
   HienThi4Goc();                                              
}
/*******************************************************/
void HienThi4Goc()
{
   lcd_command(0x80);
   lcd_data("A");
   lcd_command(0x80 + 19);
   lcd_data("B"); 
   lcd_command(0xD4);
   lcd_data("D");
   lcd_command(0xD4 + 19);
   lcd_data("C");
}
