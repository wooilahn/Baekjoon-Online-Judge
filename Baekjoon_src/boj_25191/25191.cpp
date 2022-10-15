
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){

  int N;
  int A, B;
  
  scanf("%d", &N);
  scanf("%d %d", &A, &B);
  printf("%d\n", min(N, A/2 + B));

  return 0;
}
