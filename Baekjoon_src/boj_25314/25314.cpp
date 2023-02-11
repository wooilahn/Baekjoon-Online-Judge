#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N;
  scanf("%d", &N);

  while(true){
    if(N == 0){
	  printf("int\n");
	  break;
	}

	printf("long ");
	N -= 4;
  }

  return 0;
}
