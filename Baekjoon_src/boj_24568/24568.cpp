#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int R, S;
  scanf("%d %d", &R, &S);

  int sum = R*8 + S*3;

  printf("%d\n", sum-28);

  return 0;
}
