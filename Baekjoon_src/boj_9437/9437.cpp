#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N, P;
  
  while(true){
    scanf("%d", &N);

	if(N == 0)
	  break;

	scanf("%d", &P);

	if(P <= N/2){
	  if(P % 2 == 0) // 짝수
	    printf("%d %d %d\n", P-1, N-P+1, N-P+2);
	  else if(P % 2 == 1) // 홀수
	    printf("%d %d %d\n", P+1, N-P, N-P+1);
	}
	else if(P > N/2){
	  if(P % 2 == 0){ // 짝수
	    printf("%d %d %d\n", N-P+1, N-P+2, P-1);
	  }
	  else if(P % 2 == 1){ // 홀수
	    printf("%d %d %d\n", N-P, N-P+1, P+1);
	  }
	}
  }

  return 0;
}
