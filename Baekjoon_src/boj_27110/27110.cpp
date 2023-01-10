#define MIN(A,B) A > B ? B : A
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N;
  scanf("%d", &N);
  
  int A, B, C;
  scanf("%d %d %d", &A, &B, &C);

  int sum = 0;
  sum += MIN(A, N);
  sum += MIN(B, N);
  sum += MIN(C, N);

  printf("%d\n", sum);

  return 0;

}
