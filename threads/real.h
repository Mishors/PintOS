#ifndef THREADS_REAL_H
#define THREADS_REAL_H

typedef struct
  {
    int real;
                 
  }real;

real int_to_real (int n);

int real_to_int(real x);

int real_to_int_round(real x);

real real_add(real x,real y);

real real_sub(real x,real y);

real add_real_int(real x,int n);

real sub_real_int(real x,int n);

real mult_real (real x, real y);

real div_real (real x, real y);

real mult_int_real (real x, int n);

real div_int_real (real x, int n);

#endif
