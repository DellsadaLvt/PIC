#include<tv_pickit2_shift_1.c>
#include<MaTranPhim_01.c>
////////////////////////////////////////
unsigned int8 tt, led=0;
 unsigned int1 t[8]={0,0,0,0,0,0,0,0};
/*****************************/
void mode();
void main()
{
   set_up_port_ic_chot();
   set_tris_b(0x3c);
   while(true)
   {
      mode();
   }
}


void mode()
{
   
   tt = key_4x4();
   if( tt!= 0xff)
      xuat_32led_don_4byte(tt,0,0,0);
   switch(tt)
   {
      case 0:
         t[0]=~t[0];
         if( t[0]== 1)
            led = led | 0x01;
         else
            led = led & 0xfe;
         xuat_32led_don_4byte(0, 0, 0,led );
         break;
      case 1:
         t[1]=~t[1];
         if( t[1]== 1)
            led = led | 0x02;
         else
            led = led & 0xfd;
         xuat_32led_don_4byte(0, 0, 0,led );
         break;      
      
   }
   
}
  

