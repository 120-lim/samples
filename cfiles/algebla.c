#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix_util.h"

int main(){
  int a[3][4][3][4];
  int i,j,k,l;
  for(i=0;i<=2;++i){
    for(j=0;j<=3;++j){
      for(k=0;k<=2;++k){
	for(l=0;l<=3;++l){
	  a[i][j][k][l] = 0;
	}
      }
    }
  }
  a[0][0][0][0] = 1;
  a[0][1][0][1] = 1;
  a[0][2][0][2] = 1;
  a[0][3][0][3] = 1;
  a[1][0][1][0] = 1;
  a[1][1][1][1] = 1;
  a[1][2][1][2] = 1;
  a[1][3][1][3] = 1;
  a[2][0][2][0] = 1;
  a[2][1][2][1] = 1;
  a[2][2][2][2] = 1;
  a[2][3][2][3] = 1;
  int b[3][4][3][4];
  for(i=0;i<=2;++i){
    for(j=0;j<=3;++j){
      b[0][0][i][j] = a[0][0][i][j] + a[1][0][i][j] + a[0][1][i][j];
    }
  }
  for(i=0;i<=2;++i){
    for(j=0;j<=3;++j){
      b[1][0][i][j] = a[0][0][i][j]+a[1][0][i][j]+a[1][1][i][j]+a[2][0][i][j];
    }
  }
  for(i=0;i<=2;++i){
    for(j=0;j<=3;++j){
      b[2][0][i][j] = a[1][0][i][j]+a[2][0][i][j]+a[2][1][i][j];
    }
  }
  
  for(i=0;i<=2;++i){
    for(j=0;j<=3;++j){
      b[0][1][i][j] = a[0][0][i][j]+a[0][1][i][j]+a[1][1][i][j]+a[0][2][i][j];
    }
  }
  for(i=0;i<=2;++i){
    for(j=0;j<=3;++j){
      b[1][1][i][j] = a[1][0][i][j]+a[0][1][i][j]+a[1][1][i][j]+a[2][1][i][j]+a[1][2][i][j];
    }
  }
  for(i=0;i<=2;++i){
    for(j=0;j<=3;++j){
      b[2][1][i][j] = a[2][2][i][j]+a[2][0][i][j]+a[1][1][i][j]+a[2][1][i][j];
    }
  }
  for(i=0;i<=2;++i){
    for(j=0;j<=3;++j){
      b[0][2][i][j] = a[0][1][i][j]+a[0][3][i][j]+a[0][2][i][j]+a[1][2][i][j];
    }
  }
  for(i=0;i<=2;++i){
    for(j=0;j<=3;++j){
      b[1][2][i][j] = a[0][2][i][j]+a[1][2][i][j]+a[2][2][i][j]+a[1][1][i][j]+a[1][3][i][j];
    }
  }
  for(i=0;i<=2;++i){
    for(j=0;j<=3;++j){
      b[2][2][i][j] = a[1][2][i][j]+a[2][2][i][j]+a[2][1][i][j]+a[2][3][i][j];
    }
  }
  for(i=0;i<=2;++i){
    for(j=0;j<=3;++j){
      b[0][3][i][j] = a[0][2][i][j]+a[0][3][i][j]+a[1][3][i][j];
    }
  }
  for(i=0;i<=2;++i){
    for(j=0;j<=3;++j){
      b[1][3][i][j] = a[0][3][i][j]+a[1][3][i][j]+a[2][3][i][j]+a[1][2][i][j];
    }
  }
  for(i=0;i<=2;++i){
    for(j=0;j<=3;++j){
      b[2][3][i][j] = a[1][3][i][j]+a[2][3][i][j]+a[2][2][i][j];
    }
  }
  int n;
  int x;
  int c[3][4];
  double **d;
  d = alloc_dmatrix(3,4);
  printf("Input initial state A\n");
  for(i = 0; i < 3; ++i){
    for(j = 0; j< 4; ++j){
      printf("a[%d][%d] = ", i+1, j+1);
      scanf("%d", &c[i][j]);
      if (c[i][j] != 0 && c[i][j] != 1) {
    fprintf(stderr, "Input 0 or 1\n");
    exit(1);
  }
    }
  }
  
  
  int e[3][4];
  int g[3][4];
  printf("Input final state B\n");
  for(i = 0; i < 3; ++i){
    for(j = 0; j < 4; ++j){
      printf("b[%d][%d] = ", i+1, j+1);
      scanf("%d", &g[i][j]);
        if (g[i][j] != 0 && g[i][j] != 1) {
    fprintf(stderr, "Input 0 or 1\n");
    exit(1);
  }
    }
  }
      
  for(i = 0; i < 3; ++i){
    for(j = 0; j < 4; ++j){
      d[i][j] = c[i][j];
    }
  }
    printf("Iinitial state:\n");
    fprint_dmatrix(stdout, 3, 4, d);
    
    srand(10);
    for(k=0;k<10000000;++k){
      x = rand(); 
      for(i=0;i<=2;++i){
      for(j=0;j<=3;++j){
	c[i][j] = (c[i][j]+b[x%3][x%4][i][j])%2;
      }
      }
      e[x%3][x%4] = e[x%3][x%4] + 1;
      if(c[0][0] == g[0][0] && c[1][0] == g[1][0] && c[2][0] == g[2][0] && c[0][1] == g[0][1] && c[1][1] == g[1][1] && c[2][1] == g[2][1] && c[0][2] == g[0][2] && c[1][2] == g[1][2] && c[2][2] == g[2][2] && c[0][3] == g[0][3] && c[1][3] == g[1][3] && c[2][3] == g[2][3]){
	break;
      }
    }
    for(i=0;i<=2;++i){
      for(j=0;j<=3;++j){
	d[i][j] = c[i][j];
      }
    }
    double **f;
    f =  alloc_dmatrix(3,4);
    for(i=0;i<=2;++i){
      for(j=0;j<=3;++j){
	f[i][j] = e[i][j]%2;
      }
    }
    printf("Final state:\n");
    fprint_dmatrix(stdout, 3, 4, d);
    printf("Buttons switched on :\n");
  fprint_dmatrix(stdout, 3, 4, f);
  free_dmatrix(d);
  free_dmatrix(f);
  return 0;
}

