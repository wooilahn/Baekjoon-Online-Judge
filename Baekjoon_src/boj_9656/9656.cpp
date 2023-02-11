#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N;
  bool flag = true; // true: SK, false: CY

  scanf("%d", &N);

  while(N){
    if(N == 1)
		break;

    if(N >= 4){
	  flag = !flag;
	  N -= 3;
	}
	else if(N <= 3){
	  flag = !flag;
	  N--;
	}
  }

  if(flag)
    printf("CY\n");
  else
    printf("SK\n");

  return 0;
}
