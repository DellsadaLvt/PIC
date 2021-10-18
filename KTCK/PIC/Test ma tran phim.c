#include<tv_pickit2_shift_1.c>
#include<MaTranPhim_01.c>
unsigned int8  mp, j;

/*#int_rb   dung timer de kich hoat vong quyet
void ngat()
{
   mp = key_4x4();
   
}*/
void main()
{
   set_up_port_ic_chot();
   set_tris_b(0x3c);

   xuat_32led_don_4byte(0,0,0,0xf0);
   /*if (input(mp) == true)*/
   /*enable_interrupts(global);
   enable_interrupts(int_rb);*/
   while(true)
   {
      mp = key_4x4();
      if(mp != 0xff)     xuat_32led_don_4byte(0,0,0, mp);
   }
}

