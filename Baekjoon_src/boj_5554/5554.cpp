#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);

  int sum = a+b+c+d;
  printf("%d\n%d\n", sum/60, sum%60);

  return 0;
}
