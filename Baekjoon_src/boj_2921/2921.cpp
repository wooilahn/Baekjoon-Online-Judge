#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int N, ans = 0;
  scanf("%d", &N);

  for(int i=0; i<=N; i++){
    for(int j=i; j<=N; j++){
	  ans += i+j;
	}
  }

  printf("%d\n", ans);

  return 0;
}
