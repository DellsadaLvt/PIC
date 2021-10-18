#include<tv_pickit2_shift_1.c> 

unsigned int8 i; 
unsigned int16 temp[3]; 

void  adc_channel( int8 x) ;
void adc_7doan_2channel();

void main()
{
       set_up_port_ic_chot();
       
       setup_adc(0x02);
       setup_adc_ports( 0x0c, 0x00);
       
       temp[0] = temp[1] = 0;
       
       while(true)
       {      
               adc_channel(0) ;
               adc_channel(1) ;
              adc_7doan_2channel();
       }
}

void  adc_channel( int8 x) 
{
   set_adc_channel(x); 
   
   for( i=0; i< 100; i++)
   {
       temp[x] = temp[x] + read_adc();
       delay_us(100);
   } 
   temp[x] = temp[x] / 2.046 / 100;

}

void adc_7doan_2channel()
{                                                                          
   xuat_4led_7doan_4so(ma7doan[temp[1]/10], ma7doan[temp[1]%10],  ma7doan[temp[0]/10], ma7doan[temp[0]%10]   );
}
    
