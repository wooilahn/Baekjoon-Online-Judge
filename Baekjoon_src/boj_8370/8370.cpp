#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int n1, k1, n2, k2;
  scanf("%d %d %d %d", &n1, &k1, &n2, &k2);

  printf("%d\n", n1*k1 + n2*k2);

  return 0;
}
