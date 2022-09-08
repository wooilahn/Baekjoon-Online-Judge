#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N;
  scanf("%d", &N);

  int cnt = 0;

  while(true){
    if(N <= 0)
	  break;

	for(int i=1; i<=N; i++){
	  if(i > N)
	    break;
	  else if(i <= N){
	    N -= i;
	    cnt++;
	  }
	}
  }

  printf("%d\n", cnt);

  return 0;
}
