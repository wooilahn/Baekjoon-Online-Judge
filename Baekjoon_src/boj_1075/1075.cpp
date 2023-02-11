#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N, F;
  scanf("%d %d", &N, &F);

  int q = N % 100;
  int ans = 0;

  for(int i=0; i<=99; i++){
    int t = N-q+i;

	if(t % F == 0){
	  ans = i;
	  break;
	}
  }

  printf("%02d\n", ans);

  return 0;
}
