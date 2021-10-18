#include<tv_pickit2_shift_1.c>
////////////////////////////////////////
unsigned int32 y, v, u;
signed int8 i, j, TT;
unsigned int16 x1, x2;
//////////////////////////////////////
#define UP pin_b4 // bt3
#define DW pin_b5
////////////////////////////////////////
void SangTuTSP();
void sangPsT();
void ledChop();
void chayVao();
void chayRa();
void ledChop_1();
void SangDon_1();
void SangDon_2();
void SangDon_3();
void sangDon_4();
void upButton();
void dwButton();
void mode();
///////////////////////////////////
#int_timer3
void ngatTimer3()
{
   set_timer3(-62500);
   dwButton();
   upButton();
   
}
//////////////////////////////////
void main()
{
   set_up_port_ic_chot();
   y=0;
   TT= 0;
   setup_timer_3(T3_INTERNAL | T3_DIV_BY_8);
   set_timer3(3036);
   enable_interrupts(global);
   enable_interrupts(int_timer3);
   while(true)
   {
      mode();
   }
}

void SangTuTSP()
{
   y=0;
   for( i= 0; i < 32 ; i++)
          {
            xuat_32led_don_1dw(y);
            delay_ms(50);
            y = (y>>1) | 0x80000000;
            if( TT != 1) break;
          }
   for( i= 0; i < 32 ; i++)
          {
            xuat_32led_don_1dw(y);
            delay_ms(50);
            y = y>>1;
            if( TT != 1) break;
          }
}

void sangPsT()
{
   y = 0;
   for( i=0; i<32; i++)
   {
      y = (y<<1) | 1;
      xuat_32led_don_1dw(y);
      if( TT != 2) break;
      delay_ms(50);
   }
   
   for( i=0; i<32; i++)
   {
      y= y<<1;
      xuat_32led_don_1dw(y);
      if( TT != 2) break;
      delay_ms(50);
   }
}

void ledChop()
{
   for(i=0; i<20; i++)
   {
      xuat_32led_don_4byte(0x00, 0xff, 0xff, 0x00);
      delay_ms(20);
      xuat_32led_don_4byte(0x00, 0x00, 0x00, 0x00);
      delay_ms(20);
   }
   for(i=0; i<20; i++)
   {
      xuat_32led_don_4byte(0xff,0x00,0x00, 0xff);
      delay_ms(20);
      xuat_32led_don_4byte(0x00, 0x00, 0x00, 0x00);
      delay_ms(20);
   }
   for(i=0; i<20; i++)
   {
      xuat_32led_don_4byte(0x00, 0xff, 0xff, 0x00);
      delay_ms(20);
      xuat_32led_don_4byte(0x00, 0x00, 0x00, 0x00);
      delay_ms(20);
      xuat_32led_don_4byte(0xff,0x00,0x00, 0xff);
      delay_ms(20);
      xuat_32led_don_4byte(0x00, 0x00, 0x00, 0x00);
      delay_ms(20);
   }
}
void ledChop_1()
{
   for(i=0; i<20; i++)
   {
      xuat_32led_don_4byte(0x00, 0xff, 0xff, 0x00);
      delay_ms(15);
      xuat_32led_don_4byte(0x00, 0x00, 0x00, 0x00);
      delay_ms(15);
      xuat_32led_don_4byte(0xff,0x00,0x00, 0xff);
      delay_ms(15);
      xuat_32led_don_4byte(0x00, 0x00, 0x00, 0x00);
      delay_ms(15);
   }
}
void chayVao()
{
   x1 = 0;
   x2 = 0;
   for( i=0; i<16; i++)
   {
      x1= (x1>>1) | 0x8000;
      x2= (x2<<1) | 1;
      xuat_32led_don_2word(x1, x2);
      if( TT != 4) break;
      delay_ms(60);
   }
}

void chayRa()
{
    x1 = 0;
   x2 = 0;
   for( i=0; i<16; i++)
   {
      x2= (x2>>1) | 0x8000;
      x1= (x1<<1) | 1;
      xuat_32led_don_2word(x1, x2);
      if( TT != 4) break;
      delay_ms(60);
   }
}


void SangDon_1()
{
   y=0;
   v=0;
   for( j = 32; j >=0; j--)
   {
      //if( TT != 6) break;
      for( i = 0 ; i < j; i++)
      {
         if( TT != 6) break;
         y = ((y<<1) | 1) | v;
         xuat_32led_don_1dw(y);
         delay_ms(35);
         
      }
      for( i = 0 ; i < j-1; i++)
      {
         if( TT != 6) break;
         y = (y<<1) ;
         xuat_32led_don_1dw(y);
         delay_ms(35);
      }
      v = ( v>>1) | 0x80000000;
   }
}

void SangDon_2()
{
   y=0;
   v=0;
   for( j = 32; j >=0; j--)
   {
      for( i = 0 ; i < j; i++)
      {
         if( TT != 7) break;
         y = ((y<<1) | 1) | v;
         xuat_32led_don_1dw(y);
         delay_ms(35);
      }
      v = ( v>>1) | 0x80000000;
      u = 0x7fffffff;
      for( i = 0 ; i<32; i++)
      {
         if( TT != 7) break;
         u = u >> 1;
         y = y & (v | u);
       
         xuat_32led_don_1dw(y);
         delay_ms(25);
      }
   }
}

void SangDon_3()
{
   y=0;
   v=0;
   for( j = 0; j <32; j++)
   {
      for( i = 0 ; i < j; i++)
      {
         if( TT != 8) break;
         y = ((y<<1) | 1) | v;
         xuat_32led_don_1dw(y);
         delay_ms(40);
      }
      v = ( v>>1) | 0x80000000;
      u = 0x7fffffff;
      for( i = 0 ; i<32; i++)
      {
         if( TT != 8) break;
         u = u >> 1;
         y = y & (v | u);
       
         xuat_32led_don_1dw(y);
         delay_ms(25);
      }
   }
}
void sangDon_4()
{
   y=0;
   v=0;
   for( j = 0; j < 32; j++)
   {
      for( i = 0 ; i < j; i++)
      {
         if( TT != 9) break;
         y = ((y<<1) | 1) | v;
         xuat_32led_don_1dw(y);
         delay_ms(35);
      }
      for( i = 0 ; i < j; i++)
      {
         if( TT != 9) break;
         y = y>>1;
         xuat_32led_don_1dw(y);
         delay_ms(35);
      }
      //v = ( v>>1) | 0x80000000;
   }
}

void upButton()
{
   if( !input(UP))
   {
      delay_ms(20);
      if(!input(UP))
      {
         TT++;
         if( TT> 10) TT=0;
         while(!input(UP));
      }
   }
}

void dwButton()
{
   if( !input(DW))
   {
      delay_ms(20);
      if(!input(DW))
      {
         TT--;
         if( TT < 0) TT=10;
         while(!input(DW));
      }
   }
}
void mode()
{
   switch(TT)
   {
      case 0:
         xuat_32led_don_1dw(0);
         break;
      case 1: 
         SangTuTSP();
         break;
      case 2:
         sangPsT();
         break;
      case 3:
         ledChop();
         break;
      case 4:
         chayVao();
         chayRa();
         break;
      case 5:
         ledChop_1();
         break;
      case 6:
         SangDon_1();
         break;
      case 7:
         SangDon_2();
         break;
      case 8:
         SangDon_3();
         break;
      case 9:
         SangDon_4();
         break;
      case 10:
         ledChop_1();
         break;
         
   }
}

