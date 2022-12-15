#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int w1, h1, w2, h2;
  scanf("%d %d %d %d", &w1, &h1, &w2, &h2);

  if(w1-1 <= w2 || h1-1 <= h2)
    printf("0\n");
  else
    printf("1\n");

  return 0;
}
