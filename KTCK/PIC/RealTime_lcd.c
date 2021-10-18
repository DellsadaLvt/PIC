#include<tv_pickit2_shift_1.c>
#include<TV_PICKIT2_SHIFT_DS13B07_I2C.C>  

void read_realtime_bai801();
void hien_thi_thoi_gian();
            
Void main()
{                            
      set_up_port_ic_chot () ; 
      setup_lcd();   
      
      lcd_command(0x80);
      lcd_data("clock");
      
      doc_thoi_gian_tu_realtime();
      
      if( ma_ds13 !=  ma_ds) 
      {
          thiet_lap_thoi_gian_hien_tai();
          NAP_THOI_GIAN_HTAI_VAO_DS13B07() ;
      }    
      doc_thoi_gian_tu_realtime();
       giaytam = giay_ds13;   
                           
       
       while(true)
       {
              read_realtime_bai801();
              hien_thi_thoi_gian();
       }
}                              

void read_realtime_bai801()
{
            doc_thoi_gian_tu_realtime();
            if(giaytam != giay_ds13)
            {
               giaytam = giay_ds13;
               //HIEN_THI_THOI_GIAN_DS13B07 ( );
            }                                       
            delay_ms(500);       
}

void hien_thi_thoi_gian()
{
   lcd_command(0x80 + 5);
   LCD_DATA(GIO_DS13/16  +0X30);    LCD_DATA(GIO_DS13%16  +0X30);
   LCD_DATA(' ');
   lcd_command(0xc0);
   hien_thi_thoi_gian_ds13b07();
}
