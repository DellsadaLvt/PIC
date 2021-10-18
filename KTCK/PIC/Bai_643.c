#include<tv_pickit2_shift_1.c>
#include<tv_pickit2_shift_lcd.c>
/*************************************************/
unsigned int8 i, dem;
const int8 pos[5] = { 0x80, 0xc0, 0x94, 0xd4}; 
/*************************************************/
void hien_thi_lcd_x_y(signed int8 n, a, b );                     
void tachso_hienthi(signed int n);
/*****************************************************/
/*****************************************************/
void main()
{                                           
     set_up_port_ic_chot();
     setup_timer_0(48 | 8);
     set_timer0(0);
     setup_lcd();                                         
     lcd_command(0x40);
     for(i=0; i<64; i++)  lcd_data( lcd_ma_8doan[i]);
     dem=0;
     while(true)
     {  
        dem = get_timer0();
        tachso_hienthi(dem);
     }
}
/*************************************************/                 
void hien_thi_lcd_x_y(signed int8 n, a, b)
{                                          
    lcd_command(pos[a] + b);        
    for(i = 0; i< 6; i++)
    {
      if(i==3)       lcd_command(pos[a+1] + b);
      lcd_data(lcd_so_x[n][i]);
    }
}  
/***************************************************/ 
void tachso_hienthi(signed int n)
{
    if(n==99)      n = 0;
    hien_thi_lcd_x_y(n/10, 1,1);
    hien_thi_lcd_x_y(n%10, 1,5);
}
/***************************************************/

