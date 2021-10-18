const unsigned char MaPhim[4] = { 0x3f, 0x7f, 0xbf, 0xff};
unsigned int8 mpt1=0, mpt2=0;
unsigned int key_nhan()
{
   signed int8 key, hang, cot;
   key = hang = 0xff;
   for(cot=0; cot<4; cot++)
   {
      output_b(MaPhim[cot]);
      if(!input(pin_b2))        { hang=0;   break; }
      else if(!input(pin_b3))   { hang=1;   break; }
      else if(!input(pin_b4))   { hang=2;   break; }
      else if(!input(pin_b5))   { hang=3;   break; }
   }
   if(hang!=0xff)    key = hang*4 + cot;
   return(key);
}

unsigned int key_4x4()
{
   mpt1 = key_nhan();
   if( mpt1 != 0xff)
   {
      delay_ms(20);
      mpt1= key_nhan();
      do{ mpt2= key_nhan();}
      while( mpt2 == mpt1);
   }
   return(mpt1);
   
}
