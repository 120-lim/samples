#include<stdio.h>
#include<math.h>
double main(){
  int j;
  printf("べき数を入力" );
  scanf("%d" , &j);
  double k = pow(2.0,j);
  printf("%lf\n", k);
  return 0;
}
