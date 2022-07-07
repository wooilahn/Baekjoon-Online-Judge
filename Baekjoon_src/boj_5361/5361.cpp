#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int T;
  double A, B, C, D, E;

  scanf("%d", &T);

  while(T--){
    scanf("%lf %lf %lf %lf %lf", &A, &B, &C, &D, &E);
    printf("$%.2lf\n", A*350.34 + B*230.90 + C*190.55 + D*125.30 + E*180.90);
  }

  return 0;
}
