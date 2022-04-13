#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N;
  scanf("%d", &N);

  for(int i=1; i<=N; i++){
    for(int k=0; k<N-i; k++)
	  printf(" ");

	for(int k=0; k<i; k++){
	  printf("*");
	  
	  if(k != i-1)
	    printf(" ");
	}
	printf("\n");
  }

  return 0;
}
