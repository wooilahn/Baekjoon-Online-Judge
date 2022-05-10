#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N;
  scanf("%d", &N);

  for(int i=1; i<=N; i++){
    if(i==N){
	  for(int k=1; k<=2*i-1; k++)
	    printf("*");
	}
	else if(i == 1){
	  for(int k=0; k<N-i; k++)
	    printf(" ");
	  printf("*");
	}
	else {
	  for(int k=0; k<N-i; k++)
	    printf(" ");
	  printf("*");
	  for(int k=0; k<(i-1)*2-1; k++)
	    printf(" ");
	  printf("*");
	}
	printf("\n");
  }

  return 0;
}
