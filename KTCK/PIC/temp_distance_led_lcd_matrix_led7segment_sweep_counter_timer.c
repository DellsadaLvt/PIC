
#include<tv_pickit2_shift_1.c> 
#include<tv_pickit2_shift_lcd.c>  
#include<MaTranPhim_01.c>
#include<math.h>
#define trigger pin_e2
#define echo    pin_e1 

unsigned int8 i, count_time, ma_phim, ma[4], temp_set; 
unsigned int16 dem, temp[3], adc_sharp; 
float time, distance_sharp; // time = distance  
                             
void  adc_channel( int8 x) ;
void adc_7doan_LcdLargeFont_2channel();
void control_led(); 
void demsp();
void trigger_pulse();
void measure_distance_sonic();
void adc_distance_sharp();
                         
#int_timer3

void interrupts_timer3()
{
   
   set_timer3 (3036) ;
   count_time++;
   
   if (count_time >= 100)
   {
      count_time = count_time - 100;
      ma_phim = key_4x4 ();

      if (ma_phim != 0xff)
      {
         ma[0] = ma[1];
         ma[1] = ma_phim;
         temp_set = ma[0] * 10 + ma[1];
      } adc_7doan_LcdLargeFont_2channel () ;
   }
}

void main()
{
   
   set_up_port_ic_chot () ;
   setup_lcd ();
   
   setup_timer_0 (0x32|8);
   set_timer0 (0) ;
   
   setup_timer_1 (t1_disabled);
   
   setup_timer_3 (0x85|0x30);
   set_timer3 (3036) ;
   
   enable_interrupts (global) ;
   enable_interrupts (int_timer3) ;
   
   setup_adc (0x02) ;
   setup_adc_ports (0x0c|0x00);
   
   
   dem = 0;
   temp[0] = temp[1] = 0;
   count_time = 0;
   ma[0] = ma[1] = 0;
   temp_set = 0;
   
   
   
   while (true)
   {
      demsp ();
      led_7dq[0] = ma7doan[ (unsigned int16) time / 10];
      led_7dq[1] = ma7doan[ (unsigned int16) time % 10];
      adc_channel (0);
      adc_channel (1);
      measure_distance_sonic () ;
      adc_distance_sharp () ;
      adc_7doan_LcdLargeFont_2channel () ;
      control_led () ;
      HIEN_THI_8LED_7DOAN_QUET_ALL () ;
   }
}

void  adc_channel( int8 x) 
{
   set_adc_channel (x);
   
   for (i = 0; i< 100; i++)
   {
      temp[x] = temp[x] + read_adc ();
      delay_us (100) ;
   }

   temp[x] = temp[x] / 2.046 / 100;
}

void adc_7doan_LcdLargeFont_2channel()
{
   
   //xuat_4led_7doan_4so (ma7doan[temp[1] / 10], ma7doan[temp[1] % 10], ma7doan[temp[0] / 10], ma7doan[temp[0] % 10]  );
   xuat_4led_7doan_4so (ma7doan[dem / 10], ma7doan[dem % 10], ma7doan[temp_set / 10], ma7doan[temp_set % 10]  );

   // lcd
   lcd_command (0x80) ;
   lcd_data ("hang 1:") ;
   lcd_command (0xc0) ;
   lcd_data ("Sonic:") ;
   lcd_data ( (unsigned int16) time / 10 + 0x30);
   lcd_data ( (unsigned int16) time % 10 + 0x30);
   lcd_command (0x94) ;
   lcd_data ("Sharp:") ;
   lcd_data ( (unsigned int16) distance_sharp / 10 + 0x30);
   lcd_data ( (unsigned int16) distance_sharp % 10 + 0x30);
   lcd_command (0xd4);
   lcd_data ("hang 2:");
   lcd_hienthi_so_z_toado_xy (temp[1] / 10, 0,10);
   lcd_hienthi_so_z_toado_xy (temp[1] % 10, 0,13);
   lcd_hienthi_so_z_toado_xy (temp[0] / 10, 2,10);
   lcd_hienthi_so_z_toado_xy (temp[0] % 10, 2,13);
}

void control_led()
{
   if (temp[0] < temp_set&&temp[1] < temp_set) triac_2_on ();
   if (temp[0] >= temp_set||temp[1] >= temp_set) triac_2_off ();
}

void demsp()
{
   
   dem = get_timer0 ();
   if (dem >= 99) set_timer0 (0);
}

void trigger_pulse() 
{
   delay_ms (10) ;
   output_high (trigger) ;
   delay_ms (10) ;
   output_low (trigger);
   
   set_timer1 (0) ;
   while ( ! input (echo)) ;
   setup_timer_1 (0x85|0x20);
   
   while (input (echo));
   time = get_timer1 ();
   setup_timer_1 (t1_disabled) ;
}

void measure_distance_sonic()
{
   trigger_pulse ();
   time = time * 0.8 / 58;
   //xuat_4led_7doan_4so (0xff, 0xff, ma7doan[ (unsigned int16) time / 10], ma7doan[ (unsigned int16) time % 10]);
   delay_ms (500) ;
}

void adc_distance_sharp()
{
   set_adc_channel (2) ;
   adc_sharp = read_adc ();
   delay_ms (40) ;
   distance_sharp = pow (4277 / adc_sharp, 1.106);
   if (distance_sharp > 80)  distance_sharp = 80;
}

