#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N, X, K;
  int A, B;
  scanf("%d %d %d", &N, &X, &K);

  for(int i=0; i<K; i++){
    scanf("%d %d", &A, &B);

	if(A == X)
	  X = B;
	else if(B == X)
	  X = A;
  }

  printf("%d\n", X);

  return 0;
}
