#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int yy, mm;
  scanf("%d %d", &yy, &mm);
  printf("%d\n", mm + (mm-yy));

  return 0;
}
