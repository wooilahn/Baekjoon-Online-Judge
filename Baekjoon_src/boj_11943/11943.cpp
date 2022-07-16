#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
  int A, B, C, D;
  scanf("%d %d", &A, &B);
  scanf("%d %d", &C, &D);
  printf("%d\n", min(A+D, B+C));

  return 0;
}
