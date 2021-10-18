#include<tv_pickit2_shift_1.c>
#include<MaTranPhim_01.c>
/********************************************//*************************************************/
signed int8 i, j, led;
unsigned int8 mv, k, ch_m, dv_m, tr_s, ch_s, dv_s, D_sp, buffer, sp, gt_dem, tt_timer;
unsigned int8 set[3]={18, 18};
unsigned int8 dem[3] ={ 0, 0};
unsigned char array[9];
unsigned int1 state;
/********************************************//*************************************************/
#define up pin_b2
#define dw pin_b3
/********************************************//*************************************************/
void Bai_401();
void Bai_402();
void Bai_403();
void Bai_403_Modif();
void Bai_405();
void Bai_409();
void Test_maTranPhim();
void BaiTapTrenLop();
void Bai_441();
void Bai_414();
void Up_button();
void Dw_button();
void Bai_424();
void XepMang();
/*************************************************//*************************************************/
/*#int_rb
void Ngat_rb()
{
   mv=key_4x4();
}*/
/*********************************************//*************************************************/
void main()
{
   set_up_port_ic_chot();
   led = 0;
   k=0;
   sp=0;
   gt_dem=0;
   tt_timer=0;
   /*enable_interrupts(global);
   enable_interrupts(int_rb);*/
   //Bai_401();
   //BaiTapTrenLop();
   //setup_timer_0(T0_EXT_H_TO_L|T0_DIV_2|T0_8_BIT);
   /*setup_timer_0(48|8|T0_8_BIT);
   set_timer0(250);
   buffer = 0;
   state = 0;        // bai 414()
   D_sp = 248;*/
   setup_timer_0(0x80);
   //set_timer0(0);
   set_tris_b(0x3c);
   //xuat_4led_7doan_4so(0x7f, 0x7f,0x7f, 0x7f);
   BaiTapTrenLop();
}
/*************************************************//*************************************************/
void Bai_401()
{
   xuat_4led_7doan_4so(0xb0, 0xa4, 0xc0, 0xc0);
}
/*************************************************//*************************************************/
void Bai_402()
{
   for(i=0; i<10; i++)
   {
      xuat_4led_7doan_4so(0,0,0,ma7doan[i]);
      delay_ms(200);
   }
}
/*************************************************//*************************************************/
void Bai_403()
{
   for(i=0; i<10; i++)
      for(j=0; j<10; j++)
         {
            xuat_4led_7doan_4so(0xff, 0xff, ma7doan[i], ma7doan[j]);
            delay_ms(100);
         }
}
/*************************************************//*************************************************/
void Bai_403_Modif()
{
   for(i=0; i<100; i++)
      {
         xuat_4led_7doan_4so(0xff, 0xff, ma7doan[i/10], ma7doan[j%10]);
         delay_ms(100);
      }
}
/*************************************************//*************************************************/
void Bai_405()
{
   for(i=0; i<60; i++)
   {
      xuat_4led_7doan_4so(0xff, 0xff, ma7doan[i/10], ma7doan[i%10]);
      delay_ms(100);
   }
   delay_ms(200);
   for(i=59; i>=0; i--)
   {
      xuat_4led_7doan_4so(0xff, 0xff, ma7doan[i/10], ma7doan[i%10]);
      delay_ms(100);
   }
}
/*************************************************//*************************************************/
void Test_maTranPhim()
{
   mv = key_4x4();
   if(mv!=0xff)
   {
   xuat_4led_7doan_4so(0xff, 0xff, 0xff, ma7doan[mv]);
   xuat_32led_don_4byte(0, 0, 0, mv);
   //xuat_32led_don_4byte(0, 0, key_4x4(), 0);
   delay_ms(100);
   }
}
/*************************************************//*************************************************/
void Bai_409()
{
   for(j=0;j<60;j++)
      for(i=0;i<60; i++)
      {
         ch_m= j/10;
         dv_m = j%10;
         ch_s = i/10;
         dv_s = i%10;
         if(ch_m==0) ch_m=16;
         if(ch_s==0) ch_s=16;
         xuat_4led_7doan_4so(ma7doan[dv_s],ma7doan[ch_s], ma7doan[dv_m], ma7doan[ch_m]);
         delay_ms(100);
      }
}
/*************************************************//*************************************************/
void BaiTapTrenLop()
{
   //trang thai dau
   xuat_4led_7doan_4so(ma7doan[set[0]],ma7doan[set[1]],ma7doan[dem[0]],ma7doan[dem[1]]);
   // nhap input
   while(true)
   {
      mv= key_4x4();
      if(mv!=0xff)
      {
         xuat_32led_don_4byte(0,0,0,mv);
         if(mv<10 && tt_timer==0)
         {
            set[1]  = set[0];
            set[0]  = mv;
            gt_dem= set[1]*10 + set[0];
            xuat_4led_7doan_4so(ma7doan[set[0]],ma7doan[set[1]],ma7doan[dem[0]],ma7doan[dem[1]]);
         }
         if(mv==10  && gt_dem!=0) 
         {
            tt_timer=1;
            setup_timer_0(48|8);
            if(k==0) set_timer0(0);
            else     set_timer0(sp);// tiep tuc dem
            k=10;
            gt_dem= set[1]*10 + set[0];
         }
         if(mv==12)
         {
            set_timer0(0x80);
            k=1;
         }
         if(mv==11)
         {
            tt_timer=0;
            k=0;
            gt_dem=0;
            sp=0;
            setup_timer_0(0x80);
            set_timer0(0);
         }
         //xuat_4led_7doan_4so(ma7doan[1], ma7doan[2], ma7doan[3], ma7doan[4]);
      }
      
      if(k==10) //state = ~ state;
         //if(state)
         {
            sp = get_timer0();
            dem[0] =sp%10;
            dem[1] = sp/10;
            xuat_4led_7doan_4so(ma7doan[set[0]],ma7doan[set[1]],ma7doan[dem[0]],ma7doan[dem[1]]);
         }
      if(sp ==gt_dem && sp!=0)
      {
         k=0;
         sp= gt_dem =0;
         set_timer0(0x80);
         xuat_4led_7doan_4so(ma7doan[set[0]],ma7doan[set[1]],ma7doan[dem[0]],ma7doan[dem[1]]);
         delay_ms(100);
         xuat_4led_7doan_4so(0xff, 0xff, 0xff, 0xff);
         delay_ms(100);
      }
   }
   
}
/*************************************************//*************************************************/
void Bai_441()
{
   D_sp = get_timer0();
   //if(dv_s ==0)   dv_s = 16;
   if(D_sp != buffer)
   {
   buffer = D_sp;
   ch_s = D_sp/10;
   dv_s = D_sp%10;
   if(ch_s == 0)  ch_s = 16;
   xuat_4led_7doan_4so(ma7doan[dv_s], ma7doan[ch_s], 0xff, 0xff);
   if(D_sp>=20)
      set_timer0(1);
   }
}
/*************************************************//*************************************************/
void Bai_414()
{
   up_button();
   dw_button();
   if(state==1)
   {
      sp = get_timer0();
      if( sp != buffer)
      {
         buffer = sp;
         D_sp++;
         if((D_sp >=255) | (D_sp < 248))     D_sp=249;//set_timer0(250);
         tr_s = D_sp/100;
         ch_s = D_sp/10%10;
         dv_s = D_sp%10;
         if(tr_s == 0)  tr_s=16;
         if(ch_s == 0)  ch_s=16;
         
         xuat_4led_7doan_4so(ma7doan[dv_s], ma7doan[ch_s], ma7doan[tr_s], 0xff);
      }
   }
   else  buffer = get_timer0();
}
/*************************************************//*************************************************/
void Up_button()
{
   if(!input(up))
   {
      delay_ms(20);
      if(!input(up))
      {
         xuat_32led_don_1dw(0xffffffff);
         state = 1;
      }
      while(!input(up));
   }
}
/*************************************************//*************************************************/
void Dw_button()
{
   if(!input(dw))
   {
      delay_ms(20);
      if(!input(dw))
      {
         state = 0;
         xuat_32led_don_1dw(0);
      }
      while(!input(dw));
   }
}
/*************************************************//*************************************************/
void Bai_424()
{
   mv = key_4x4();
   if(mv != 0xff)
   {
      if(mv<=9)
      {
         /*array[7] = array[6];
         array[6] = array[5];
         array[5] = array[4];
         array[4] = array[3];
         array[3] = array[2];
         array[2] = array[1];
         array[1] = array[0];*/
         for(i=7; i>0; i--)
         {
            array[i]=array[i-1];
         }
         array[0] = ma7doan[mv];
         xuat_4led_7doan_4so(array[0], array[1], array[2], array[3]);
      }
      if(mv==12)   
      {
         for(i=0; i<8; i++)
            array[i]=0x7f;
         xuat_4led_7doan_4so(array[0], array[1], array[2], array[3]);
      }
      if(mv==11)
      {
         for(i=0;i<7;i++)
            array[i]=array[i+1];
         array[7] = 0x7f;
         xuat_4led_7doan_4so(array[0], array[1], array[2], array[3]);
      }
   }
}
/*************************************************//*************************************************/
void XepMang()
{
   mv = key_4x4();
   if(mv != 0xff)
      if( mv <10)
      {
         array[3] = array[2];
         array[2] = array[1];
         array[1] = array[0];
         array[0] = mv;
         xuat_4led_7doan_4so(ma7doan[array[0]],ma7doan[array[1]],ma7doan[array[2]],ma7doan[array[3]]);
      }
      if(mv == 10)
      {
         xuat_32led_don_1dw(~led);
         for(;array[1]<=9; array[1]++)
         {
            for(;array[0]<=8; array[0]++)
            {
               xuat_4led_7doan_4so(ma7doan[array[0]],ma7doan[array[1]],ma7doan[array[2]],ma7doan[array[3]]);
               delay_ms(200);
            }
            array[0]=0;
         }
      }
}
