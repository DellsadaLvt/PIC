#include<tv_pickit2_shift_1.c>

unsigned int32 y, v, u;
signed int8 i, j;
unsigned int16 x1, x2, t;

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

void main()
{
   set_up_port_ic_chot();
   y=0;   
   t = 0;
   while(true)
   {
    //SangTuTSP();     
    //sangPsT();              
    //chayVao();    
    //chayRa();
    //ledChop();
    //SangDon_1();
    SangDon_2();
    //SangDon_3();
    //sangDon_4();                    
    //ledChop_1(); 
   }
}

void SangTuTSP()
{
   y=0;
   for( i= 0; i < 32 ; i++)
          {
            //xuat_32led_don_1dw(y);
            
            xuat_32led_don_4byte(y>>24, y>>16, y>>8, y);
            delay_ms(50);
            y = (y>>1) | 0x80000000;
          }                                                            
   for( i= 0; i < 32 ; i++)
          {
            xuat_32led_don_1dw(y);
            delay_ms(50);
            y = y>>1;
          }
}

void sangPsT()
{
   y = 0;
   for( i=0; i<32; i++)
   {
      y = (y<<1) | 1;
      xuat_32led_don_1dw(y);
      delay_ms(50);
   }
   
   for( i=0; i<32; i++)
   {
      y= y<<1;
      xuat_32led_don_1dw(y);
      delay_ms(50);
   }
}

void ledChop()
{
   for(i=0; i<20; i++)
   {
      xuat_32led_don_4byte(0x00, 0xff, 0xff, 0x00);
      delay_ms(10);
      xuat_32led_don_4byte(0x00, 0x00, 0x00, 0x00);
      delay_ms(10);
   }
   for(i=0; i<20; i++)
   {
      xuat_32led_don_4byte(0xff,0x00,0x00, 0xff);
      delay_ms(10);
      xuat_32led_don_4byte(0x00, 0x00, 0x00, 0x00);
      delay_ms(10);
   }
   for(i=0; i<20; i++)
   {
      xuat_32led_don_4byte(0x00, 0xff, 0xff, 0x00);
      delay_ms(10);
      xuat_32led_don_4byte(0x00, 0x00, 0x00, 0x00);
      delay_ms(10);
      xuat_32led_don_4byte(0xff,0x00,0x00, 0xff);
      delay_ms(10);
      xuat_32led_don_4byte(0x00, 0x00, 0x00, 0x00);
      delay_ms(10);
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
      delay_ms(50);
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
      delay_ms(50);
   }
}


void SangDon_1()
{
   y=0;
   v=0;
   for( j = 32; j >=0; j--)
   {
      for( i = 0 ; i < j; i++)
      {
         y = ((y<<1) | 1) | v;
         xuat_32led_don_1dw(y);
         delay_ms(35);
      }
      for( i = 0 ; i < j-1; i++)
      {
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
         y = ((y<<1) | 1) | v;
         xuat_32led_don_1dw(y);
         delay_ms(35);
      }
      v = ( v>>1) | 0x80000000;
      u = 0x7fffffff;                                          
      for( i = 0 ; i<32; i++)                                   
      {
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
         y = ((y<<1) | 1) | v;
         xuat_32led_don_1dw(y);
         delay_ms(40);
      }
      v = ( v>>1) | 0x80000000;
      u = 0x7fffffff;
      for( i = 0 ; i<32; i++)
      {
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
         y = ((y<<1) | 1) | v;
         xuat_32led_don_1dw(y);
         delay_ms(35);
      }
      for( i = 0 ; i < j; i++)
      {
         y = y>>1;
         xuat_32led_don_1dw(y);
         delay_ms(35);
      }
      //v = ( v>>1) | 0x80000000;
   }
}

