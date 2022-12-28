#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
  int N, M;
  scanf("%d %d", &N, &M);
  printf("%d\n", min(N/2, M/2));

  return 0;
}
