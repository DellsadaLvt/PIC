
#include<tv_pickit2_shift_1.c>

/******************************************************************/
unsigned INT8 i, tg, giay, phut , gio, dem_ngat, chedo, cd_mode;
unsigned INT16 sp;

/******************************************************************/
#define up     pin_b4
#define dw     pin_b3
#define mode   pin_b5                                        

/******************************************************************/
void Bai_501();
void Bai_502();
void bai_511();
void delay_time();
void giaiMa8LedQuyet(INT m);
void Bai_512();
void bai_514();
void chongDoi_up();
void chongDoi_dw();
void chongDoi_mode();

/******************************************************************/
#INT_timer1

void Ngat_timer1()
{
   set_timer1 (60536) ;
   //dem_ngat++;
   hien_thi_8led_7doan_quet_all () ;

   /* IF (dem_ngat == 10)
   {
      //hien_thi_8led_7doan_quet_all () ;
      dem_ngat = 0;
      giay++;
   }*/
}

/******************************/
#INT_timer0

void ngat_timer0()
{
   dem_ngat++;
   set_timer0 (3036) ;
}

/*********************************/
#INT_rb

void ngat_nut()
{
   chongDoi_up () ;
   chongDoi_dw () ;
   chongDoi_mode () ;
}

/******************************************************************/
void main()
{
   set_up_port_ic_chot () ;
   dem_ngat = 0;
   giay = phut = gio = 0;
   cd_mode = 0;
   //Bai_511 () ;
   //Bai_502 (); //
   // set up timer
   setup_timer_0 (0|2) ;
   set_timer0 (3036) ;
   setup_timer_1 (0x85|0x30); // internal
   set_timer1 (60536);  // gt dau
   //set up interrupts
   enable_interrupts (global) ;
   enable_interrupts (INT_timer1) ;
   enable_interrupts (INT_timer0) ;
   enable_interrupts (INT_rb) ;

   //interrupts timer 0 dem giay
   //enable_interrupts (global) ;
   //enable_interrupts (INT_timer0) ;
   
   WHILE (true)
   {
      bai_514 () ;
      //bai_512 () ;
   }
}

/******************************************************************/
void Bai_501()
{
   FOR (i = 0; i < 8; i++)
      led_7dq[i] = ma7doan[8];

   WHILE (true)
   {
      hien_thi_8led_7doan_quet_all () ;
      //delay_ms (1000) ;
      //BREAK;
   }
}

/******************************************************************/
void bai_502()
{
   led_7dq[1] = ma7doan[1];
   led_7dq[0] = ma7doan[0];

   WHILE (true)
   {
      hien_thi_8led_7doan_quet_all () ;
   }
}

/******************************************************************/
void delay_time()
{
   FOR (i = 0; i<50; i++)
   {
      /* xuat_8led_7doan_quet_2 (1, ma7doan[giay % 10]);
      delay_us (200) ;
      xuat_8led_7doan_quet_tat_led () ;
      xuat_8led_7doan_quet_2 (2, ma7doan[giay / 10]);
      delay_us (200);
      xuat_8led_7doan_quet_tat_led (); */
      hien_thi_8led_7doan_quet_all () ;
   }
}

/******************************************************************/
void bai_511()
{
   //tg = 0;

   //WHILE (tg < 100)
   
   // FOR (tg = 0; tg < 60; tg++)
   /*
   {
      delay_tg () ;
      //tg++;
      //delay_ms (50) ;
   }*/

   FOR (giay = 0; giay < 60; giay++)
   {
      giaiMa8LedQuyet (giay) ;
      // hien_thi_8led_7doan_quet_all () ;
      //delay_ms (200) ;
      delay_time () ;
      /* FOR (i = 0; i < 200;  i++)
      {
         xuat_8led_7doan_quet_2 (1, ma7doan[giay % 10]);
         delay_us (200) ;
         xuat_8led_7doan_quet_tat_led () ;
         xuat_8led_7doan_quet_2 (2, ma7doan[giay / 10]);
         delay_us (200);
         xuat_8led_7doan_quet_tat_led () ;
      }*/
   }
}

/******************************************************************/
void giaiMa8LedQuyet(INT m)
{
   led_7dq[2] = ma7doan[m / 10];
   led_7dq[1] = ma7doan[m % 10];
}

/******************************************************************/
void Bai_512()
{
   //giay = get_timer0 ();
   giay++;
   IF (giay == 60) giay = 0;
   delay_ms (200) ;
   giaiMa8LedQuyet (giay) ;
   //giaiMa8LedQuyet ();
   //delay_ms (200) ;
}

/******************************************************************/
void bai_514()
{
   //led_7dq[0] = ma7doan[8];
   led_7dq[0] = ma7doan[giay % 10];
   led_7dq[1] = ma7doan[giay / 10];
   led_7dq[2] = 0xbf;
   led_7dq[3] = ma7doan[phut % 10];
   led_7dq[4] = ma7doan[phut / 10];
   led_7dq[5] = 0xbf;
   led_7dq[6] = ma7doan[gio % 10];
   led_7dq[7] = ma7doan[gio / 10];
   
   IF (dem_ngat >= 1)
   {
      dem_ngat = 0;
      giay++;

      IF (giay == 60)
      {
         phut++;
         giay = 0;
      }

      IF (phut == 60)
      {
         gio++;
         phut = 0;
      }

      IF (gio == 24) gio = 0;
   }

   //ELSE hien_thi_8led_7doan_quet_all () ;
}

/******************************************************************/
/*VOID bai_515()
{
   chedo = 0;
   cd_mode = 0;
   
   /************************/
   /* SWITCH (cd_mode)
   {
      CASE 1:
   }
}*/

/*******************/
void chongDoi_up()
{
   IF ( ! input (up) )
   {
      delay_ms (20) ;

      IF ( ! input (up) )
      {
         IF (cd_mode == 1)  giay++;
         IF (cd_mode == 2)  phut++;
         IF (cd_mode == 3)  gio++;
         WHILE ( ! input (up)) ;
      }
   }
}

/*******************/
void chongDoi_dw()
{
   IF ( ! input (dw) )
   {
      delay_ms (20) ;

      IF ( ! input (dw) )
      {
         IF (cd_mode == 1)  giay--;
         IF (cd_mode == 2)  phut--;
         IF (cd_mode == 3)  gio--;
         WHILE ( ! input (dw)) ;
      }
   }
}

/*******************/
void chongDoi_mode()
{
   IF ( ! input (mode) )
   {
      delay_ms (20) ;

      IF ( ! input (mode) )
      {
         cd_mode++;
         xuat_4led_7doan_4so (0, 0, 0, ma7doan[cd_mode]);
         //delay_ms (2000) ;
         WHILE ( ! input (mode)) ;
      }
   }
}

/***************************************************************/


