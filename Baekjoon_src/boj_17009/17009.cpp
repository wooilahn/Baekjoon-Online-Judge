#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int a1, a2, a3, t_a;
  int b1, b2, b3, t_b;

  scanf("%d %d %d", &a1, &a2, &a3);
  scanf("%d %d %d", &b1, &b2, &b3);

  t_a = a1*3 + a2*2 + a3;
  t_b = b1*3 + b2*2 + b3;

  if(t_a > t_b)
    printf("A\n");
  else if(t_a < t_b)
    printf("B\n");
  else
    printf("T\n");

  return 0;
}
