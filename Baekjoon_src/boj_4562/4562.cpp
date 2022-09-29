#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int T;
  scanf("%d", &T);

  while(T--){
    int X, Y;
	scanf("%d %d", &X, &Y);

	if(X >= Y)
	  printf("MMM BRAINS\n");
	else
	  printf("NO BRAINS\n");
  }

  return 0;
}
