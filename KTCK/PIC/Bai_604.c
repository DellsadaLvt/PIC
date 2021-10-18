#include<tv_pickit2_shift_1.c>
#include<tv_pickit2_shift_lcd.c>
/***************************************************************/
void Dich();  
/***************************************************************/
void main()
{
   set_up_port_ic_chot();
   setup_lcd();                            
   lcd_command(0x80 + 19);
   lcd_data("QSD;JG");         
   lcd_command(0xd4 + 15);
   lcd_data("KFGSKJ");
   /*************/
   while(true)
   {   
      Dich();               
   }
}
/***************************************************************/
void Dich()
{ 
   //lcd_command(lcd_shift_left);
   lcd_command(lcd_shift_right);
   delay_ms(500);
}
