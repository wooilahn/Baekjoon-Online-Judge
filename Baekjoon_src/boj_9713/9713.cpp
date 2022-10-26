#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int T, N;
  int sum = 0;

  scanf("%d", &T);

  while(T--){
	scanf("%d", &N);
	sum = ((N / 2) + 1)*(1 + N) / 2;
	printf("%d\n", sum);
  }

  return 0;
}
