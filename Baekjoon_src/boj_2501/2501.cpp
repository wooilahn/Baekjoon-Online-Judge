#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N, K;
  int cnt = 0;
  scanf("%d %d", &N, &K);

  for(int i=1; i<=N; i++){
    if(N%i == 0){
	  cnt++;

	  if(cnt == K){
	    printf("%d\n", i);
		return  0;
	  }
	}
  }

  printf("0\n");
  return 0;
}
