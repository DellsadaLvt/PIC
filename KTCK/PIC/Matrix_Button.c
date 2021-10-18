#include<tv_pickit2_shift_1.c>
#include<MaTranPhim.c>
////////////////////////////////////////
unsigned int8 tt, led=0;
/*****************************/
void mode();
void main()
{
   set_up_port_ic_chot();
   set_tris_b(0x3c);
   //port_b_pullups(true);
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
         led = 0x01 | led;
         xuat_32led_don_4byte(0, 0, 0,led );
         break;
      case 8:
         led = led & 0xfe;
         xuat_32led_don_4byte(0,0,0, led);
         break;
      case 1:
         led = 0x02 | led;
         xuat_32led_don_4byte(0, 0, 0,led );
         break;
      case 9:
         led = led & 0xfd;
         xuat_32led_don_4byte(0,0,0, led);
         break;
      case 2:
         led = 0x04 | led;
         xuat_32led_don_4byte(0, 0, 0,led );
         break;
      case 10:
         led = led & 0xfb;
         xuat_32led_don_4byte(0,0,0, led);
         break;
      case 3:
         led = 0x08 | led;
         xuat_32led_don_4byte(0, 0, 0,led );
         break;
      case 11:
         led = led & 0xf7;
         xuat_32led_don_4byte(0,0,0, led);
         break;
      case 4:
         led = 0x10 | led;
         xuat_32led_don_4byte(0, 0, 0,led );
         break;
      case 12:
         led = led & 0xef;
         xuat_32led_don_4byte(0,0,0, led);
         break;
      case 5:
         led = 0x20 | led;
         xuat_32led_don_4byte(0, 0, 0,led );
         break;
      case 13:
         led = led & 0xdf;
         xuat_32led_don_4byte(0,0,0, led);
         break;
      case 6:
         led = 0x40 | led;
         xuat_32led_don_4byte(0, 0, 0,led );
         break;
      case 14:
         led = led & 0xbf;
         xuat_32led_don_4byte(0,0,0, led);
         break;
      case 7:
         led = 0x80 | led;
         xuat_32led_don_4byte(0, 0, 0,led );
         break;
      case 15:
         led = led & 0x7f;
         xuat_32led_don_4byte(0,0,0, led);
         break;
         

   }
   
}
  

