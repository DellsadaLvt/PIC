#include<tv_pickit2_shift_1.c>
#include<tv_pickit2_shift_lcd.c>  

unsigned int8 i;

const char ee[9] = {  0x04, 0x0a, 0x00,0x0e, 0x11, 0x1e, 0x10, 0x0e};
const char aw[9] = {  0x12, 0x0c, 0x00, 0x0e, 0x12, 0x12, 0x12, 0x0f}; 
const char oj[9] = {  0x0e, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x04};
const char shift_j[9] = {0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
                          
void saveInCGRam();
void HienThiTen();

void main()
{                                              
     set_up_port_ic_chot();
     setup_lcd();
     saveInCGRam();
     HienThiTen();
}

void saveInCGRam()
{
    lcd_command(0x40);
    for(i= 0; i < 8; i++)     lcd_data ( ee[i]);
    lcd_command(0x48); 
    for(i=0; i < 8; i++)      lcd_data(aw[i]);
    lcd_command(0x50);
    for(i = 0; i< 8; i++)     lcd_data(oj[i]);
    lcd_command(0x58);
    for(i = 0; i< 8; i ++)    lcd_data(shift_j[i]);
} 

void HienThiTen()
{
     lcd_command(0x80+5);
     lcd_data('L');
     lcd_data(0);
     lcd_data(' ');
     lcd_data('V');
     lcd_data(1); 
     lcd_data('n');
     lcd_data(' ');
     lcd_data("Tho");
     //lcd_data(2); 
     lcd_command(0xc0 + 14);
     lcd_data(3);
}
