#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N;
  scanf("%d", &N);

  
  // 2*i-1
  
  for(int i=0; i<N; i++){
    for(int k=0; k<N-1-i; k++)
      printf(" ");
    printf("*");

    for(int k=0; k<2*i-1; k++)
      printf(" ");

    if(i > 0)
      printf("*");
    printf("\n");
  }

  return 0;
}
