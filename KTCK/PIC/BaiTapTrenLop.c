#include<tv_pickit2_shift_1.c>
#include<tv_pickit2_shift_lcd.c>
#include<MaTranPhim_01.c>
/*****************************************************/
unsigned int8 array[21]; 
unsigned int8 key;
signed int8 i;
/*****************************************************/
void nhap_so();
void hien_thi();
/*****************************************************/
void main()
{
    set_up_port_ic_chot();
    set_tris_b(0x3c);
    setup_lcd();
    for(i=0; i<21;i++)  array[i]=0;
    while(true)
    {
       nhap_so();
       hien_thi();
    }
} 
/*****************************************************/   
void nhap_so()
{
   key =  key_4x4();
   if( key != 0xff)
   {
      array[4] = array[3];
      array[3] = array[2];
      array[2] = array[1];
      array[1] = array[0];
      array[0] = key;                       
   }
}
/*****************************************************/
void hien_thi()
{
   lcd_command(0xc0 + 3);
   for(i = 4 ; i>=0; i--)
   {
      lcd_data(array[i] + 0x30);
   }  
} 
/*****************************************************/
void xep_mang_tang_dan()
{
   for(i=0; i
}

