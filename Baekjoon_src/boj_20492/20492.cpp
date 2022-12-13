#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N;
  scanf("%d", &N);

  int cost1 = N * 0.78;
  int cost2 = (N*0.8) + (N*0.2*0.78);

  printf("%d %d\n", cost1, cost2);

  return 0;
}
