#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int A, B, C, D;
  scanf("%d %d %d\n%d", &A, &B, &C, &D);

  int rA, rB, rC;
  rA = D/3600;
  rB = (D - 3600*rA) / 60;
  rC = (D - 3600*rA - 60*rB);

  C = C+rC;
  B = B+rB+(C/60);
  A = A+rA+(B/60);

  C = C%60;
  B = B%60;
  A = A%24;

  printf("%d %d %d\n", A, B, C);

  return 0;
}
