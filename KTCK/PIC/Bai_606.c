#include<tv_pickit2_shift_1.c>
#include<tv_pickit2_shift_lcd.c> 
/***************************************************************/
unsigned int8 i;
/***************************************************************/
void Dich();  
/***************************************************************/
void main()
{
   set_up_port_ic_chot();
   setup_lcd();                            
   lcd_command(0x80);
   lcd_data("QSD;JG");                                         
   lcd_command(0xd4);
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
   for( i = 0; i < 39; i++)
   {
   lcd_command(lcd_shift_right);
   delay_ms(75);   
   }  
   for( i = 0; i < 39; i++)
   {
   lcd_command(lcd_shift_left);
   delay_ms(75);   
   }           
   
}                
