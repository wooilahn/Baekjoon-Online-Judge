#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N;
  scanf("%d", &N);

  for(int i=N-1; i>=0; i--){
    for(int k=0; k<i; k++)
	  printf(" ");
	for(int k=0; k<N-i; k++)
	  printf("*");
	printf("\n");
  }

  for(int i=1; i<=N-1; i++){
    for(int k=0; k<i; k++)
	  printf(" ");
	for(int k=0; k<N-i; k++)
	  printf("*");
	printf("\n");
  }

  return 0;
}
