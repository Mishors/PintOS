#ifndef THREADS_REAL_H
#define THREADS_REAL_H

#define F 16384

#define INT_TO_REAL(n) (n) * (F)
#define REAL_TO_INT(x) (x) / (F)
#define REAL_TO_INT_ROUND(x) ((x) >= 0 ? ((x) + (F) / 2) / (F) : ((x) - (F) / 2) / (F))
#define REAL_ADD(x ,y) (x) + (y)
#define REAL_SUB(x ,y) (x) - (y)
#define REAL_ADD_INT(x , n) (x) + (n) * (F)
#define REAL_SUB_INT(x , n) (x) - (n) * (F)
#define REAL_MULT(x , y) ((int64_t)(x)) * (y) / (F)
#define REAL_DIV(x , y) ((int64_t)(x)) * (F) / (y)
#define REAL_MULT_INT(x , n) (x) * (n)
#define REAL_DIV_INT(x , n) (x) / (n)

#endif
