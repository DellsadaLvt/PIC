
#include<tv_pickit2_shift_1.c>
#include<tv_pickit2_shift_lcd.c>
#include<tv_pickit2_shift_ds18b20.c>


void Read_temp_ds18b20();
                                            
void main()                                                                          
{
   set_up_port_ic_chot () ;
    setup_lcd();
    khoi_tao_ds18b20();
   ds18a_tam =0; 
   while (true)       
   {
      Read_temp_ds18b20();
      lcd_hienthi_so_z_toado_xy(ds18a/10,2,0);  
      lcd_hienthi_so_z_toado_xy(ds18a%10,2,4); 
   } 
}

void Read_temp_ds18b20() 
{
       //khoi_tao_ds18b20();
       //ds18a_tam =0;                                              
       if(touch_present())        doc_giatri_ds18b20(); 
      //if(ds18al != ds18a_tam)
      
         //ds18a_tam = ds18al;
         ds18a = (ds18a >> 4);
         //ds18a = ds18a & 0xff;
         xuat_4led_7doan_giaima_xoa_so0(ds18a);
      
  
          /*lcd_command(0xd4);
          lcd_data(ds18a /10 + 0x30);
          lcd_data(ds18a %10  + 0x30);*/ 
         
         
}
    

