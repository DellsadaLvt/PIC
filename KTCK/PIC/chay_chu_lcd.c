#include<tv_pickit2_shift_1.c> 
#include<tv_pickit2_shift_lcd.c>
#include<string.h>

 //unsigned int8 line2[] = {"vi xu li"};
 //unsigned int8 tam[21] = {"           "};  
 unsigned int8 n, k, j;     
 const unsigned int8 ten[52] = {"                    Le Van Tho                    "};
 
 void chay_chu();  
 void chay_chu_1() ;       
                      
void main()
{
       // khoi tao ic 
      set_up_port_ic_chot () ;  
      
      //lcd  
      setup_lcd();       
      
      
      while(true)                          
      {   
            
      }                
}  

/*void chay_chu()
{
        for( n = 0 ; n < (20 + strlen(line2)); n++)
        {
            // lay du lieu hien thi chua vao tam
            for( k = 0 ; k < 20 ; k ++)
            {
               tam[k] = tam [k+ 1];
            }
            if ( n < (strlen(line2))) tam[19] = line2[n];
            else tam[19] = ' ';
            
            // hien thi ra hang 2 lcd
            lcd_data(0xc0);
            for ( j = 0 ; j < 20; j++)
            {
               lcd_data(tam[j]);
            }  
            delay_ms(200);
        }
}*/
     
     
void chay_chu_1() 
{
     for(n = 0; n< 30; n++)
     {
            lcd_command(0x80);
             for( j = n; j < 20+ n; j++)
             {
               lcd_data(ten[j]);
             }
             delay_ms(100);
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