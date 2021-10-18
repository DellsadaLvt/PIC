
#include<tv_pickit2_shift_1.c>
#include<tv_pickit2_shift_lcd.c>

unsigned int8 j, solan, dem_s;
unsigned int16 lm35a;  

void Bai_701_hienthi_nhietdo() ;
void bai_702_sosanh_nhietdo_buzzer();

                         
#int_timer1          

void interrupt_timer1()
{                          
   
   set_timer1 (3036) ;
   dem_s++;

   // read thermal
   if (dem_s >= 10)
   {   
        
      dem_s = dem_s - 10;  
      lm35a = 0;
      for (j = 0; j < solan; j++)
      {
         lm35a = lm35a + read_adc ();
         delay_ms (1);
      }
      lm35a = lm35a / 2.046 / solan; 
      lcd_hienthi_so_z_toado_xy(lm35a/10, 0, 6);  
      lcd_hienthi_so_z_toado_xy(lm35a%10, 0, 9); 
   }
}

      
void main()                                                                          
{
   set_up_port_ic_chot () ;
    setup_lcd();
   /***/
   setup_timer_1 (0x85|0x30) ;
   set_timer1 (3036);

   /****/
   enable_interrupts (global);
   enable_interrupts (int_timer1) ;

   /////
   setup_adc (0x05) ;   // chon tan so lay mau fosc/div
   setup_adc_ports (AN0|VSS_VDD);
   set_adc_channel (0) ;
   
                             
   solan = 50;
   //lm35a = 0;
   dem_s = 0;
                                                           
   while (true)
   {
      bai_701_hienthi_nhietdo () ;
      bai_702_sosanh_nhietdo_buzzer(); 
    
       
   }
}

void Bai_701_hienthi_nhietdo() 
{
   xuat_4led_7doan_4so(ma7doan[lm35a/10], ma7doan[lm35a%10], 0x9c, 0xc6) ;
}

void bai_702_sosanh_nhietdo_buzzer()
{ 
      if( lm35a >=36)  
      {
         xuat_32led_don_1dw(0xff);
         //triac_2_off();
      }
      if( lm35a <=34)                                                  
      { 
         xuat_32led_don_1dw(0x03);
         //triac_2_on();
      }                                                                               
      
}

