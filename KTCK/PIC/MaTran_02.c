#include<tv_pickit2_shift_1.c>
#include<MaTranPhim_01.c>
////////////////////////////////////////
unsigned int8 tt, led=0,mp;
unsigned int32 led, temp;
 unsigned int1 t[8]={0,0,0,0,0,0,0,0};
/*****************************/
void mode();
void mode_modify();
void main()
{
   set_up_port_ic_chot();
   set_tris_b(0x3c);
   //port_b_pullups(true);
   while(true)
   {
      mode_modify();
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
      case 2:
         t[2]=~t[2];
         if( t[2]== 1)
            led = led | 0x04;
         else
            led = led & 0xfb;
         xuat_32led_don_4byte(0, 0, 0,led );
         break; 
       case 3:
         t[3]=~t[3];
         if( t[3]== 1)
            led = led | 0x08;
         else
            led = led & 0xf7;
         xuat_32led_don_4byte(0, 0, 0,led );
         break; 
       case 4:
         t[4]=~t[4];
         if( t[4]== 1)
            led = led | 0x10;
         else
            led = led & 0xef;
         xuat_32led_don_4byte(0, 0, 0,led );
         break;
       case 5:
         t[5]=~t[5];
         if( t[5]== 1)
            led = led | 0x20;
         else
            led = led & 0xdf;
         xuat_32led_don_4byte(0, 0, 0,led );
         break;
       case 6:
         t[6]=~t[6];
         if( t[6]== 1)
            led = led | 0x40;
         else
            led = led & 0xbf;
         xuat_32led_don_4byte(0, 0, 0,led );
         break;
        case 7:
         t[7]=~t[7];
         if( t[7]== 1)
            led = led | 0x80;
         else
            led = led & 0x7f;
         xuat_32led_don_4byte(0, 0, 0,led );
         break;
   }
   
}

void mode_modify()
{
   led=0;
   temp = 1;
   mp = key_4x4();
   if(mp!=0xff)
   {
      temp = temp<<mp;
      led = led^temp;
   }
   xuat_32led_don_1dw(led);
}
  

