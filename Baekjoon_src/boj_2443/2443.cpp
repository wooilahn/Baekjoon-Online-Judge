#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N;
  scanf("%d", &N);

  int k=0;

  for(int i=N; i>=1; i--){
    
	for(int j=0; j<k; j++)
	 printf(" ");

    for(int j=0; j<2*i-1; j++){
	  printf("*");
	}
	printf("\n");
	k++;
  }

  return 0;
}
