#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
  int T;
  scanf("%d", &T);

  double A, B;
  while(T--){
    scanf("%lf %lf", &A, &B);
    printf("%.0lf\n", (A*A/2) / (B*B/2));
  }

  return 0;
}
