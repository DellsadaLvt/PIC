 #include<tv_pickit2_shift_1.c> 
 #include<MaTranPhim_01.c>           
 #include<tv_pickit2_shift_lcd.c>
 #include<tv_pickit2_shift_ds18b20.c> 
 
 
 unsigned int8 i, x, y, maphimm, sp, state, time_9, max_sp; 
 unsigned int8 maled[3];    
 unsigned int16 temp, le;
 
 void hien_lcd();    
 void read_ds18a();
 
unsigned int8 time;




 void main()
 {
         // khoi tao ic 
         set_up_port_ic_chot () ;   
         
         //lcd
         setup_lcd();            
           setuplcd_solon();
           
           // setup ds18b20a
  KHOI_TAO_DS18B20(); // moi them 
       // khoi tao timer3
   //setup_timer_3( T3_INTERNAL | T3_DIV_BY_8 );
   //set_timer3(59286); // chu ki 100ms
   // get_timer3(); lay gia tri timer 3

   // interrupts timer3
  // enable_interrupts(global);
   //enable_interrupts(int_timer3);
                                        
         
   //khoi tao counter0
  // setup_timer_0(T0_EXT_L_TO_H | T0_DIV_1); // T0_OFF 
  
     setup_timer_0( T0_OFF);
        set_timer0( 0);  
   
                    
   // set ban dau  
     x =0;
     y = 0; 
     time_9 = 0;  
     max_sp = 0;
      
     maled[0] =  18;
     maled[1] =  18;
          
     state = 0;
     led_7dq[0] =  ma7doan[maled[0]];
     led_7dq[1] =ma7doan[maled[1]]; 
     led_7dq[2] =  0xff;  
     led_7dq[3] = ma7doan[  y];
     led_7dq[4] = ma7doan[ x]; 
     led_7dq[5] =  0x8e;
     led_7dq[6] =  0x8e;
     led_7dq[7] =  0xc0; 
                                    
     
   
     
     while(true)   
     {         
     
              for( i =0 ; i< 100; i++)
               HIEN_THI_8LED_7DOAN_QUET_ALL();  
               
               // nhan phim               
               maphimm = key_4x4();
               if( maphimm != 0xff) 
               {
                     if( maphimm == 10)
                     {    
                     state = 1;
                           setup_timer_0(T0_EXT_L_TO_H | T0_DIV_1); // T0_OFF 
                              set_timer0( 0);   
                           //XUAT_32LED_DON_1DW(0xff); 
                           // on
                           led_7dq[6] =  0xab;
                           led_7dq[5] =  0xbf; 
                           for( i =0 ; i< 200; i++)
               HIEN_THI_8LED_7DOAN_QUET_ALL(); 
                            
   
                     }  
                     if( maphimm == 11)
                     {    
                     state = 0;
                        setup_timer_0( T0_OFF); 
                        led_7dq[5] =  0x8e;
                          led_7dq[6] =  0x8e; 
                          for( i =0 ; i< 200; i++)
               HIEN_THI_8LED_7DOAN_QUET_ALL(); 
                     } 
                     
                     // dich led
                     if(maphimm <= 9)
                     {    
                     for( i =0 ; i< 200; i++)
               HIEN_THI_8LED_7DOAN_QUET_ALL(); 
                        
                        maled[1] = maled[0];
                        maled[0] = maphimm;  
                        led_7dq[0] =  ma7doan[maled[0]];
                         led_7dq[1] =ma7doan[maled[1]];
                          time_9++;  
                         if(time_9 >= 2)
                         {
                                 max_sp =   maled[1]*10 + maled[0];
                                 /*lcd_command(0x80);
                                 lcd_data(max_sp/10 + 0x30);
                                 lcd_data(max_sp%10 + 0x30); */                                                            
                         }                                   
                     }                
               }                                 
               if(state ==1)
               {
                sp = get_timer0(); 
                if( sp > max_sp)       sp = max_sp;
                x = sp/10;
                y = sp  %10;   
                led_7dq[3] = ma7doan[  y];
                led_7dq[4] = ma7doan[ x]; 
                
                for( i =0 ; i< 100; i++)
               HIEN_THI_8LED_7DOAN_QUET_ALL();
               } 
                //
                for( i =0 ; i< 100; i++)
               HIEN_THI_8LED_7DOAN_QUET_ALL();
               // LCD
               hien_lcd();  
                 //
                 for( i =0 ; i< 100; i++)
               HIEN_THI_8LED_7DOAN_QUET_ALL();
               // temp
                read_ds18a();
   
     }                                        

 }                   
 
 
 void hien_lcd()
 {                         
      lcd_command(0x80 + 2);
      lcd_data("DO NHIET DO DS1820");   
      
      for( i =0 ; i< 200; i++)
               HIEN_THI_8LED_7DOAN_QUET_ALL(); 
      
      //xuat_4led_7doan_giaima_xoa_so0 ((unsigned int16)ds18a);
      lcd_hienthi_so_z_toado_xy((unsigned int16)ds18a/10, 2,2);       
       lcd_hienthi_so_z_toado_xy((unsigned int16)ds18a%10, 2,5);
       
       //
       
          lcd_data (lcd_so_x[0][4]);                               // hien thi dau cham
         lcd_hienthi_so_z_toado_xy (le / 100, 2, 9);
        lcd_hienthi_so_z_toado_xy (le / 10 % 10, 2,12);
         lcd_hienthi_so_z_toado_xy (le % 10, 2, 15) ;
              for( i =0 ; i< 200; i++)
               HIEN_THI_8LED_7DOAN_QUET_ALL();   
               lcd_command(  0xd4 + 18); 
               lcd_data(0xdf); 
              // lcd_command(  0xd4 + 19); 
               lcd_data('C'); 
               //                              
 }
 void read_ds18a()                           
{
     if(touch_present())        doc_giatri_ds18b20(); 

     ds18a = (ds18a >> 4);   
     le = bit_test (ds18a, 3) * 500 + bit_test(ds18a, 2) * 250 + bit_test (ds18a, 1) * 125;
     
     for( i =0 ; i< 200; i++)
               HIEN_THI_8LED_7DOAN_QUET_ALL();
}                                               
