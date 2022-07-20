#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int K;
  scanf("%d", &K);

  int prev_A = 1;
  int prev_B = 0;

  int next_A = 0;
  int next_B = 0;

  for(int i=1; i<=K; i++){
    next_A = prev_B;
	next_B = prev_A + prev_B;

	prev_A = next_A;
	prev_B = next_B;
  }

  printf("%d %d\n", next_A, next_B);

  return 0;
}
