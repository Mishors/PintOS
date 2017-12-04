#include "real.h"

#define F 2^14 

real int_to_real (int n)
{ 
  real ret ;  
  ret.real = n*F;
  return ret;
}

int real_to_int(real x)
{
  return x.real/F;
}

int real_to_int_round(real x)
{
 if(x.real >= 0) 
  {
   (x.real + F / 2) / F;  
  }else{
   (x.real - F / 2) / F;
  }
}

real real_add(real x,real y)
{
  real ret ; 
  
  ret.real = x.real + y.real;
  return ret.real; 
}

real real_sub(real x,real y)
{
  real ret ; 
  
  ret.real = x.real - y.real;
  return ret.real; 
}

real add_real_int(real x,int n)
{
  real ret ; 
  
  ret.real = x.real + n*F;
  return ret.real; 
}

real sub_real_int(real x,int n)
{
  real ret ; 
  
  ret.real = x.real - n*F;
  return ret.real; 
}


real mult_real (real x, real y)
{
   real ret;
   ret.real = x.real * y.real;
   ret.real /= F;
   return ret;
}

real div_real (real x, real y)
{
   real ret;
   ret.real =(x.real * F) / y.real;
   return ret;
}

real mult_int_real (real x, int n)
{
   real ret;
   ret.real = n * x.real;
   return ret;
}

real div_int_real (real x, int n)
{
   real ret;
   ret.real =  x.real/n;
   return ret;
}














