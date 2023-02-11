#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int ur, tr, uo, to;
  scanf("%d %d %d %d", &ur, &tr, &uo, &to);
  printf("%d\n", ur*56 + 24*tr + 14*uo + 6*to);

  return 0;
}
