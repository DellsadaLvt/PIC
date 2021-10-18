 #include<tv_pickit2_shift_1.c>     
 #include<tv_pickit2_shift_lcd.c> 
 
 
 #define start pin_b5   
 
 
 unsigned int8 tt; 
 unsigned int8 array[];  
 
  void nhap_chu(int x); 
  void phim_start() ;
                          
 void main()
 {
       set_up_port_ic_chot () ;
       
       // 0x80, 0xC0, 0x94, 0xD4
      setup_lcd();   
      
      //
      tt = 0;  
      array[0] = 0;
      
      
      while(true)
      {     
         /*if ( tt >= 7)
            nhap_chu(0x87); 
            phim_start() ;
            if(tt < 7)
            {
            
            lcd_command(0x87);
            lcd_data( tt + 0x30);     
            } */
            
            lcd_command(0x80);
            lcd_data("-1");
                            
      }
 }                
 
 
 void nhap_chu(int x)
 {      
       array[0] = tt;
       lcd_command(x);
       lcd_data(array[0] + 0x30);    
       delay_ms(500); 
       array[0] = ' ';
       lcd_command(x);
       lcd_data(array[0] );    
       delay_ms(500);
        
 }     
 
 void phim_start() 
{                          
   if(!input(start))
   {
      delay_ms(20);
      if(!input(start))
      {
         // statements
          tt++;
         while(!input(start));
      }
   }
}
