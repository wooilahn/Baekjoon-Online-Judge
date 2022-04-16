#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(){
  int T;
  scanf("%d", &T);

  int N;
  while(T--){
    int num, sum = 0;
    scanf("%d", &N);

	while(N--){
	  scanf("%d", &num);
	  sum += num;
	}

	printf("%d\n", sum);
  }

  return 0;
}
