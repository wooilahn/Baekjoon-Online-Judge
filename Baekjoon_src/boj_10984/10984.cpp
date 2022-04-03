#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int T;
  scanf("%d", &T);

  int N;

  while(T--){
   scanf("%d", &N);

   int C;
   double G;
   int t_C = 0;
   double t_G = 0;

   for(int i=0; i<N; i++){
     scanf("%d %lf", &C, &G);
	 
	 t_C += C;
	 t_G += (G*C);
   }

   printf("%d %.1lf\n", t_C, t_G/(double)t_C);
  }

  return 0;
}
