#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int T, S;
  scanf("%d %d", &T, &S);

  if(!(T >= 12 && T <= 16) || S == 1){
    printf("280\n");
  }
  else
    printf("320\n");

  return 0;
}
