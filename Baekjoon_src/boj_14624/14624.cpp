
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N;
  scanf("%d", &N);

  if(N % 2 == 0)
    printf("I LOVE CBNU");
  else {
	for(int i=0; i<N; i++)
	  printf("*");
	printf("\n");

	for(int i=N/2; i>=0; i--){
	  for(int k=0; k<i; k++)
	    printf(" ");
	  printf("*");

	  for(int k=1; k<N-(2*i + 1); k++)
	    printf(" ");

	  if(N != 2*i+1)
	    printf("*");
	  printf("\n");
	}
  }

  return 0;
}
