#include<tv_pickit2_shift_1.c>
#include<tv_pickit2_shift_lcd.c>
/*************************************************/
unsigned int8 i;
const int8 pos[5] = { 0x80, 0xc0, 0x94, 0xd4}; 
/*************************************************/
void hien_thi_lcd_x_y(signed int8 n, a, b );
/*****************************************************/
void main()
{                                           
     set_up_port_ic_chot();
     setup_lcd();                                       
     lcd_command(0x40);
     for(i=0; i<64; i++)  lcd_data( lcd_ma_8doan[i]);
     hien_thi_lcd_x_y(0, 0, 1);
}
/*************************************************/                 
void hien_thi_lcd_x_y(signed int8 n, a, b)
{                                          
    lcd_command(pos[a] + b);
    //lcd_goto_xy(x1, y1);
    for(i = 0; i< 6; i++)
    {
      if(i=3)       lcd_command(pos[a+1] + b);
      lcd_data(lcd_so_x[n][i]);
    }
}  
/***************************************************/
