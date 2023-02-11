#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
  int N;
  scanf("%d", &N);

  double ans = 0;

  for(int i=0; i<5; i++){
   double t = (double)(N%10);
   N /= 10;

   ans += powf(t, 5);
  }

  printf("%d\n", (int)ans);

  return 0;
}
