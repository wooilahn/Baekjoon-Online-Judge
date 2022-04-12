#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N;
  scanf("%d", &N);

  for(int i=1; i<=N; i++){
   if(i%2 == 1){
     for(int k=0; k<N; k++){
	   printf("*");
	   
	   if(k != N-1)
	     printf(" ");
	 }
	 printf("\n");
   }
   else if(i%2 == 0){
     for(int k=0; k<N; k++){
	   printf(" *");
	 }
	 printf("\n");
   }
  }

  return 0;
}
