#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int B;
  scanf("%d", &B);

  int P = 5*B-400;
  int flag = 0;

  if(P < 100)
    flag = 1;
  else if(P > 100)
    flag = -1;

  printf("%d\n%d\n", P, flag);

  return 0;
}
