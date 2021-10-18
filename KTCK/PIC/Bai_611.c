
#include<tv_pickit2_shift_1.c>
#include<tv_pickit2_shift_lcd.c> 
#include<Matranphim_01.c>
/***************************************************************/
unsigned INT8  counter_time, s, h, min, ch, chedo, dem, key;  
unsigned int1 tt;
/***************************************************************/
#define dw        pin_b3
#define up        pin_b5 
#define mode      pin_b4 
#define st        pin_b2
/***************************************************************/
void HienThiLCD();                             
void get_time();
void Cd_mode();     
void Cd_up();  
void Cd_dw();
void GM_7doan_quet();
void HienThi_7doan_quet();
void fun_st(); 
void HienThi_7d();
/***************************************************************/  
#INT_timer1
                                                        
void Interrupts_timer1()                       
{
   set_timer1 (59286) ;
   counter_time++;              
   dem++;       
  hien_thi_8led_7doan_quet_all(); 
}                   
/*******************/
#int_rb                  
void interrupt_button()    
{
      Cd_mode();                                                
      Cd_up();
}  
/************************/
#int_timer3
void interrupt_timer3()
{
      //key = key_4x4(); 
      //dem++; 
      //hien_thi_8led_7doan_quet_all(); 
      set_timer3(3036);  
}
/***************************************************************/
void main()
{
   set_up_port_ic_chot () ;
   setup_lcd (); 
   setup_timer_1 (T1_INTERNAL|T1_DIV_BY_8) ; 
   set_timer1 (59286) ;
   /*setup_timer_3(T3_INTERNAL | T3_DIV_BY_8);
   set_timer3(3036); */
   enable_interrupts (global) ;
   enable_interrupts (INT_timer1);
   enable_interrupts(int_rb); 
   enable_interrupts(int_timer3);

   /****************************/
   counter_time = 0;
   s=0;
   min =0;
   h =0;
   chedo = 0;
   dem = 0;
   tt = 0;
   key = 0;
   /*************/
   WHILE (true)
   {  
     // key = key_4x4();
      get_time();                                    
      HienThiLCD (); 
      GM_7doan_quet();
      HienThi_7doan_quet();
      HienThi_7d(); 
   }
}

/***************************************************************/
void HienThiLCD()
{
   lcd_command (0x80 + 5);
   lcd_data (h/10 +0x30);
   lcd_data (h % 10 + 0x30);
   lcd_data (":");
   lcd_data (min/10 +0x30);
   lcd_data (min % 10 + 0x30);             
   lcd_data (":");
   lcd_data (ch);
   lcd_data (s % 10 + 0x30); 
   /***************************/
   lcd_command(0xc0+ 5);
   lcd_data("che do:");
   lcd_data(chedo + 0x30);
}

/***************************************************************/
void get_time()  
{
   IF (counter_time >= 10)
   {
      counter_time = counter_time - 10;
      s++; 
      if(s==60) 
      {   
         s=0;
         min++;
         if( min ==60)
         {
            min= 0;
            h++;
            if( h == 60)   h=0;
         }
      }
      ch = s/10 ;
      if( ch == 0)     ch =' ';
      else              ch = ch + 0x30;
   }
}  
/*******************************************************************************/
void Cd_mode()
{
   if(!input(mode))
   {
      delay_ms(20);
      if(!input(mode))
      {
           chedo++;
           if(chedo == 4) chedo = 0;
           while(!input(mode)); 
      }
   }
} 
/*******************************************************************************/ 
void Cd_up()
{                                        
   if(!input(up))
   {
      delay_ms(20);
      if(!input(up))
      {
           switch(chedo)
            {
               case 2:                 
                  h++; 
                  if(h==24) h = 0;
                  break;
            }
            
           while(!input(up)); 
      }
   }
}
/***************************************************************/
void Cd_st()
{                                        
   if(!input(st))
   {                             
      delay_ms(20);
      if(!input(st))
      {
           tt=~tt; 
           while(!input(st)); 
      }
   }
} 
/*******************************************************************************/
void fun_st()
{
   if(tt)
   {
      
   }
}
/*******************************************************************************/
void GM_7doan_quet()
{
         led_7dq[0] = ma7doan[s%10];
         led_7dq[1] = ma7doan[s/10];
         led_7dq[2] = 0xbf;
         led_7dq[3] = ma7doan[min%10]; 
         led_7dq[4] = ma7doan[min/10];
         led_7dq[5] = 0xbf;
         led_7dq[6] = ma7doan[h%10];
         led_7dq[7] = ma7doan[h/10];
}     
/*******************************************************************************/ 
void Cd_dw()
{                                        
   if(!input(dw))
   {
      delay_ms(20);
      if(!input(dw))
      {
           switch(chedo)
            {
               case 2:                 
                  h--; 
                  if(h==0) h = 0;
                  break;
            }
            
           while(!input(dw)); 
      }
   }
}               
/*******************************************************************************/
   
/**********************************************************************************/
void HienThi_7doan_quet()
{
   if(dem>=1)
   {    
      dem= dem-1;
      //hien_thi_8led_7doan_quet_all();  
   }               
}                 
/*******************************************************************************/
void HienThi_7d()
{  
  // key = key_4x4();                 
   if( key != 0xff)
      xuat_4led_7doan_4so(0, 0, ma7doan[key], ma7doan[key]);  
}  
/*******************************************************************************/

