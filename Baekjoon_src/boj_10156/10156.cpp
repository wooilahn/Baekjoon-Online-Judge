#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int max(int A, int B){
  return A > B ? A : B;
}

int main(){
  int K, N, M;

  scanf("%d %d %d", &K, &N, &M);
  printf("%d\n", max(K*N-M, 0));

  return 0;
}
