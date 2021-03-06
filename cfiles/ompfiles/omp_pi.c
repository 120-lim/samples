#include<stdio.h>
#include<time.h>
#include<omp.h>
#define num_steps 1000000000

int main(void){
    double /*clock_t*/ t1, t2;
 t1 =(double) time(NULL);
 int i;
 double x,pi,sum=0.0,step;
 step = 1.0 / (double) num_steps;
 
#pragma omp parallel for reduction(+:sum) private(x)
/* private は2重ループで使える*/

 for(i = 1;i <= num_steps; i++){
 x = (i - 0.5) * step;
 sum = sum + 4.0 / (1.0 + x * x);
 }

 pi = step * sum;
 printf("%f\n",pi);

 t2 = (double) time(NULL);
    printf("%f\n", (double)(t2 - t1));
 return(0);
}
